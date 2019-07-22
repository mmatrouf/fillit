#ifndef FILLIT_H
# define FILLIT_H
# include "libft/libft.h"
# include <fcntl.h>
# include <stdio.h>
# include <unistd.h>

typedef struct	s_tetrisa
{
	char	a;
	char	tetri[4][5];
	int		x[4];
	int		y[4];
}				t_tetrisa;

typedef struct	s_file
{
	t_tetrisa	file[26];
	char		**map;
	int			count;
}				t_file;

void	ft_clean_map(t_file *h, int size);
int 	ft_map_size(t_file h);
void	ft_del_tet(t_file *h, int i, int x, int y);
int 	ft_add_tet(t_file *h, int i, int size, int x, int y);
void	ft_map_new(t_file *h, int size);
void	ft_upperleft(t_file *h);
void	ft_coor(t_tetrisa *t);
int		ft_stock(int fd, t_file *t);
int		ft_form(t_tetrisa t);
int		ft_test(int fd, t_tetrisa *t);
int		ft_count(t_tetrisa t);
int		ft_sqrt(int n);
int		ft_solve(t_file *h, int size, int n);
void	ft_display(t_file *t, int size);
#endif
