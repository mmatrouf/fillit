/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmatrouf <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/23 19:12:44 by mmatrouf          #+#    #+#             */
/*   Updated: 2019/06/26 17:49:15 by mmatrouf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <fcntl.h>
#include "fillit.h"

int main(int ac, char **av)
{
	int fd;
	int i;
	int a;

	ac++;
	t_tetrisa h;

	fd = open(av[1], O_RDONLY);
	
	while ((a = ft_test(fd, &h)) > 0 && (a = ft_count(h)) && (a = ft_form(h)))
	{
		printf("\n%d\n", a);
		i = 0;
		while (i < 4)
		{
		printf("%s\n", h.tetri[i]);
		i++;
		}
	}
	printf("\n%d\n", a);
	return (0);
}
