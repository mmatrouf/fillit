/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmatrouf <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/23 19:12:44 by mmatrouf          #+#    #+#             */
/*   Updated: 2019/06/30 21:18:30 by mmatrouf         ###   ########.fr       */
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
	while (i < 26)
	{
		j = 0;
		while(h.file->tetri[j])
		{
			printf("%s", h.file->tetri[j]);
			j++;
		}
		i++;
	}
	
	/*while ((a = ft_test(fd, &h)) > 0 && (a = ft_count(h)) && (b = ft_form(h)))
	{	
		i = 0;
		while (i < 4)
		{
		printf("%s\n", h.tetri[i]);
		i++;
		}
	}*/
//	printf("\na = %d||b = %d\n", a, b);
	return (0);
}
