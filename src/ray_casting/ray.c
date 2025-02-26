/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: livsauze <livsauze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 17:45:27 by estepere          #+#    #+#             */
/*   Updated: 2025/02/26 15:08:05 by livsauze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"
// ok
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
	printf("INIT SIDE DIST : sd_x = %f, sd_y = %f\n", ray->side_dist_x, ray->side_dist_y);
}



// ok
void	dda_algo(t_ray *ray, t_player *player, t_map *map, int x)
{
	ray->hit_wall = 0; // CHECK THE PLACEMENT
	initial_distance(ray, player, map);
	printf("****************************************\n");
	printf("BEFORE UPDATE : x = %d | side_dist_x = %f, side_dist_y = %f | step_x = %d, step_y = %d\n", 
		x, ray->side_dist_x, ray->side_dist_y, ray->step_x, ray->step_y);	
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
		printf("AFTER Update: side_dist_x = %f, side_dist_y = %f\n", ray->side_dist_x, ray->side_dist_y);
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
		{
			ray->hit_wall = 1;
			printf("------------------------------------------------\n");
			printf("Mur touché ! Coordonnées impact : (%d, %d)\n", map->map_x, map->map_y);
		}
	// printf("------------------------------------------------\n");
	// printf("\033[1;32mside_dist_x = %f\033[0m\n", ray->side_dist_x);
	// printf("\033[1;32mdelta_dist_x = %f\033[0m\n", ray->delta_dist_x);
	// printf("\033[1;34mside_dist_y = %f\033[0m\n", ray->side_dist_y);
	// printf("\033[1;34mdelta_dist_y = %f\033[0m\n", ray->delta_dist_y);
	// printf("plane x = %f\n", map->ray->plane_x);
	// printf("plane y = %f\n", map->ray->plane_y);
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
		// printf("camera_x = %f\n", ray->camera_x);
		map->map_x = (int)player->pos_x;
        map->map_y = (int)player->pos_y;
		// ray->camera_x = (2 * x / (double)WIDTH - 1) * (WIDTH / (double)HEIGHT);
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

// init_data() : Initialise les variables (position, direction, plan de la caméra).

// raycasting() : Implémente l'algorithme de ray-casting.

// draw_vertical_line() : Dessine une ligne verticale à l'écran.

// key_hook() : Gère les entrées clavier pour déplacer le joueur.