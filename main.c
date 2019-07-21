#include "fillit.h"
int        main(int argc, char const *argv[])
{
	t_file    t;
	int                fd;
	int a;
	int size;
	int i;

	fd = open(argv[1], O_RDONLY);
	if (argc == 2)
	{
		if (ft_stock(fd, &t))
		{
			ft_upperleft(&t);
			//size = ft_sqrt(t.count * 4);
			size = ft_map_size(t);
			ft_map_new(&t, size);
			//i = -1;
			while (ft_solve(&t, size, 0) == 0)
			{
				size++;
				ft_map_new(&t, size);
			}
		ft_display(&t, size);
		}
		else
			ft_putendl("error");
		//ft_display(&t, size);
		/*a = -1;
		printf("%d",size);
		while(++a < size)
		{
				ft_putendl(t.map[a]);
		}*/
	}
	else
		ft_putendl("usage: ./fillit target_file");
	return (0);
}
