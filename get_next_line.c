/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: viferrei <viferrei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/13 16:41:04 by viferrei          #+#    #+#             */
/*   Updated: 2021/09/20 11:39:21 by viferrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char	*excess = NULL;
	char		*buffer;
	char		*line;
	int			n;

	buffer = (char *) malloc(BUFFER_SIZE + 1);
	if (BUFFER_SIZE <= 0 || !buffer)
		return (NULL);
	if (!excess)
		excess = ft_strdup("");

	while (find_nl(&buffer, &excess, &line))
	{
		n = read(fd, buffer, BUFFER_SIZE);
		buffer[n] = '\0';
	}
	return (line);
}

int	find_nl(char **buffer, char **excess, char **line)
{
	int		index;

	while (*buffer[index] != 0)
	{
		if (*buffer[index] == '\n')
		{
			line = ft_strljoin(excess, buffer, index);
			free(excess);
		}
		index++;
	}
	excess = ft_strljoin(excess, buffer, index);
	free(buffer);
	if (line)
		return(0);
	return(1);
}

/*
char	*....(int fd, char *excess, char *buffer)
{
	char	*temp;
	int		eof;
	int		index;

	eof = 1;
	index = 0;
	while(buffer[index - 1] != '\n' && eof)
	{
		eof = read(fd, &buffer[index++], BUFFER_SIZE);
		temp = excess;
		excess = ft_strjoin(temp, buffer);
		free(temp);
	}
	return (excess);
}
*/
