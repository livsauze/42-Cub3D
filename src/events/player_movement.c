/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_movement.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: estepere <estepere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/05 21:49:41 by estepere          #+#    #+#             */
/*   Updated: 2025/03/05 21:58:29 by estepere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3D.h"

void	rotation_player(t_map *map, t_player *player, double theta)
{
	double	old_dir_x;
	double	old_dir_y;
	double	old_plane_x;

	old_plane_x = map->ray->plane_x;
	old_dir_x = player->dir_x;
	old_dir_y = player->dir_y;
	player->dir_x = old_dir_x * cos(theta) - old_dir_y * sin(theta);
	player->dir_y = old_dir_x * sin(theta) + old_dir_y * cos(theta);
	map->ray->plane_x = old_plane_x * cos(theta)
		-map->ray->plane_y * sin(theta);
	map->ray->plane_y = old_plane_x * sin(theta)
		+ map->ray->plane_y * cos(theta);
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
