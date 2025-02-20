#include "../../includes/cub3D.h"

void	ft_malloc_game(t_map *map)
{
	map->ray = malloc(sizeof(t_ray));
	map->texture = malloc(sizeof(t_text));
	map->mini = malloc(sizeof(t_minimap));
	map->texture->wall_no = malloc(sizeof(t_img));
	map->texture->wall_so = malloc(sizeof(t_img));
	map->texture->wall_we = malloc(sizeof(t_img));
	map->texture->wall_ea = malloc(sizeof(t_img));
	map->texture->bckg = malloc(sizeof(t_img));
	map->mini->mnmap = malloc(sizeof(t_img));
	init_data(map);
}

void init_data(t_map *map)
{
	map->max_h = ft_tab_len(map->map);
	map->max_w = len_map_width(map->map) + 1;
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
	ft_malloc_game(map);
	ft_window_init(map);
	ft_init_textures(map, map->texture);
	mlx_loop_hook(map->mlx, ft_hook, map);
	mlx_loop(map->mlx);
}

void	get_dir_player(t_map *map, int x, int y)
{
	if (map->map[y][x] == 'N')
	{
		map->player->dir_x = 0.0;
		map->player->dir_y = 1.0;
	}
	else if (map->map[y][x] == 'S')
	{
		map->player->dir_x = 0.0;
		map->player->dir_y = -1.0;
	}
	else if (map->map[y][x] == 'W')
	{
		map->player->dir_x = -1.0;
		map->player->dir_y = 0.0;
	}
	else if (map->map[y][x] == 'E')
	{
		map->player->dir_x = 1.0;
		map->player->dir_y = 0.0;
	}
	printf("dir x = %f\ndir y = %f\n", map->player->dir_x, map->player->dir_y);
	printf("pos x = %f\npos y = %f\n", map->player->pos_x, map->player->pos_y);

}

int	ft_init_player(t_map *map, int x, int y, int nb_player)
{
	if (nb_player > 0)
	{
		ft_err("Map : more than one player detected\n", map);
		return (2);
	}
	map->player = malloc(sizeof(t_player));
	map->player->pos_x = x;
	map->player->pos_y = y;
	get_dir_player(map, x, y);
	// NEED TO IMPLEMENT DIRECTIONS PLAYER
	return (1);
}