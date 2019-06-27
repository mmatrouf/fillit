/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmatrouf <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/22 16:32:07 by mmatrouf          #+#    #+#             */
/*   Updated: 2019/06/26 21:55:36 by mmatrouf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "fillit.h"


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
	return (((rd == 20 && j == 4) || (rd == 21 && j == 5)) ? 1 : 0);

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

/*int ft_form(t_tetrisa t)
{
	int i;
	int j;

	i = 0;
	while(i < 4)
	{
		j = 0;
		while(j < 4)
		{
			if (t.tetri[i][j] == '#')
			{
				if (t.tetri[i][j + (j < 3)] != '#' && t.tetri[i + (i < 3)][j] != '#')
					return (0);
			}
			j++;
		}
		i++;
	}
	return (1);
}*/

int ft_form(t_tetrisa t)
{
	int i;
	int j;

	i = -1;
	while(++i < 4)
	{
		j = -1;
		while(++j < 4)
			if (t.tetri[i][j] == '#')
			{
				if(i == 0 && j == 0)
					if (t.tetri[i][j + 1] != '#' && t.tetri[i + 1][j] != '#')
						return (0);
				if (i == 0 && j != 0)
					if (t.tetri[i][j + (j < 3)] != '#' && t.tetri[i + (i < 3)][j] != '#' && t.tetri[i][j - 1] != '#')
						return (0);
				if (i != 0 && j == 0)
					if (t.tetri[i][j + (j < 3)] != '#' && t.tetri[i + (i < 3)][j] != '#' && t.tetri[i - 1][j] != '#')
						return (0);
				if (i != 0 && j != 0)
					if (t.tetri[i][j + (j < 3)] != '#' && t.tetri[i + (i < 3)][j] != '#' && t.tetri[i - 1][j] != '#'
						   	&& t.tetri[i][j - 1] != '#')
						return (0);
			}
	}
	return (1);
}
