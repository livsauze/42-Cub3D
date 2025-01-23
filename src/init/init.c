#include "../includes/cub3D.h"

t_map	*ft_init_struct(char *file)
{
	t_map	*map;
	t_mlx	mlx;

	map = malloc(sizeof(t_map));
	map->err = 0;
	map->fd = open(file, O_RDONLY);
	if (map->fd < 0)
		return (printf("%s\n", "Error\nCannot open file"), map->err = 2, map);
	mlx.name = "Cub3d"; 
	ft_window_init(&mlx);

	mlx_loop_hook(mlx.mlx, &no_event, &mlx);
	mlx_loop(mlx.mlx);
	return (map);
}
