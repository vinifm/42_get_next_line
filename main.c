/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: viferrei <viferrei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/13 16:11:46 by viferrei          #+#    #+#             */
/*   Updated: 2021/10/05 17:50:30 by viferrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>

#include "get_next_line.h"

int	main(void)
{
	int		fd[4];
	int		n;
	int		index;

	fd[0] = open ("./tester/files/41_with_nl", O_RDONLY);
	fd[1] = open ("./tester/files/42_with_nl", O_RDONLY);
	fd[2] = open ("./tester/files/43_with_nl", O_RDONLY);
	index = 1;
	n = 3;
	while (n--)
	{
		printf("%d >>%s<<\n", index, get_next_line(fd[0]));
		index++;
	}
	return (0);
}
