/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: viferrei <viferrei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/13 16:11:46 by viferrei          #+#    #+#             */
/*   Updated: 2021/10/04 16:30:26 by viferrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>

#include "get_next_line.h"

int	main(void)
{
	int		fd;
	int		n;
	int		index;

	fd = open ("text.txt", O_RDONLY);
	//fd = open ("empty", O_RDONLY);
	index = 1;
	n = 3;
	while (n)
	{
		printf("%d >>%s<<", index, get_next_line(fd));
		n--;
		index++;
	}
	return (0);
}
