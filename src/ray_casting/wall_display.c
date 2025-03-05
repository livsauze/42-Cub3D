/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wall_display.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: estepere <estepere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/05 22:10:52 by estepere          #+#    #+#             */
/*   Updated: 2025/03/05 22:35:52 by estepere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

void	ft_calc_perp(t_map *map, t_ray *ray)
{
	if (ray->side_wall == 0)
		ray->perp_w_d = (map->map_x - map->player->pos_x
				+ (1 - ray->step_x) / 2) / ray->ray_dir_x;
	else
		ray->perp_w_d = (map->map_y - map->player->pos_y
				+ (1 - ray->step_y) / 2) / ray->ray_dir_y;
}

t_img	*get_texture(t_map *map, t_ray *ray)
{
	if (ray->side_wall == 0)
	{
		if (ray->step_x > 0)
			return (map->t->wall_ea);
		else
			return (map->t->wall_we);
	}
	else
	{
		if (ray->step_y > 0)
			return (map->t->wall_so);
		else
			return (map->t->wall_no);
	}
}

void	draw_textured_wall(int draw_start, int draw_end, t_map *map, int x)
{
	int		y;
	int		d;
	int		tex_x;
	int		tex_y;
	double	wall_x;

	if (map->ray->side_wall == 0)
		wall_x = map->player->pos_y + map->ray->perp_w_d * map->ray->ray_dir_y;
	else
		wall_x = map->player->pos_x + map->ray->perp_w_d * map->ray->ray_dir_x;
	wall_x -= floor(wall_x);
	map->cur_t = get_texture(map, map->ray);
	tex_x = (int)(wall_x * (double)map->cur_t->width);
	y = draw_start;
	while (y < draw_end)
	{
		d = y * 256 - HEIGHT * 128 + map->ray->line_h * 128;
		tex_y = ((d * map->cur_t->height) / map->ray->line_h) / 256;
		map->color = map->cur_t->wall[tex_y * map->cur_t->width + tex_x];
		mlx_put_pixel(map->img, x, y, map->color);
		y++;
	}
}

void	wall_dist(t_map *map, t_ray *ray, int x)
{
	int		line_height;
	int		draw_start;
	int		draw_end;

	ft_calc_perp(map, ray);
	line_height = (int)(HEIGHT / ray->perp_w_d);
	draw_start = -line_height / 2 + HEIGHT / 2;
	draw_end = line_height / 2 + HEIGHT / 2;
	if (draw_start < 0)
		draw_start = 0;
	if (draw_end >= HEIGHT)
		draw_end = HEIGHT - 1;
	ray->line_h = line_height;
	draw_textured_wall(draw_start, draw_end, map, x);
}
