/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alopes-n <alopes-n@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/27 12:58:09 by alopes-n          #+#    #+#             */
/*   Updated: 2022/07/18 04:55:54 by alopes-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdlib.h>

char		*get_next_line(int fd);
char		*ft_strchr( char *s, int c);
char		*ft_strdup( char *s);
size_t		ft_strlen( char *s);
char		*ft_strjoin(char *s1, char *s2);

#endif