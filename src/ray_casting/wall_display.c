#include "../../includes/cub3D.h"

void	ft_calc_perp(t_map *map, t_ray *ray)
{
	if (ray->side_wall == 0)
		ray->perp_wall_dist = (map->map_x - map->player->pos_x + (1 - ray->step_x) / 2) / ray->ray_dir_x;
	else
		ray->perp_wall_dist = (map->map_y - map->player->pos_y + (1 - ray->step_y) / 2) / ray->ray_dir_y;
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

void	draw_textured_wall(int draw_start, int draw_end, t_map *map, int x, t_img *texture)
{
	int		y;
	int		d;
	int		tex_x;
	int		tex_y;
	double	wall_x;
	
	if (map->ray->side_wall == 0)
        wall_x = map->player->pos_y + map->ray->perp_wall_dist * map->ray->ray_dir_y;
    else
        wall_x = map->player->pos_x + map->ray->perp_wall_dist * map->ray->ray_dir_x;
    wall_x -= floor(wall_x);
    tex_x = (int)(wall_x * (double)texture->width);
	y = draw_start;
	while (y < draw_end)
	{
		d = y * 256 - HEIGHT * 128 + map->ray->line_height * 128;
        tex_y = ((d * texture->height) / map->ray->line_height) / 256;
		map->color = ((int *)texture->addr)[tex_y * texture->width + tex_x];
		mlx_put_pixel(map->img, x, y, map->color);
		y++;
	}
}

void	wall_dist(t_map *map, t_ray *ray, int x)
{
	int		line_height;
	int		draw_start;
	int		draw_end;
	t_img	*texture;

	ft_calc_perp(map, ray);
	line_height = (int)(HEIGHT / ray->perp_wall_dist);
	draw_start = -line_height / 2 + HEIGHT / 2;
	draw_end = line_height / 2 + HEIGHT / 2;
	if (draw_start < 0)
		draw_start = 0;
	if (draw_end >= HEIGHT)
		draw_end = HEIGHT - 1;
	texture = get_texture(map, ray);
	ray->line_height = line_height;
	draw_textured_wall(draw_start, draw_end, map, x, texture);
}
