#include "../../includes/cub3D.h"

void	ft_init_mlx(t_map *map)
{
	t_mlx	mlx;

	mlx.name = "Cub3d";
	map->mlx = &mlx;
	ft_window_init(map);
	mlx_loop(map->mlx->mlx);
}