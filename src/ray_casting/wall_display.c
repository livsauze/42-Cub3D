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
	if (ray->side_wall == 0) // Mur vertical (Est-Ouest)
		return (ray->step_x > 0) ? map->t->wall_ea : map->t->wall_we;
	else // Mur horizontal (Nord-Sud)
		return (ray->step_y > 0) ? map->t->wall_so : map->t->wall_no;
}

void	draw_textured_wall(int draw_start, int draw_end, t_map *map, int x, t_img *texture, int tex_x)
{
	int		y;
	int		tex_y;
	double	step;
	double	tex_pos;

	// Calcule l'échelle pour éviter l'étirement
	step = 1.0 * texture->height / (draw_end - draw_start);
	tex_pos = (draw_start - HEIGHT / 2 + (draw_end - draw_start) / 2) * step;

	y = draw_start;
	while (y < draw_end)
	{
		tex_y = (int)tex_pos & (texture->height - 1); // Empêche les dépassements de texture
		tex_pos += step;

		// Récupérer la couleur du pixel dans la texture
		int color = ((int *)texture->addr)[tex_y * texture->width + tex_x];

		// Dessiner le pixel texturé
		mlx_put_pixel(map->img, x, y, color);
		y++;
	}
}

void	wall_dist(t_map *map, t_ray *ray, int x)
{
	int		line_height;
	int		draw_start;
	int		draw_end;
	double	wall_x;
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
	if (ray->side_wall == 0)
		wall_x = map->player->pos_y + ray->perp_wall_dist * ray->ray_dir_y;
	else
		wall_x = map->player->pos_x + ray->perp_wall_dist * ray->ray_dir_x;
	wall_x -= floor(wall_x); // On garde uniquement la fraction
	int tex_x = (int)(wall_x * (double)texture->width);
	if ((ray->side_wall == 0 && ray->ray_dir_x > 0) || (ray->side_wall == 1 && ray->ray_dir_y < 0))
		tex_x = texture->width - tex_x - 1; // Inverser l'image si nécessaire
	draw_textured_wall(draw_start, draw_end, map, x, texture, tex_x);
}




// void	draw_vertical_line(int draw_start, int draw_end, t_map *map, int x)
// {
// 	int	y;

// 	y = draw_start;
// 	while (y < draw_end)
// 	{
// 		mlx_put_pixel(map->img, x, y, map->color);
// 		y++;
// 	}
// }

// void	wall_dist(t_map *map, t_ray *ray, int x)
// {
// 	int	line_height;
// 	int	draw_start;
// 	int	draw_end;

// 	if (ray->side_wall == 0)
// 		ray->perp_wall_dist = (map->map_x - map->player->pos_x + (1 - ray->step_x) / 2) / ray->ray_dir_x;
// 	else
// 		ray->perp_wall_dist = (map->map_y - map->player->pos_y + (1 - ray->step_y) / 2) / ray->ray_dir_y;
	
// 	if (ray->side_wall == 0) // Mur vertical (Est-Ouest)
// 	{
// 		if (ray->step_x > 0)
// 			map->color = WOOD; // Mur Est
// 		else
// 			map->color = BEIGE; // Mur Ouest
// 	}
// 	else // Mur horizontal (Nord-Sud)
// 	{
// 		if (ray->step_y > 0)
// 			map->color = GREY; // Mur Sud
// 		else
// 			map->color = BRICK; // Mur Nord
// 	}
// 	line_height = (int)(HEIGHT / ray->perp_wall_dist);
// 	draw_start = -line_height / 2 + HEIGHT / 2;
// 	draw_end = line_height / 2 + HEIGHT / 2;
// 	if (draw_start < 0)
// 		draw_start = 0;
// 	if (draw_end >= HEIGHT)
// 		draw_end = HEIGHT - 1;		
// 	draw_vertical_line(draw_start, draw_end, map, x);
// }

