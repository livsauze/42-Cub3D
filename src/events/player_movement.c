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

void	front_mov(t_map *map, t_player *player, int key)
{
	double	new_x;
	double	new_y;

	if (key == XK_w) // Avancer
	{
		new_x = player->pos_x + player->dir_x * MOV_PLAYER;
		new_y = player->pos_y + player->dir_y * MOV_PLAYER;
	}
	else // Reculer
	{
		new_x = player->pos_x - player->dir_x * MOV_PLAYER;
		new_y = player->pos_y - player->dir_y * MOV_PLAYER;
	}
	if (map->map[(int)(new_y + COLLISION_MARGIN)][(int)(new_x + COLLISION_MARGIN)] != '1') 
	{
		player->pos_x = new_x;
		player->pos_y = new_y;
	}
}
void	side_mov(t_map *map, t_player *player, int key)
{
	double	new_x;
	double	new_y;

	if (key == XK_d) // Déplacement latéral à droite
	{
		new_x = player->pos_x + map->ray->plane_x * MOV_PLAYER;
		new_y = player->pos_y + map->ray->plane_y * MOV_PLAYER;
	}
	else // Déplacement latéral à gauche
	{
		new_x = player->pos_x - map->ray->plane_x * MOV_PLAYER;
		new_y = player->pos_y - map->ray->plane_y * MOV_PLAYER;
	}
	if (map->map[(int)(new_y + COLLISION_MARGIN)][(int)(new_x + COLLISION_MARGIN)] != '1') 
	{
		player->pos_x = new_x;
		player->pos_y = new_y;
	}
}

void	ft_move(t_map *map, t_player *player, int key)
{
	if (key == XK_Left)
		rotation_player(map, player, -ROT_SPEED);
	else if (key == XK_Right)
		rotation_player(map, player, ROT_SPEED);
	else if ((key == UP || key == DOWN))
		front_mov(map, player, key);
	else if ((key == LEFT || key == RIGHT))
		side_mov(map, player, key);	
	ft_change_mnmap(map->map, map->player);
}