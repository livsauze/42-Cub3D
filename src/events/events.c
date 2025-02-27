#include "../includes/cub3D.h"

void	ft_destroy_img(t_map *map, t_text *texture)
{
	// if (map->img->img)
	// 	mlx_destroy_image(map->mlx, map->img->img);
	if (map->mini->mnmap)
		mlx_destroy_image(map->mlx, map->mini->mnmap->img);
	if (texture->wall_so)
		mlx_destroy_image(map->mlx, texture->wall_so->img);
	if (texture->wall_no)
		mlx_destroy_image(map->mlx, texture->wall_no->img);
	if (texture->wall_we)
		mlx_destroy_image(map->mlx, texture->wall_we->img);
	if (texture->wall_ea)
		mlx_destroy_image(map->mlx, texture->wall_ea->img);
}

int	ft_close_handler(t_map *map)
{
	ft_destroy_img(map, map->t);
	ft_end(map);
	if (map->window)
		mlx_destroy_window(map->mlx, map->window);
	if (map->mlx)
	{
		mlx_loop_end(map->mlx);
		mlx_destroy_display(map->mlx);
		free(map->mlx);
	}
	free(map);
	exit(EXIT_SUCCESS);
	return (0);
}

void	ft_events_init(t_map *map)
{
	mlx_hook(map->window, KeyPress, KeyPressMask, ft_key_handler, map);
	mlx_hook(map->window, 17, (1L << 17), ft_close_handler, map);
}

void	ft_move(t_map *map, t_player *player, int key)
{
	if (key == 119 && !ft_check_wall(map->map, player, key))
		player->pos_y -= 0.1;
	else if (key == 97 && !ft_check_wall(map->map, player, key))
		player->pos_x -= 0.1;
	else if (key == 115  && !ft_check_wall(map->map, player, key))
		player->pos_y += 0.1;
	else if (key == 100  && !ft_check_wall(map->map, player, key))
		player->pos_x += 0.1;
	ft_change_mnmap(map->map, map->player);
}

int	ft_key_handler(int keysym, t_map *map)
{
	if (keysym == XK_Escape)
	{
		ft_close_handler(map);
	}
	// else if (keysym == 119 || keysym == 97 || keysym == 115
	// 	|| keysym == 100 || keysym == XK_Left || keysym == XK_Right)
	// 	ft_move(map, map->player, keysym);
	// printf("player x : %f, player y : %f\n", map->player->pos_x, map->player->pos_y);
	// ft_hook(map);
	return (0);
}
