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
	// printf("y = %i\n", y);
	while (y < draw_end)
	{
		mlx_put_pixel(map->img, x, y, map->color);
		y++;
	}
}

void	wall_dist(t_map *map, t_ray *ray, int x)
{
	int	line_height;
	int	draw_start; // begin of the vertical line of the wall
	int	draw_end; // end of the vertical line of the wall

	printf("ray_dir_x = %f\n", ray->ray_dir_x);
	printf("ray_dir_y = %f\n", ray->ray_dir_y);
	printf("side_wall = %i\n", ray->side_wall);
	printf("side_dist_x = %f\n", ray->side_dist_x);
	
	



	if (ray->side_wall == 0)
	{
		// ray->perp_wall_dist = ray->side_dist_x - ray->delta_dist_x;
		
		if (fabs(ray->ray_dir_x) < 0.0001)
			ray->perp_wall_dist = INFINITY;
		else
			ray->perp_wall_dist = fabs((map->map_x - map->player->pos_x + (1 - ray->step_x) / 2) / ray->ray_dir_x);
		map->color = CYAN;

	}
	else
	{
		// ray->perp_wall_dist = ray->side_dist_y - ray->delta_dist_y;
		if (fabs(ray->ray_dir_x) < 0.0001)
			ray->perp_wall_dist = INFINITY;
		else
			ray->perp_wall_dist = fabs((map->map_y - map->player->pos_y + (1 - ray->step_y) / 2) / ray->ray_dir_y);
		map->color = MAGENTA;
	}

	if (ray->perp_wall_dist < 0.0001)
		ray->perp_wall_dist = 0.0001;
	printf("perp_wall_dist = %f\n", ray->perp_wall_dist);
	line_height = (int)(HEIGHT / ray->perp_wall_dist);
	draw_start = -line_height / 2 + HEIGHT / 2;
    draw_end = line_height / 2 + HEIGHT / 2;
	printf("line_height = %i\n", line_height);
	printf("draw_start = %i\n", draw_start);
	printf("draw_end = %i\n", draw_end);
	if (draw_start < 0)
		draw_start = 0;
	if (draw_end >= HEIGHT)
		draw_end = HEIGHT - 1;
	if (draw_start >= 0 && draw_start < HEIGHT && draw_end >= 0 && draw_end < HEIGHT)
    	draw_vertical_line(draw_start, draw_end, map, x);
	else
    	printf("Erreur : draw_start ou draw_end hors limites\n");
	// draw_vertical_line(draw_start, draw_end, map, x);
	
}
