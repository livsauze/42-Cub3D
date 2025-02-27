#include "../../includes/cub3D.h"

void	mlx_put_pixel(t_img *img, int x, int y, int color)
{
	int	offset;

	offset = (y * img->line_len + (x * (img->bpp / 8)));
	*(unsigned int *)(img->addr + offset) = color;
}

long	ft_convert_rgb(int r, int g, int b)
{
	return (r * 256 * 256 + g * 256 + b);
}

void	ft_draw_bckg(t_map *map, t_img *img)
{
	int		x;
	int		y;
	long	color;

	color = ft_convert_rgb(map->ceiling[0], map->ceiling[1], map->ceiling[2]);
	y = 0;
	while (y < HEIGHT)
	{
		x = 0;
		while (x < WIDTH)
		{
			mlx_put_pixel(img, x, y, color);
			x++;
		}
		y++;
		if (y == HEIGHT / 2)
			color = ft_convert_rgb(map->floor[0], map->floor[1], map->floor[2]);
	}
}
