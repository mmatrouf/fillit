/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmatrouf <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/14 15:50:31 by mmatrouf          #+#    #+#             */
/*   Updated: 2019/07/23 16:50:48 by mmatrouf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	ft_map_new(t_file *t)
{
	int i;
	int j;

	i = -1;
	if (!(t->map = (char **)malloc(sizeof(char *) * (t->size + 1))))
		return ;
	while (++i < t->size)
	{
		if (!(t->map[i] = (char *)malloc(sizeof(char) * (t->size + 1))))
			return ;
		j = -1;
		while (++j < t->size)
		{
			t->map[i][j] = '.';
		}
		t->map[i][j] = '\0';
	}
	t->map[i] = 0;
}

int		ft_add_tet(t_file *t, int i, int x, int y)
{
	int z;

	z = 0;
	while (z < 4)
	{
		if ((x + t->file[i].x[z]) >= t->size || (y + t->file[i].y[z])
				>= t->size)
			return (0);
		else if (t->map[x + t->file[i].x[z]][y + t->file[i].y[z]] != '.')
			return (0);
		z++;
	}
	z = 0;
	while (z < 4)
	{
		t->map[x + t->file[i].x[z]][y + t->file[i].y[z]] = t->file[i].a;
		z++;
	}
	return (1);
}

void	ft_del_tet(t_file *t, int i, int x, int y)
{
	int z;

	z = -1;
	while (++z < 4)
		t->map[x + t->file[i].x[z]][y + t->file[i].y[z]] = '.';
}
