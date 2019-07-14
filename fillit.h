#ifndef FILLIT_H
# define FILLIT_H
# include"libft/libft.h"
# include <fcntl.h>

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
	int			count;
}				t_file;


char 	**ft_add_tet(char **map, t_tetrisa h, int size);
char	**ft_map_new(int size);
void	ft_upperleft(t_file *h);
void	ft_coor(t_tetrisa *t);
int		ft_stock(int fd, t_file *t);
int		ft_form(t_tetrisa t);
int		ft_test(int fd, t_tetrisa *t);
int		ft_count(t_tetrisa t);

#endif
