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
	map->ray->delta_dist_x = fabs(1 / map->ray->ray_dir_x);
	map->ray->delta_dist_y = fabs(1 / map->ray->ray_dir_y);
	map->ray->hit_wall = 0;
}


void	ft_start_game(t_map *map)
{
	ft_init_mlx(map);
	mlx_loop_hook(map->mlx->mlx, ft_minimap, map);
}


int	ft_init_player(t_map *map, int x, int y, int player)
{
	if (player > 0)
	{
		ft_err("Map : more than one player detected\n", map);
		return (2);
	}
	map->player = malloc(sizeof(t_player));
	map->player->pos_x = x;
	map->player->pos_y = y;
	return (1);
}