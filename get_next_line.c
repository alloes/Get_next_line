/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alopes-n <alopes-n@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/19 19:35:37 by alopes-n          #+#    #+#             */
/*   Updated: 2022/07/26 00:08:06 by alopes-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*ft_substr(char *s, unsigned int start, size_t len)
{
	size_t	index;
	size_t	s_len;
	char	*sub;

	s_len = ft_strlen(s);
	if (start >= s_len)
		return (ft_strdup(""));
	if (s_len - start < len)
		len = s_len - start;
	sub = malloc(len + 1);
	if (!sub)
		return (NULL);
	index = 0;
	while (s[start + index] && index < len)
	{
		sub[index] = s[start + index];
		index++;
	}
	sub[len] = '\0';
	return (sub);
}

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
	static char	*backup = NULL;
	char		*line;
	char		*temp;

	if (fd < 0 || fd > 1024 || BUFFER_SIZE <= 0)
		return (NULL);
	backup = ft_read_line(fd, backup);
	if (!backup)
	{
		return (NULL);
	}
	else if (!*backup)
	{
		free(backup);
		backup = NULL;
		return (NULL);
	}
	line = extract_line(backup);
	temp = backup;
	backup = ft_substr(backup, ft_strlen(line), ft_strlen(backup));
	free (temp);
	temp = NULL;
	return (line);
}
