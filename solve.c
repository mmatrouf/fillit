/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrizkiou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/19 23:45:01 by mmatrouf          #+#    #+#             */
/*   Updated: 2019/07/23 17:07:42 by mmatrouf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	ft_upperleft(t_file *t)
{
	int x;
	int y;
	int i;
	int j;

	i = -1;
	while (++i < t->count)
	{
		j = -1;
		x = 3;
		y = 3;
		while (++j < 4)
		{
			if (t->file[i].x[j] < x)
				x = t->file[i].x[j];
			if (t->file[i].y[j] < y)
				y = t->file[i].y[j];
		}
		j = -1;
		while (++j < 4)
		{
			t->file[i].x[j] = t->file[i].x[j] - x;
			t->file[i].y[j] = t->file[i].y[j] - y;
		}
	}
}

void	ft_map_size(t_file *t)
{
	int r;
	int res;
	int i;
	int nb;

	nb = t->count * 4;
	i = 0;
	r = nb / 2;
	res = 0;
	while (i < r && res < nb)
	{
		i++;
		res = i * i;
	}
	t->size = i;
}

int		ft_solve(t_file *t, int n)
{
	int x;
	int y;
	int a;

	a = -1;
	if (n == t->count)
		return (1);
	x = -1;
	while (++x < t->size)
	{
		y = -1;
		while (++y < t->size)
			if (ft_add_tet(t, n, x, y))
			{
				if ((a = ft_solve(t, n + 1)))
					return (1);
				else
					ft_del_tet(t, n, x, y);
			}
	}
	return (0);
}

void	ft_clean_map(t_file *t)
{
	int x;

	x = -1;
	while (++x < t->size)
	{
		free(t->map[x]);
	}
	free(t->map);
}
