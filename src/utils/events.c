#include "../includes/cub3D.h"

int	ft_close_handler(t_map *map)
{
	if (map->mlx->img)
		mlx_destroy_image(map->mlx->mlx, map->mlx->img);
	if (map->mlx->window)
		mlx_destroy_window(map->mlx->mlx, map->mlx->window);
	if (map->mlx->mlx)
	{
		mlx_loop_end(map->mlx->mlx);
		mlx_destroy_display(map->mlx->mlx);
		free(map->mlx->mlx);
	}
	ft_end(map);
	free(map);
	exit(EXIT_SUCCESS);
	return (0);
}

void	ft_events_init(t_map *map)
{
	mlx_hook(map->mlx->window, KeyPress, KeyPressMask, ft_key_handler, map);
	mlx_hook(map->mlx->window, DestroyNotify, StructureNotifyMask, ft_close_handler, map);
}

int	ft_key_handler(int keysym, t_map *map)
{
	if (keysym == XK_Escape)
	{
		ft_close_handler(map);
	}
	return (0);
}