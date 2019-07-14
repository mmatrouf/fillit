/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmatrouf <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/14 15:50:31 by mmatrouf          #+#    #+#             */
/*   Updated: 2019/07/14 18:01:43 by mmatrouf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include <stdio.h>

char **ft_map_new(int size)
{
	char **map;
	int i;
	int j;

	i = -1;
	if (!(map = (char **)malloc(sizeof(char *) * (size + 1))))
		return (0);
	while (++i < size)
	{
		if (!(map[i] = (char *)malloc(sizeof(char) * (size + 1))))
			return (0);
		j = -1;
		while (++j < size)
		{
			map[i][j] = '.';
		}
		map[i][j] = '\0';
	}
	map[i] = 0;
	return (map);
}

char 	**ft_add_tet(char **map, t_tetrisa h, int size)
{
	int x;
	int y;
	int c;

	c = 0;
	x = -1;
	while (++x < size)
	{
		y = -1;
		while (++y < size)
			if (map[x][y] == '.' && c < 4)
			{
				map[h.x[c]][h.y[c]] = h.a;
				c++;
			}
	}
	return (map);
}
