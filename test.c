/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmatrouf <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/22 16:32:07 by mmatrouf          #+#    #+#             */
/*   Updated: 2019/07/06 02:22:53 by mmatrouf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "fillit.h"
#include <stdio.h>


int		ft_test(int fd, t_tetrisa *t)
{
	char	buffer[22];
	int 	rd;
	int		i;
	int		j;

	i = -1;
	j = 0;
	rd = 0;
	rd = read(fd, buffer, 21);
	buffer[rd] = '\0';
	while (buffer[++i])
		if (buffer[i] == '\n')
			j++;
	i = 0;
	while (i < 4 && ((rd == 20 && j == 4) || (rd == 21 && j == 5)))
	{
		ft_strcpy(t->tetri[i], ft_strsub(buffer, (i * 5), 4));
		i++;
	}
	if (rd == 20 && j == 4)
		return(-1);
	return (((rd == 20) || (rd == 21)));
}

int ft_count(t_tetrisa t)
{
	int i;
	int j;
	int n;
	int d;

	i = -1;
	n = 0;
	d = 0;
	while (++i < 4)
	{
		j = -1;
		while (++j < 4)
		{
			if (t.tetri[i][j] == '.')
				n++;
			if (t.tetri[i][j] == '#')
				d++;
		}
	}
	if (n == 12 && d == 4)
		return (1);
	return (0);
}

int ft_form(t_tetrisa t)
{
	int i;
	int j;
	int bond;

	i = -1;
	bond = 0;
	if (ft_count(t))
	while (++i < 4)
	{
		j = -1;
		while(++j < 4)
			if (t.tetri[i][j] == '#')
			{
				if (j > 0 && t.tetri[i][j - 1] == '#')
					bond++;
				if (j < 3 && t.tetri[i][j + 1] == '#')
					bond++;
				if (i > 0 && t.tetri[i - 1][j] == '#')
					bond++;
				if (i < 3 && t.tetri[i + 1][j] == '#')
					bond++;
			}
	}
	return (bond == 6 || bond == 8);
}

int		ft_stock(int fd, t_file *t)
{
	int i;
	int a;

	i = -1;

	while (t->count < 26 && (a = ft_test(fd, &t->file[++i])) != 0) 
	{
		printf("//%d//\n", a);
		if (!ft_form(t->file[i]))
			return (0);
		t->count++;
		if (a == -1)
			break;
	}
	
	if ((t->count == 26 && a != -1) || a == 0)
		return (0);
	return (1);
}
