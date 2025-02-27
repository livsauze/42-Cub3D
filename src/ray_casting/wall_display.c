#include "../../includes/cub3D.h"

void	draw_vertical_line(int draw_start, int draw_end, t_map *map, int x)
{
	int	y;

	y = draw_start;
	while (y < draw_end)
	{
		mlx_put_pixel(map->img, x, y, map->color);
		y++;
	}
}

void	wall_dist(t_map *map, t_ray *ray, int x)
{
	int	line_height;
	int	draw_start;
	int	draw_end;

	if (ray->side_wall == 0)
		ray->perp_wall_dist = (map->map_x - map->player->pos_x + (1 - ray->step_x) / 2) / ray->ray_dir_x;
	else
		ray->perp_wall_dist = (map->map_y - map->player->pos_y + (1 - ray->step_y) / 2) / ray->ray_dir_y;
	if (ray->side_wall == 0) // Mur vertical (Est-Ouest)
	{
		if (ray->step_x > 0)
			map->color = WOOD; // Mur Est
		else
			map->color = BEIGE; // Mur Ouest
	}
	else // Mur horizontal (Nord-Sud)
	{
		if (ray->step_y > 0)
			map->color = GREY; // Mur Sud
		else
			map->color = BRICK; // Mur Nord
	}
	line_height = (int)(HEIGHT / ray->perp_wall_dist);
	draw_start = -line_height / 2 + HEIGHT / 2;
	draw_end = line_height / 2 + HEIGHT / 2;
	if (draw_start < 0)
		draw_start = 0;
	if (draw_end >= HEIGHT)
		draw_end = HEIGHT - 1;		
	draw_vertical_line(draw_start, draw_end, map, x);
}

