#include "../../includes/cub3D.h"

void	ft_start_game(t_map *map)
{
	(void)map;
	t_mlx	mlx;

	mlx.name = "Cub3d"; 
	ft_window_init(&mlx);
	mlx_loop_hook(mlx.mlx, &no_event, &mlx);
	mlx_loop(mlx.mlx);
	// printf("%s\n", "it's working!!!");
}