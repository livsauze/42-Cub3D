#include "../includes/cub3D.h"

void	ft_draw_minimap(t_map *map, t_img *mnmap)
{
	int	pos_x;
	int	pos_y;

	pos_y = -1;
	while (++pos_y < mnmap->height)
	{
		pos_x = -1;
		while (++pos_x < mnmap->width)
		{
			if (map->map[pos_y][pos_x] == '1')
				my_put_pixel(mnmap, pos_x, pos_y, RED);
			else if (map->map[pos_y][pos_x] == '0')
				my_put_pixel(mnmap, pos_x, pos_y, WHITE);
			else
				my_put_pixel(mnmap, pos_x, pos_y, BLACK);
		}
		mlx_put_image_to_window(map->mlx, map->window, mnmap->img, pos_x, pos_y);
	}
}

int	ft_minimap(t_map *map)
{
	t_img mnmap;

	mnmap.width = 300;
	mnmap.height = 150;
	mnmap.img = mlx_new_image(map->mlx, mnmap.width, mnmap.height);
	mnmap.addr = mlx_get_data_addr(mnmap.img, &mnmap.bpp, &mnmap.line_len, &mnmap.endian);
	ft_draw_minimap(map, &mnmap);
	return (0);
}