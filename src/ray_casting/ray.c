/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: estepere <estepere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 17:45:27 by estepere          #+#    #+#             */
/*   Updated: 2025/02/26 15:59:21 by estepere         ###   ########.fr       */
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
		ray->side_dist_x = (map->map_x + 1.0 - player->pos_x) * ray->delta_dist_x;
	}
	if (ray->ray_dir_y < 0)
	{
		ray->step_y = -1;
		ray->side_dist_y = (player->pos_y - map->map_y) * ray->delta_dist_y;
	}
	else
	{
		ray->step_y = 1;
		ray->side_dist_y = (map->map_y + 1.0 - player->pos_y) * ray->delta_dist_y;
	}
}

void	dda_algo(t_ray *ray, t_player *player, t_map *map, int x)
{
	ray->hit_wall = 0; // CHECK THE PLACEMENT
	initial_distance(ray, player, map);
	while(ray->hit_wall == 0)
	{
		if (ray->side_dist_x < ray->side_dist_y)
		{
			ray->side_dist_x += ray->delta_dist_x; // move to x*square of delta_x
			map->map_x += ray->step_x; // update of the curr ray in the grid
			ray->side_wall = 0;
		}
		else
		{
			ray->side_dist_y += ray->delta_dist_y;
			map->map_y += ray->step_y;
			ray->side_wall = 1;
		}
		// Vérification si step_x ou step_y change anormalement
		// if (map->map_x < 0 || map->map_x >= map->map_width || map->map_y < 0
		// 	|| map->map_y >= map->map_height)
		// 	break;
		// if (map->map_x < 0)
 	   	// 	map->map_x = 0;
		// if (map->map_x >= map->map_width)
 		//    map->map_x = map->map_width - 1;
		// if (map->map_y < 0)
		//     map->map_y = 0;
		// if (map->map_y >= map->map_height)
  		// 	map->map_y = map->map_height - 1;
		if (map->map[map->map_y][map->map_x] == '1')
			ray->hit_wall = 1;
	}
	wall_dist(map, ray, x);
}

// start ray display OK
void	ray_casting(t_ray *ray, t_player *player, t_map *map)
{
	int	x;
	x = 0;
	while (x < WIDTH)
	{
	// calculate ray position (camera_x) and direction (ray_dir)
		ray->camera_x = 2 * x / (double)WIDTH - 1;
		// ray->camera_x = (2 * x / (double)WIDTH - 1) * (WIDTH / (double)HEIGHT);
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
