#include "../../includes/cub3D.h"

int	ft_hook(t_map *map)
{
	ray_casting(map->ray, map->player, map);
	mlx_put_image_to_window(map->mlx, map->window, map->img->img, 0, 0);
	return (0);
}

int	len_map_width(char **map)
{
	int	max_width;
	int	i;
	int	len;

	max_width = 0;
	i = 0;
	
	while(map[i])
	{
		len = ft_strlen(map[i]);
		if (len > max_width)
			max_width = len;
		i++;
	}
	return(max_width);
}
void init_data(t_map *map)
{
	map->ray->camera_x = 0.0;
	map->map_x = (int)map->player->pos_x; // Same position because the display ray begin at the position of the player 
	map->map_y = (int)map->player->pos_y; // cast to int to have the cell of the current ray. exemple if pos_x = 5,7 => ray_x = 5
	map->map_height = ft_tab_len(map->map);
	map->map_width = len_map_width(map->map);
	map->ray->hit_wall = 0;
}
void	ft_malloc_game(t_map *map)
{
	map->img = malloc(sizeof(t_img));
	map->texture = malloc(sizeof(t_text));
	map->texture->wall_no = malloc(sizeof(t_img));
	map->texture->wall_so = malloc(sizeof(t_img));
	map->texture->wall_we = malloc(sizeof(t_img));
	map->texture->wall_ea = malloc(sizeof(t_img));
}

void	ft_start_game(t_map *map)
{
	ft_malloc_game(map);
	init_data(map);
	ft_window_init(map);
	mlx_loop_hook(map->mlx, ft_hook, map);
	mlx_loop(map->mlx);
}




void	get_dir_player(t_map *map, int x, int y)
{
	if (map->map[y][x] == 'N')
	{
		map->player->dir_x = 0.0;
		map->player->dir_y = -1.0;
	}
	else if (map->map[y][x] == 'S')
	{
		map->player->dir_x = 0.0;
		map->player->dir_y = 1.0;
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
	map->ray->plane_x = -(map->player->dir_y * 0.66);
	map->ray->plane_y = map->player->dir_x * 0.66;
}

int	ft_init_player(t_map *map, int x, int y, int nb_player)
{
	if (nb_player > 0)
	{
		ft_err("Map : more than one player detected\n", map);
		return (2);
	}
	map->player = malloc(sizeof(t_player));
	map->ray = malloc(sizeof(t_ray));
	map->player->pos_x = x + 0.5;
	map->player->pos_y = y + 0.5;
	get_dir_player(map, x, y);
	return (1);
}