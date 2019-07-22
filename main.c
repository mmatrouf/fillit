#include "fillit.h"
int        main(int argc, char const *argv[])
{
	t_file	t;
	int		fd;
	int		size;

	fd = open(argv[1], O_RDONLY);
	if (argc == 2)
	{
		if (ft_stock(fd, &t))
		{
			ft_upperleft(&t);
			size = ft_map_size(t);
			ft_map_new(&t, size);
			while (ft_solve(&t, size, 0) == 0)
			{
				size++;		
				ft_map_new(&t, size);
			}
			ft_display(&t, size);
		}
		else
			ft_putendl("error");
		}
	else
		ft_putendl("usage: ./fillit target_file");
	return (0);
}
