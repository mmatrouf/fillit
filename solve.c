/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrizkiou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/19 23:45:01 by mmatrouf          #+#    #+#             */
/*   Updated: 2019/07/23 00:23:13 by mmatrouf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

/*initialiase cor of tetrimonos*/
void	ft_upperleft(t_file *h)
{
	int x;
	int y;
	int i;
	int j;

	i = -1;
	while (++i < h->count)
	{
		j = -1;
		x = 3;
		y = 3;
		while (++j < 4)
		{
			if(h->file[i].x[j] < x)
				x = h->file[i].x[j];
			if (h->file[i].y[j] < y)
				y = h->file[i].y[j];
		}
		j = -1;
		while (++j < 4)
		{
			h->file[i].x[j] = h->file[i].x[j] - x; 
			h->file[i].y[j] = h->file[i].y[j] - y;
		}
	}
}

/*Calcule la racine pour obtenir le size de la map*/
int ft_map_size(t_file h)
{
	int r;
	int res;
	int i;
	int nb;

	nb = h.count * 4;
	i = 0;
	r = nb / 2;
	res = 0;
	while (i < r &&  res < nb)
	{
		i++;
		res = i * i;
	}
	return (i);
}
int ft_solve(t_file *h, int size, int n)
{
	int x;
	int y;
	int a;

	a = -1;
	if (n ==  h->count)
		return (1);
	x = -1;
	while (++x < size)
	{
		y = -1;
		while (++y < size)
		{
			if (ft_add_tet(h, n, size, x, y))
			{	
				if ((a = ft_solve(h, size, n + 1)))
				{
					return (1);
				}
				else
				{
					ft_del_tet(h, n, x, y);
				}
			}
		}
	}
	return (0);
}

void	ft_clean_map(t_file *h, int size)
{
	int x;

	x = -1;
	while (++x < size)
	{
		free(h->map[x]);
	}
	free(h->map[x]);
}
