/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_struct.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: estepere <estepere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/05 21:58:48 by estepere          #+#    #+#             */
/*   Updated: 2025/03/05 22:01:11 by estepere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

void	ft_malloc_game(t_map *map)
{
	map->t = malloc(sizeof(t_text));
	map->mini = malloc(sizeof(t_minimap));
	map->img = malloc(sizeof(t_img));
	map->t->wall_no = malloc(sizeof(t_img));
	map->t->wall_so = malloc(sizeof(t_img));
	map->t->wall_we = malloc(sizeof(t_img));
	map->t->wall_ea = malloc(sizeof(t_img));
	map->mini->mnmap = malloc(sizeof(t_img));
	init_data(map);
}

void	ft_clean_init_data(t_map *map)
{
	int	i;

	map->color = 0;
	map->max_w = -1;
	map->max_h = -1;
	map->map_x = -1;
	map->map_y = -1;
	map->fd = -1;
	map->err = 0;
	map->no = NULL;
	map->so = NULL;
	map->we = NULL;
	map->ea = NULL;
	i = -1;
	while (++i < 3)
	{
		map->ceiling[i] = -1;
		map->floor[i] = -1;
	}
}

t_map	*ft_clean_init_struct(t_map *map)
{
	ft_clean_init_data(map);
	map->map = NULL;
	map->window = NULL;
	map->mlx = NULL;
	map->player = NULL;
	map->mini = NULL;
	map->t = NULL;
	map->ray = NULL;
	return (map);
}

t_map	*ft_init_struct(char *file)
{
	t_map	*map;

	map = malloc(sizeof(t_map));
	ft_clean_init_struct(map);
	map->fd = open(file, O_RDONLY);
	if (map->fd < 0)
		return (ft_err("Cannot open file\n", map), map);
	ft_get_map(map);
	return (map);
}
