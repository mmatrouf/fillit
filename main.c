/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmatrouf <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/23 15:01:25 by mmatrouf          #+#    #+#             */
/*   Updated: 2019/07/23 16:51:59 by mmatrouf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		main(int ac, char const **av)
{
	t_file	t;
	int		fd;

	fd = open(av[1], O_RDONLY);
	if (ac == 2)
	{
		if (ft_stock(fd, &t))
		{
			ft_map_size(&t);
			ft_map_new(&t);
			while (ft_solve(&t, 0) == 0)
			{
				t.size++;
				ft_map_new(&t);
			}
			ft_display(t);
			ft_clean_map(&t);
		}
		else
			ft_putendl("error");
	}
	else
		ft_putendl("usage: ./fillit target_file");
	return (0);
}
