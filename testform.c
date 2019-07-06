/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmatrouf <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/23 19:12:44 by mmatrouf          #+#    #+#             */
/*   Updated: 2019/07/06 02:22:56 by mmatrouf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <fcntl.h>
#include "fillit.h"

int main(int ac, char **av)
{
	int fd;
	int i,j;
	int a;
	//int b = 0;

	ac++;
	t_file h;
	i = 0;

	fd = open(av[1], O_RDONLY);
	a = ft_stock(fd, &h);
	printf("%d\n", h.count);

	while (i < h.count)
	{
		j = 0;
		while (j < 4)		
		{
			printf("%s\n", h.file[i].tetri[j]);
			j++;
		}
		printf("%d\n", a);
		i++;
	}
	if (a == 0)
		printf("//this is not a valid file//\n");
	return (0);
}
