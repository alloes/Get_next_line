/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alopes-n <alopes-n@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/26 21:04:26 by alopes-n          #+#    #+#             */
/*   Updated: 2022/07/26 21:06:05 by alopes-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char		*ft_strchr(char *s, int c);
char		*ft_strdup(char *s);
size_t		ft_strlen(char *s);
char		*ft_strjoin(char *s1, char *s2);
char		*ft_substr(char *s, unsigned int start, size_t len);

size_t	ft_strlen(char *s)
{
	size_t	count;

	count = 0;
	while (*s)
	{
		count++;
		s++;
	}
	return (count);
}

char	*ft_strchr(char *s, int c)
{
	int	index;

	index = 0;
	while (s[index] != '\0')
	{
		if (s[index] == (unsigned char)c)
			return ((char *)s + index);
		index++;
	}
	if (s[index] == (unsigned char)c)
		return ((char *)s + index);
	return (NULL);
}

char	*ft_strdup(char *s)
{
	char	*dup;
	size_t	len;
	size_t	index;

	len = ft_strlen(s);
	dup = malloc(len + 1);
	if (!dup)
		return (NULL);
	index = 0;
	while (s[index])
	{
		dup[index] = s[index];
		index++;
	}
	dup[index] = '\0';
	return (dup);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*new_str;
	size_t	len_total;
	size_t	len_s1;
	size_t	len_s2;

	len_s1 = -1;
	len_s2 = 0;
	if (!s1 || !s2)
		return (NULL);
	len_total = (ft_strlen(s1) + ft_strlen(s2)) + 1;
	new_str = malloc (len_total);
	if (!new_str)
		return (NULL);
	while (s1[++len_s1])
		new_str[len_s1] = s1[len_s1];
	while (s2[len_s2])
		new_str[len_s1++] = s2[len_s2++];
	new_str[len_s1] = '\0';
	return (new_str);
}

char	*ft_substr(char *s, unsigned int start, size_t len)
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
