#include "../../includes/cub3D.h"

void	ft_init_mlx(t_map *map)
{
	ft_window_init(map);
	mlx_loop(map->mlx);
}