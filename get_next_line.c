/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: viferrei <viferrei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/13 16:41:04 by viferrei          #+#    #+#             */
/*   Updated: 2021/09/27 15:53:45 by viferrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	free_ptr(char *ptr)
{
	if (ptr)
	{
		free(ptr);
		ptr = NULL;
	}
}

char	*get_next_line(int fd)
{
	static char	*s_buff = NULL;
	char		*buffer;
	char		*line;

	buffer = (char *) malloc(BUFFER_SIZE + 1);
	if (BUFFER_SIZE <= 0 || !buffer)
		return (NULL);
	if (!s_buff)
		s_buff = ft_strdup("");

	find_nl(fd, &buffer, &s_buff, &line);
	return (line);
}

ssize_t	find_nl(int fd, char **buffer, char **s_buff, char **line)
{
	ssize_t	n;
	char	*temp;

	n = 1;
	while (!ft_strchr(*buffer, '\n') && n)
	{
		n = read(fd, *buffer, BUFFER_SIZE);
		(*buffer)[n] = '\0';
		temp = *s_buff;
		*s_buff = ft_strjoin(temp, *buffer);
		free_ptr(temp);
	}
	free_ptr(*buffer);
	*s_buff = get_line(s_buff, line);

	return(0);
}

char	*get_line(char **s_buff, char **line)
{
	size_t	index;
	char	*new_buff;

	index = 0;
	new_buff = NULL;
	while ((*s_buff)[index] != '\n' && (*s_buff)[index] != '\0')
		index++;
	if ((*s_buff)[index] == '\n')
	{
		*line = ft_substr(*s_buff, 0, (index + 1));
		new_buff = ft_strdup(s_buff[index + 1]);
	}
	else
		*line = ft_strdup(*s_buff);
	free_ptr(*s_buff);
	return (new_buff);
}
