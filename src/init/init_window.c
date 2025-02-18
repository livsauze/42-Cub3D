#include "../../includes/cub3D.h"

void	ft_malloc_error(void)
{
	perror("malloc problems");
	exit(EXIT_FAILURE);
}

void	ft_window_init(t_map *map)
{	
	map->mlx = mlx_init();
	if (map->mlx == NULL)
		ft_malloc_error();
	map->window = mlx_new_window(map->mlx, WIDTH, HEIGHT, "CUB3D");
	if (map->window == NULL)
	{
		mlx_destroy_display(map->mlx);
		free(map->mlx);
		ft_malloc_error();
	}
	map->img = mlx_new_image(map->mlx, WIDTH, HEIGHT);
	// if (map->mlx->img == NULL)
	// {
	// 	mlx_destroy_window(map->mlx->mlx, map->mlx->window);
	// 	mlx_destroy_display(map->mlx->mlx);
	// 	free(map->mlx->mlx);
	// 	ft_malloc_error();
	// }
	// map->mlx->addr = mlx_get_data_addr(map->mlx->img, &map->mlx->bpp,
	// 		&map->mlx->line_len, &map->mlx->endian);
	ft_events_init(map);
}

