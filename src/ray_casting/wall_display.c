#include "../../includes/cub3D.h"


void	draw_vertical_line(int	line_height, int draw_start, int draw_end, t_map *map)
{

}

void	wall_dist(t_map *map, t_player *player, t_ray *ray)
{
	int	line_height;
	int	draw_start; // begin of the vertical line of the wall
	int	draw_end; // end of the vertical line of the wall
	int	color; // color of the wall
	if (ray->side = 0)
	{
		ray->per_wall_dist = ray->perp_wall_dist = (map->map_x - map->pos_x + (1 - ray->step_x) / 2) / ray->ray_dir_x;
		color = CYAN;
	}
	else
	{
		ray->per_wall_dist = ray->per_wall_dist = ray->perp_wall_dist = (map->map_y - map->pos_y + (1 - ray->step_y) / 2) / ray->ray_dir_y;
		color = MAGENTA;
	}
	line_height = (int)(SCREEN_HEIGHT / perp_wall_dist);
	draw_start = -line_height / 2 + HEIGHT / 2;
    draw_end = line_height / 2 + HEIGHT / 2;
	if (draw_start < 0)
		draw_start = 0;
	if (draw_end >= HEIGHT)
		draw_end = HEIGHT - 1;
	draw_vertical_line(line_height, draw_start, draw_end, map);
}
