#include "../includes/cub3D.h"

void	ft_draw_minimap(t_map *map, t_img *mnmap)
{
	int	pos_x, pos_y, dx, dy, pixel_x, pixel_y, color;
	float scale_x;
	float scale_y;

	scale_x = (float)mnmap->width / map->max_w;
	scale_y = (float)mnmap->height / map->max_h;
	pos_y = -1;
	while (++pos_y < map->max_h)
	{
		pos_x = -1;
		while (++pos_x < map->max_w)
		{
			color = (map->map[pos_y][pos_x] == '1') ? RED :
					(map->map[pos_y][pos_x] == '0') ? WHITE :
					ft_strchr("NSWE", map->map[pos_y][pos_x]) ? GREEN : BLACK;
			dy = 0;
			while (dy < scale_y)
			{
				pixel_y = (int)(pos_y * scale_y) + dy++;
				dx = 0;
				while (dx < scale_x)
				{
					pixel_x = (int)(pos_x * scale_x) + dx++;
					if (pixel_x < mnmap->width && pixel_y < mnmap->height)
						mlx_put_pixel(mnmap, pixel_x, pixel_y, color);
				}
			}
		}
	}
}


int	ft_minimap(t_map *map, t_minimap *mini)
{

	mini->mnmap->width = MINIW;
	mini->mnmap->height = MINIH;
	ft_draw_minimap(map, mini->mnmap);
	return (0);
}
