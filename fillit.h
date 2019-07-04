#ifndef FILLIT_H
# define FILLIT_H
# include"libft/libft.h"
# include <fcntl.h>

typedef struct	s_tetrisa
{
	char	tetri[4][5];
}				t_tetrisa;

typedef struct	s_file
{
	t_tetrisa	file[26];
}				t_file;

int		ft_stock(int fd, t_file *t);
int		ft_form(t_tetrisa t);
int		ft_test(int fd, t_tetrisa *t);
int		ft_count(t_tetrisa t);

#endif
