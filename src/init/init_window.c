#include "../../includes/cub3D.h"

void	ft_malloc_error(void)
{
	perror("malloc problems");
	exit(EXIT_FAILURE);
}

// ignor to do mlx_loop_hook
int     no_event(t_mlx *mlx) 
{
    (void)mlx;
    return (0); 
}

void	ft_window_init(t_map *map)
{	
	map->mlx->mlx = mlx_init();
	if (map->mlx->mlx == NULL)
		ft_malloc_error();
	map->mlx->window = mlx_new_window(map->mlx->mlx, WIDTH, HEIGHT, map->mlx->name);
	if (map->mlx->window == NULL)
	{
		mlx_destroy_display(map->mlx->mlx);
		free(map->mlx->mlx);
		ft_malloc_error();
	}
	map->mlx->img = mlx_new_image(map->mlx->mlx, WIDTH, HEIGHT);
	if (map->mlx->img == NULL)
	{
		mlx_destroy_window(map->mlx->mlx, map->mlx->window);
		mlx_destroy_display(map->mlx->mlx);
		free(map->mlx->mlx);
		ft_malloc_error();
	}
	map->mlx->addr = mlx_get_data_addr(map->mlx->img, &map->mlx->bits_per_pixel,
			&map->mlx->line_len, &map->mlx->endian);
	ft_events_init(map);
}

