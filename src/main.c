#include "../includes/cub3D.h"

int	main(int ac, char **av)
{
	t_map	*map;
	if (ac < 2)
		return (ft_err("Too few arguments\n"));
	if (ft_check_ext(av[1]) == 1)
		return (ft_err("Please use a .cub extension file\n"));
	while (1)
	{
		map = ft_init_struct(av[1]);
		if (map->err > 0)
			return (ft_end(map), 1);
		ft_start_game(map);
	}
	return (0);
}
