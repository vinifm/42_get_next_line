/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: viferrei <viferrei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/29 17:44:32 by arbernar          #+#    #+#             */
/*   Updated: 2021/09/29 20:57:39 by viferrei         ###   ########.fr       */
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

static char *get_line(char **s_buff)
{
	char	*new_buff;
	char	*temp;
	int		i;

	i = 0;
	while((*s_buff)[i] != '\n')
		i++;
	temp = *s_buff;
	new_buff = ft_substr(*s_buff, 0, (i + 1));
	*s_buff = ft_strdup(*s_buff + i + 1);

	printf("s_buff é:>>%s<<\n\n", *s_buff);


	printf("new_buff é:>>%s<<\n\n", new_buff);


	printf("temp é:%s\n\n", temp);

	free_ptr(temp);
	return (new_buff);
};

char	*get_next_line(int fd)
{
	char		*buffer;
	ssize_t		n_bytes;
	char		*line;
	char		*temp;
	static char	*s_buff;

	buffer = (char *) malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buffer)
		return (NULL);
	if (!s_buff)
		s_buff = ft_strdup("");
	n_bytes = 1;
	while (!(ft_strchr(buffer, '\n')))
	{
		n_bytes = read(fd, buffer, BUFFER_SIZE);
		buffer[n_bytes] = '\0';
		temp = s_buff;
		s_buff = ft_strjoin(s_buff, buffer);
		free_ptr(temp);
	}

	line = get_line(&s_buff);
	printf("s_buff:%s\n\n", s_buff);

	return(line);
}
