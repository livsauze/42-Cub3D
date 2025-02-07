#include "../../includes/cub3D.h"


void init_data(t_map *map)
{
	map->player->pos_x = 5.0;
	map->player->pos_y = 5.0;
	map->player->dir_x = -1.0;
	map->player->dir_y = 0.0;
	map->ray->plane_x = 0.0;
	map->ray->plane_y = 0.66; // great angle to the fps
	map->map_x = (int)map->player->pos_x; // Same position because the display ray begin at the position of the player 
	map->map_y = (int)map->player->pos_y; // cast to int to have the cell of the current ray. exemple if pos_x = 5,7 => ray_x = 5
	ray->delta_dist_x = fabs(1 / ray_dir_x);
	ray->delta_dist_y = fabs(1 / ray_dir_y);
	ray->hit_wall = 0;
}

void	ft_start_game(t_map *map)
{
	(void)map;
	ft_init_mlx(map);
	init_data(map);

	
	// printf("%s\n", "it's working!!!");
}