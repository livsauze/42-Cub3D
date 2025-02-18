#include "../includes/cub3D.h"

void	ft_draw_minimap(t_map *map, t_img *mnmap, int scale)
{
	int	pos_x;
	int	pos_y;

	pos_y = -1;
	while (++pos_y < mnmap->height && map->map[pos_y / scale])
	{
		pos_x = -1;
		while (++pos_x < mnmap->width && map->map[pos_y / scale][pos_x /scale] )
		{
			if (map->map[pos_y / scale][pos_x / scale] == '1')
				mlx_put_pixel(mnmap, pos_x, pos_y, RED);
			else if (map->map[pos_y / scale][pos_x / scale] == '0')
				mlx_put_pixel(mnmap, pos_x, pos_y, WHITE);
			else
				mlx_put_pixel(mnmap, pos_x, pos_y, GREEN);
		}
		mlx_put_image_to_window(map->mlx, map->window, mnmap->img, pos_x, pos_y);
	}
}

int	ft_minimap(t_map *map, t_minimap *mini)
{

	mini->mnmap->width = 300;
	mini->mnmap->height = 150;
	ft_draw_minimap(map, mini->mnmap, 10);
	return (0);
}