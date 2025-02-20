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
	if (map->map[pos_y][pos_x] == '1')
		color = RED;
	else if (map->map[pos_y][pos_x] == '0')
		color = WHITE;
	else if (ft_strchr("NSWE", map->map[pos_y][pos_x]))
		color = GREEN;
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
	ft_draw_minimap(map, mini, mini->mnmap);
	return (0);
}
