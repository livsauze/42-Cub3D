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
		mlx_put_pixel(map->img, x, y, map->color);
		y++;
	}
}
// pass just in magenta
// void	wall_dist(t_map *map, t_ray *ray, int x)
// {
// 	int	line_height;
// 	int	draw_start; // begin of the vertical line of the wall
// 	int	draw_end; // end of the vertical line of the wall

// 	if (ray->side_wall == 0)
// 	{
// 		ray->perp_wall_dist = fabs(ray->side_dist_x - ray->delta_dist_x);
// 		map->color = CYAN;
// 	}
// 	else if (ray->side_wall == 1)
// 	{
// 		ray->perp_wall_dist = fabs(ray->side_dist_y - ray->delta_dist_y);
// 		map->color = MAGENTA;
// 	}
// 	line_height = (int)(HEIGHT / ray->perp_wall_dist);
// 	draw_start = -line_height / 2 + HEIGHT / 2;
//     draw_end = line_height / 2 + HEIGHT / 2;
// 	if (draw_start < 0)
// 		draw_start = 0;
// 	if (draw_end >= HEIGHT)
// 		draw_end = HEIGHT - 1;
// 	// if (draw_start >= 0 && draw_start < HEIGHT && draw_end >= 0 && draw_end < HEIGHT)
//     draw_vertical_line(draw_start, draw_end, map, x);
// 	// else
//     // 	printf("Erreur : draw_start ou draw_end hors limites\n");	
// }

void	wall_dist(t_map *map, t_ray *ray, int x)
{
	int	line_height;
	int	draw_start;
	int	draw_end;

	if (ray->side_wall == 0)
		ray->perp_wall_dist = (map->map_x - map->player->pos_x + (1 - ray->step_x) / 2) / ray->ray_dir_x;
	else
		ray->perp_wall_dist = (map->map_y - map->player->pos_y + (1 - ray->step_y) / 2) / ray->ray_dir_y;
	printf("Wall impact: map_x = %d, map_y = %d | side_wall = %d | perp_wall_dist = %f\n", 
			map->map_x, map->map_y, ray->side_wall, ray->perp_wall_dist);
	if (ray->side_wall == 0) // Mur vertical (Est-Ouest)
	{
		if (ray->step_x > 0)
			map->color = CYAN; // Mur Est
		else
			map->color = GREEN; // Mur Ouest
	}
	else // Mur horizontal (Nord-Sud)
	{
		if (ray->step_y > 0)
			map->color = MAGENTA; // Mur Sud
		else
			map->color = RED; // Mur Nord
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

