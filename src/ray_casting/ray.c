/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: estepere <estepere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/05 22:05:47 by estepere          #+#    #+#             */
/*   Updated: 2025/03/05 22:10:24 by estepere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

void	initial_distance(t_ray *ray, t_player *player, t_map *map)
{
	if (ray->ray_dir_x < 0)
	{
		ray->step_x = -1;
		ray->side_dist_x = (player->pos_x - map->map_x) * ray->delta_dist_x;
	}
	else
	{
		ray->step_x = 1;
		ray->side_dist_x = (map->map_x + 1.0 - player->pos_x)
			* ray->delta_dist_x;
	}
	if (ray->ray_dir_y < 0)
	{
		ray->step_y = -1;
		ray->side_dist_y = (player->pos_y - map->map_y) * ray->delta_dist_y;
	}
	else
	{
		ray->step_y = 1;
		ray->side_dist_y = (map->map_y + 1.0 - player->pos_y)
			* ray->delta_dist_y;
	}
}

void	dda_algo(t_ray *ray, t_player *player, t_map *map, int x)
{
	ray->hit_wall = 0;
	initial_distance(ray, player, map);
	while (ray->hit_wall == 0)
	{
		if (ray->side_dist_x < ray->side_dist_y)
		{
			ray->side_dist_x += ray->delta_dist_x;
			map->map_x += ray->step_x;
			ray->side_wall = 0;
		}
		else
		{
			ray->side_dist_y += ray->delta_dist_y;
			map->map_y += ray->step_y;
			ray->side_wall = 1;
		}
		if (map->map[map->map_y][map->map_x] == '1')
			ray->hit_wall = 1;
	}
	wall_dist(map, ray, x);
}

void	ray_casting(t_ray *ray, t_player *player, t_map *map)
{
	int	x;

	x = 0;
	while (x < WIDTH)
	{
		ray->camera_x = 2 * x / (double)WIDTH - 1;
		map->map_x = (int)player->pos_x;
		map->map_y = (int)player->pos_y;
		ray->ray_dir_x = player->dir_x + ray->plane_x * ray->camera_x;
		ray->ray_dir_y = player->dir_y + ray->plane_y * ray->camera_x;
		if (ray->ray_dir_x == 0)
			ray->delta_dist_x = 1e30;
		else
			ray->delta_dist_x = fabs(1 / ray->ray_dir_x);
		if (ray->ray_dir_y == 0)
			ray->delta_dist_y = 1e30;
		else
			ray->delta_dist_y = fabs(1 / ray->ray_dir_y);
		dda_algo(ray, player, map, x);
		x++;
	}
}
