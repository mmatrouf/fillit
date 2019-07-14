/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drag.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmatrouf <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/07 01:14:52 by mmatrouf          #+#    #+#             */
/*   Updated: 2019/07/07 01:42:50 by mmatrouf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

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
