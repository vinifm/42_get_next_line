/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: viferrei <viferrei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/13 16:41:09 by viferrei          #+#    #+#             */
/*   Updated: 2021/09/17 17:04:58 by viferrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_H
# define GET_NEXT_H

#include <stdlib.h>
#include <unistd.h>

#ifndef BUFFER_SIZE
# define BUFFER_SIZE 48
#endif

char	*get_next_line(int fd);
char	*find_nl(int fd, char *excess, char *buffer);

/* utils */
char	*ft_strdup(const char *s1);
char	*ft_strchr(const char *str, int c);
size_t	ft_strlen(const char *str);
char	*ft_strjoin(char const *s1, char const *s2);

size_t	ft_strlcpy(char *dest, const char *src, size_t size);

#endif
