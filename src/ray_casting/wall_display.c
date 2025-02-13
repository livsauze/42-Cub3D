#include "../../includes/cub3D.h"


void	mlx_put_pixel(t_img *img, int x, int y, int color)
{
	int	offset;

	offset = (y * img->line_len + (x * (img->bits_per_pixel / 8)));
	*(unsigned int *)(img->addr + offset) = color;
}

void	draw_vertical_line(int draw_start, int draw_end, t_map *map, int x)
{
	int	y;

	y = draw_start;
	while (y < draw_end)
	{
		mlx_put_pixel(map->mlx, x, y, map->color);
		y++;
	}
}

void	wall_dist(t_map *map, t_player *player, t_ray *ray, int x)
{
	int	line_height;
	int	draw_start; // begin of the vertical line of the wall
	int	draw_end; // end of the vertical line of the wall

	if (ray->side_wall == 0)
	{
		ray->perp_wall_dist = (map->map_x - player->pos_x + (1 - ray->step_x) / 2) / ray->ray_dir_x;
		map->color = CYAN;
	}
	else
	{
		ray->perp_wall_dist = (map->map_y - player->pos_y + (1 - ray->step_y) / 2) / ray->ray_dir_y;
		map->color = MAGENTA;
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
