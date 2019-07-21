/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmatrouf <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/14 15:50:31 by mmatrouf          #+#    #+#             */
/*   Updated: 2019/07/20 00:54:21 by hrizkiou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include <stdio.h>

/*Cree un map*/
void		ft_map_new(t_file *h, int size)
{
	int i;
	int j;

	i = -1;
	if (!(h->map = (char **)malloc(sizeof(char *) * (size + 1))))
		return ;
	while (++i < size)
	{
		if (!(h->map[i] = (char *)malloc(sizeof(char) * (size + 1))))
			return ;
		j = -1;
		while (++j < size)
		{
			h->map[i][j] = '.';
		}
		h->map[i][j] = '\0';
	}
	h->map[i] = 0;
}
/*Ajout un tetrimos au map*/
int		ft_add_tet(t_file *h, int i, int size, int x, int y)
{
	int z;
    int j;
    int a;
    
	z = -1;
    j = -1;
	while (++z < 4 && ++j < i)
	{
		if (h->file[j].x[z] >= size || h->file[j].y[z] >= size)
			return (0);
		else if (h->map[h->file[j].x[z]][h->file[j].y[z]] != '.')
			return (0);
	}
	z = -1;
	j = -1;
	while (++z < 4 && ++j < i)
	{
	    a = -1;
	    while (++a < 4)
		    h->map[x + h->file[j].x[a]][y + h->file[j].y[a]] = h->file[j].a;
	}
	return (1);
}

void	ft_del_tet(t_file *h, int i,int size)
{
	int x;
	int y;
	int z;

	x = -1;
	z = -1;
	while (++x < size && ++z < i)
	{
		y = -1;
		while (++y < size)
			if (h->map[x][y] == h->file[z].a)
				h->map[x][y] = '.';
	}
}
