/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: viferrei <viferrei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/29 17:44:32 by arbernar          #+#    #+#             */
/*   Updated: 2021/09/30 12:19:06 by viferrei         ###   ########.fr       */
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
	char		*line;
	static char	*s_buff;
	char		*buffer;

	line = ft_strdup("");
	if (!s_buff)
		s_buff = ft_strdup("");
	buffer = (char *) malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buffer)
		return (NULL);

	ssize_t		bytes_read;
	char		*temp;

	bytes_read = 1;
	while (!(ft_strchr(buffer, '\n')) && !(ft_strchr(s_buff,  '\n'))
			&& bytes_read)
	{
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		buffer[bytes_read] = '\0';
		temp = line;
		line = ft_strjoin(line, buffer);
		free_ptr(temp);
	}

	line = get_line(&line, &s_buff);

	printf("s_buff:%s\n\n", s_buff);
	printf("line é:>>%s<<\n\n", line);

	return(line);
}

/*
ssize_t	read_file(int fd, char **buffer, char **line)
{
	ssize_t		bytes_read;
	char		*temp;

	bytes_read = 1;
	while (!(ft_strchr(*buffer, '\n')) && bytes_read)
	{
		bytes_read = read(fd, *buffer, BUFFER_SIZE);
		*buffer[bytes_read] = '\0';
		temp = *line;
		*line = ft_strjoin(*line, *buffer);
		free_ptr(temp);
	}
	return(bytes_read);
}*/

char	*get_line(char **line, char **s_buff)
{
	char	*line_temp;
	char	*buff_temp;
	int		line_nl;
	int		buff_nl;

	line_nl = 0;
	buff_nl = 0;
	while((*line)[line_nl] != '\n')
		line_nl++;
	while((*s_buff)[buff_nl] != '\n')
		buff_nl++;
	line_temp = *line;
	buff_temp = *s_buff;
	/*if (ft_strchr(*s_buff, '\n'))
	{
		*line = ft_substr(*s_buff, 0, buff_nl + 1);
		*s_buff = ft_strdup((*s_buff) + buff_nl + 1);
	}*/
	//else
	//{
		*line = ft_strjoin(*s_buff, ft_substr(*line, 0, (line_nl + 1)));
		*s_buff = ft_strdup(line_temp + line_nl + 1);
	//}

	printf("\nline_temp é:%s\n\n", line_temp);

	free_ptr(line_temp);
	free_ptr(buff_temp);
	return (*line);
};
