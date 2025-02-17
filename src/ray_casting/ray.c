/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: estepere <estepere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 17:45:27 by estepere          #+#    #+#             */
/*   Updated: 2025/02/17 17:52:40 by estepere         ###   ########.fr       */
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
		ray->side_dist_x = (player->pos_x + 1.0 - map->map_x) * ray->delta_dist_x;
	}
	if (ray->ray_dir_y < 0)
	{
		ray->step_y = -1;
		ray->side_dist_y = (player->pos_y - map->map_y) * ray->delta_dist_y;
	}
	else
	{
		ray->step_y = 1;
		ray->side_dist_y = (player->pos_y + 1.0 - map->map_y) * ray->delta_dist_y;
	}
}




void	dda_algo(t_ray *ray, t_player *player, t_map *map, int x)
{
	initial_distance(ray, player, map);
	while(1)
	{
		if (ray->side_dist_x < ray->side_dist_y)
		{
			ray->side_dist_x += ray->delta_dist_x; // move to x*square of delta_x
			map->map_x += ray->step_x; // update of the curr ray in the grid
			ray->side_wall = 0;
		}
		else if (ray->side_dist_y < ray->side_dist_x)
		{
			ray->side_dist_y += ray->delta_dist_y;
			map->map_y += ray->step_y;
			ray->side_wall = 1;
		}
		if (map->map_x < 0 || map->map_x >= WIDTH || map->map_y < 0 || map->map_y >= HEIGHT)
			break;
		if (map->map[map->map_x][map->map_y] == '1')
			break;
	}
	wall_dist(map, player, ray, x);
	
}

// start ray display
void	ray_casting(t_ray *ray, t_player *player, t_map *map)
{
	int	x;
	
	x = 0;
	while (x < WIDTH)
	{
	// calculate ray position (camera_x) and direction (ray_dir)
		ray->camera_x = 2 * x / (double)WIDTH - 1;
		ray->ray_dir_x = player->dir_x + ray->plane_x * ray->camera_x;
		ray->ray_dir_y = player->dir_y + ray->plane_y * ray->camera_y;
		dda_algo(ray, player, map, x);
		x++;
	}
}

// init_data() : Initialise les variables (position, direction, plan de la caméra).

// raycasting() : Implémente l'algorithme de ray-casting.

// draw_vertical_line() : Dessine une ligne verticale à l'écran.

// key_hook() : Gère les entrées clavier pour déplacer le joueur.