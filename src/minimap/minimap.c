/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: livsauze <livsauze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/05 22:02:54 by estepere          #+#    #+#             */
/*   Updated: 2025/03/06 18:03:57 by livsauze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3D.h"

void	ft_calc_scale(t_map *map, t_img *mnmap)
{
	map->mini->scale_x = (float)mnmap->width / map->max_w;
	map->mini->scale_y = (float)mnmap->height / map->max_h;
}

int	ft_color(t_map *map, int pos_x, int pos_y)
{
	int	color;

	ft_calc_scale(map, map->mini->mnmap);
	if (pos_y < 0 || pos_y >= map->max_h || !map->map[pos_y])
		return (BLACK);
	if (pos_x < 0 || pos_x >= ft_strlen(map->map[pos_y]))
		return (BLACK);
	if (map->map[pos_y][pos_x] == '\0' || map->map[pos_y][pos_x] == '\n')
		color = BLACK;
	else if (map->map[pos_y][pos_x] == '1')
		color = RED;
	else if (map->map[pos_y][pos_x] == '0')
		color = WHITE;
	else if (map->map[pos_y][pos_x] == 'P')
		color = DARK_BLUE;
	else
		color = BLACK;
	return (color);
}

void	ft_draw_minimap(t_map *map, t_minimap *mn, t_img *img)
{
	int	pos_x;
	int	pos_y;
	int	dx;
	int	dy;

	pos_y = -1;
	while (++pos_y < map->max_h)
	{
		pos_x = -1;
		while (++pos_x < map->max_w)
		{
			mn->color = ft_color(map, pos_x, pos_y);
			dy = 0;
			while (dy < mn->scale_y)
			{
				mn->pixel_y = (int)(pos_y * mn->scale_y) + dy++;
				dx = 0;
				while (dx < mn->scale_x)
				{
					mn->pixel_x = (int)(pos_x * mn->scale_x) + dx++;
					mlx_put_pixel(img, mn->pixel_x, mn->pixel_y, mn->color);
				}
			}
		}
	}
}

int	ft_minimap(t_map *map, t_minimap *mini)
{
	mini->mnmap->width = MINIW;
	mini->mnmap->height = MINIH;
	ft_draw_minimap(map, mini, map->img);
	return (0);
}
