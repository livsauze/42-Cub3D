#include "../includes/cub3D.h"


void	rotation_player(t_map *map, t_player *player, double theta)
{
	double old_dir_x;
	double old_dir_y;
	double old_plane_x;
	
	old_plane_x = map->ray->plane_x;
	old_dir_x = player->dir_x;
	old_dir_y = player->dir_y;

	player->dir_x = old_dir_x * cos(theta) - old_dir_y * sin(theta);
	player->dir_y = old_dir_x * sin(theta) + old_dir_y * cos(theta);

	map->ray->plane_x = old_plane_x * cos(theta) - map->ray->plane_y * sin(theta);
	map->ray->plane_y = old_plane_x * sin(theta) + map->ray->plane_y * cos(theta);
}
void	front_mov(t_player *player, int key)
{
	if (key == XK_w)
	{
		player->pos_x = player->pos_x + player->dir_x * MOV_PLAYER;
		player->pos_y = player->pos_y + player->dir_y * MOV_PLAYER;
	}
	else
	{
		player->pos_x = player->pos_x - player->dir_x * MOV_PLAYER;
		player->pos_y = player->pos_y - player->dir_y * MOV_PLAYER;
	}
}

void	side_mov(t_map *map, t_player *player, int key)
{
	if (key == XK_d)
	{
		player->pos_x = player->pos_x + map->ray->plane_x * MOV_PLAYER;
		player->pos_y = player->pos_y + map->ray->plane_y * MOV_PLAYER;
	}
	else
	{
		player->pos_x = player->pos_x - map->ray->plane_x * MOV_PLAYER;
		player->pos_y = player->pos_y - map->ray->plane_y * MOV_PLAYER;
	}
}

void	ft_move(t_map *map, t_player *player, int key)
{
	if (key == XK_Left && !ft_check_wall(map->map, player, key))
		rotation_player(map, player, -ROT_SPEED);
	else if (key == XK_Right && !ft_check_wall(map->map, player, key))
		rotation_player(map, player, ROT_SPEED);
	else if ((key == UP || key == DOWN) && !ft_check_wall(map->map, player, key))
		front_mov(player, key);
	else if ((key == LEFT || key == RIGHT) && !ft_check_wall(map->map, player, key))
		side_mov(map, player, key);	
	// ft_change_mnmap(map->map, map->player);
}