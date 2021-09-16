/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: viferrei <viferrei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/13 16:41:04 by viferrei          #+#    #+#             */
/*   Updated: 2021/09/16 17:26:34 by viferrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char	*s_buff = NULL;
	char		*buffer;
	//char		*line;

	buffer = (char *) malloc(BUFFER_SIZE + 1);
	if (BUFFER_SIZE <= 0 || !buffer)
		return (NULL);
	if (!s_buff)
		s_buff = ft_strdup("");

	return (find_nl(fd, s_buff, buffer));
}

char	*find_nl(int fd, char *s_buff, char *buffer)
{
	char	*temp;
	int		eof;
	int		index;

	eof = 1;
	index = 0;
	while(buffer[index - 1] != '\n' && eof)
	{
		eof = read(fd, &buffer[index++], BUFFER_SIZE);
		temp = s_buff;
		s_buff = ft_strjoin(temp, buffer);
		free(temp);
	}
	return (s_buff);
}
