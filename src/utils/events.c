#include "../includes/cub3D.h"

void	ft_destroy_img(t_map *map, t_text *texture)
{
	// if (texture->wall_so)
	// 	mlx_destroy_image(map->mlx, texture->wall_so->img);
	// if (texture->wall_no)
	// 	mlx_destroy_image(map->mlx, texture->wall_no->img);
	// if (texture->wall_we)
	// 	mlx_destroy_image(map->mlx, texture->wall_we->img);
	// if (texture->wall_ea)
	// 	mlx_destroy_image(map->mlx, texture->wall_ea->img);
	if (texture->bckg)
		mlx_destroy_image(map->mlx, texture->bckg->img);
}

int	ft_close_handler(t_map *map)
{
	ft_destroy_img(map, map->t);
	if (map->window)
		mlx_destroy_window(map->mlx, map->window);
	if (map->mlx)
	{
		mlx_loop_end(map->mlx);
		mlx_destroy_display(map->mlx);
		free(map->mlx);
	}
	ft_end(map);
	free(map);
	exit(EXIT_SUCCESS);
	return (0);
}

void	ft_events_init(t_map *map)
{
	mlx_hook(map->window, KeyPress, KeyPressMask, ft_key_handler, map);
	mlx_hook(map->window, 17, (1L << 17), ft_close_handler, map);
}

int	ft_key_handler(int keysym, t_map *map)
{
	if (keysym == XK_Escape)
	{
		ft_close_handler(map);
	}
	return (0);
}
