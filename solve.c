/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrizkiou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/19 23:45:01 by mmatrouf          #+#    #+#             */
/*   Updated: 2019/07/21 02:44:20 by hrizkiou         ###   ########.fr       */
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
	while (i < r &&  res <= nb)
	{
		i++;
		res = i * i;
	}
	return (i);
}
int ft_solve(t_file *h, int size, int n)
{
	int w;
	int x;
	//printf("%d miw\n",n);
	if (n ==  h->count)
		return (1);
	w = -1;
	while (++w < size)
	{
		x = -1;
		while (++x < size)
		{
			if (ft_add_tet(&*h, h->count, size, w, x))
			{
				if (ft_solve(h, size, n + 1))
					return (1);
				else
					ft_del_tet(&*h, h->count, size);
			}
		}
	}
	return (0);
}
