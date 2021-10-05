/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: viferrei <viferrei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/13 16:11:46 by viferrei          #+#    #+#             */
/*   Updated: 2021/10/05 16:22:23 by viferrei         ###   ########.fr       */
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
	int		fd1;
	int		n;
	int		index;

	fd = open ("./tester/files/41_no_nl", O_RDONLY);
	fd1 = open ("./files/text.txt", O_RDONLY);
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
