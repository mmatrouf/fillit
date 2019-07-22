/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmatrouf <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/14 15:50:31 by mmatrouf          #+#    #+#             */
/*   Updated: 2019/07/22 21:51:45 by mmatrouf         ###   ########.fr       */
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
    
	z = 0;
	while (z < 4)
	{
		if (( x + h->file[i].x[z]) >= size || (y + h->file[i].y[z]) >= size)
			return (0);
		else if (h->map[x + h->file[i].x[z]][y + h->file[i].y[z]] != '.')
			return (0);
		z++;
	}
	z = 0;
	while (z < 4)
	{
		h->map[x + h->file[i].x[z]][y + h->file[i].y[z]] = h->file[i].a;
		z++;
	}
	return (1);
}

void	ft_del_tet(t_file *h, int i, int x, int y)
{
	int z;

	z = -1;
	while (++z < 4)
		h->map[x + h->file[i].x[z]][y + h->file[i].y[z]] = '.';
}
