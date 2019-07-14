/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmatrouf <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/23 19:12:44 by mmatrouf          #+#    #+#             */
/*   Updated: 2019/07/14 18:01:02 by mmatrouf         ###   ########.fr       */
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
	char **map;
	map = ft_map_new(4);
	ac++;
	t_file h;
	i = -1;

	fd = open(av[1], O_RDONLY);
	a = ft_stock(fd, &h);
	printf("%d\n coordoner avant le deplacement\n", h.count);

	while (++i < h.count)
	{
		j = -1;
		while (++j < 4)
			printf("(%d,%d)%c\n", h.file[i].x[j], h.file[i].y[j], h.file[i].a);
	}
	ft_upperleft(&h);
	map = ft_add_tet(map, h.file[1], 4);
	i = -1;
	while (++i < 4)
	{
		printf("%s\n", map[i]);	
	}
/*	while (++i < h.count)
	{
		j = 0;
		while (j < 4)		
		{
			printf("%s\n", h.file[i].tetri[j]);
			j++;
		}
		printf("\n");
	}
*/	i = -1;
	printf("coordonner apres le deplacement\n");
	while (++i < h.count)
	{
		j = -1;
		while (++j < 4)
			printf("(%d,%d)\n", h.file[i].x[j], h.file[i].y[j]);
	}
	if (a == 0)
		printf("//this is not a valid file//\n");
	else 
		printf("this file is valid");
	return (0);
}
