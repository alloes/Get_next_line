/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alopes-n <alopes-n@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/26 21:10:48 by alopes-n          #+#    #+#             */
/*   Updated: 2022/07/26 21:27:30 by alopes-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

static char	*extract_line(char *line)
{
	int		i;
	char	*temp;

	i = 0;
	while (line[i] != '\n' && line[i])
		i++;
	temp = ft_substr(line, 0, i + 1);
	return (temp);
}

static char	*ft_read_line(int fd, char *backup)
{
	char	*temp;
	int		bytes_read;
	char	*buffer;

	buffer = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	bytes_read = 1;
	while (bytes_read > 0)
	{
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_read == -1)
			break ;
		buffer[bytes_read] = '\0';
		if (!backup)
			backup = ft_strdup("");
		temp = backup;
		backup = ft_strjoin(temp, buffer);
		free (temp);
		temp = NULL;
		if (ft_strchr(backup, '\n'))
			break ;
	}
	free(buffer);
	buffer = NULL;
	return (backup);
}

char	*get_next_line(int fd)
{
	static char	*backup[1024];
	char		*line;
	char		*temp;

	if (fd < 0 || fd > 1024 || BUFFER_SIZE <= 0)
		return (NULL);
	backup[fd] = ft_read_line(fd, backup[fd]);
	if (!backup[fd])
	{
		return (NULL);
	}
	else if (!*backup[fd])
	{
		free(backup[fd]);
		backup[fd] = NULL;
		return (NULL);
	}
	line = extract_line(backup[fd]);
	temp = backup[fd];
	backup[fd] = ft_substr(backup[fd], ft_strlen(line), ft_strlen(backup[fd]));
	free (temp);
	temp = NULL;
	return (line);
}
