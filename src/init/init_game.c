/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: estepere <estepere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/05 21:59:41 by estepere          #+#    #+#             */
/*   Updated: 2025/03/05 22:01:20 by estepere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

void	init_data(t_map *map)
{
	map->max_h = ft_tab_len(map->map);
	map->max_w = len_map_width(map->map);
	map->ray->camera_x = 0.0;
	map->map_x = (int)map->player->pos_x;
	map->map_y = (int)map->player->pos_y;
	map->ray->delta_dist_x = fabs(1 / map->ray->ray_dir_x);
	map->ray->delta_dist_y = fabs(1 / map->ray->ray_dir_y);
	map->ray->hit_wall = 0;
}

void	init_key_states(t_map *map)
{
	int	i;

	i = 0;
	while (i < 8)
	{
		map->key_states[i] = 0;
		i++;
	}
}

void	ft_start_game(t_map *map)
{
	ft_malloc_game(map);
	ft_window_init(map);
	init_key_states(map);
	ft_init_textures(map, map->t, map->mini->mnmap);
	ft_events_init(map);
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
	map->map[y][x] = 'P';
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
