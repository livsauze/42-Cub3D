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

int	hit_the_wall(t_map *map, double new_x, double new_y)
{
	double	top;
	double	bottom;
	double	left;
	double	right;

	top = new_y - COLLISION_MARGIN;
	bottom = new_y + COLLISION_MARGIN;
	left = new_x - COLLISION_MARGIN;
	right = new_x + COLLISION_MARGIN;

	if (map->map[(int)top][(int)left] == '1')
		return(1);
	if (map->map[(int)top][(int)right] == '1')
		return(1);
	if (map->map[(int)bottom][(int)left] == '1')
		return(1);
	if (map->map[(int)bottom][(int)right] == '1')
		return(1);
	return(0);

}
void	back_mov(t_map *map, t_player *player)
{
	double	new_x;
	double	new_y;

	new_x = player->pos_x - player->dir_x * MOV_PLAYER;
	new_y = player->pos_y - player->dir_y * MOV_PLAYER;
	if (hit_the_wall(map, new_x, new_y) == 0) 
	{
		player->pos_x = new_x;
		player->pos_y = new_y;
	}
}

void	front_mov(t_map *map, t_player *player)
{
	double	new_x;
	double	new_y;

	new_x = player->pos_x + player->dir_x * MOV_PLAYER;
	new_y = player->pos_y + player->dir_y * MOV_PLAYER;
	if (hit_the_wall(map, new_x, new_y) == 0) 
	{
		player->pos_x = new_x;
		player->pos_y = new_y;
	}
}

void	right_mov(t_map *map, t_player *player)
{
	double	new_x;
	double	new_y;

	new_x = player->pos_x + map->ray->plane_x * MOV_PLAYER;
	new_y = player->pos_y + map->ray->plane_y * MOV_PLAYER;
	if (hit_the_wall(map, new_x, new_y) == 0) 
	{
		player->pos_x = new_x;
		player->pos_y = new_y;
	}
}

void	left_mov(t_map *map, t_player *player)
{
	double	new_x;
	double	new_y;

	new_x = player->pos_x - map->ray->plane_x * MOV_PLAYER;
	new_y = player->pos_y - map->ray->plane_y * MOV_PLAYER;

	if (hit_the_wall(map, new_x, new_y) == 0) 
	{
		player->pos_x = new_x;
		player->pos_y = new_y;
	}
}

void	ft_move(t_map *map, t_player *player, int *keystate)
{
	if (keystate[4] == 1)
		rotation_player(map, player, -ROT_SPEED);
	if (keystate[5] == 1)
		rotation_player(map, player, ROT_SPEED);
	if (keystate[0] == 1)
		front_mov(map, player);
	if (keystate[2] == 1)
		back_mov(map, player);
	if (keystate[1] == 1)
		left_mov(map, player);	
	if (keystate[3] == 1)
		right_mov(map, player);	
	if (keystate[6] == 1)
		ft_close_handler(map);
	ft_change_mnmap(map->map, map->player);
}