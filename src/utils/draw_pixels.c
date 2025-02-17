#include "../../includes/cub3D.h"

void	my_put_pixel(t_img *img, int x, int y, long color)
{
	char	*pixel;

	if (x >= 0 && x < WIDTH && y > 0 && y <= HEIGHT)
	{
		pixel = img->addr + (y * img->line_len + x * (img->bpp / 8));
		*(int *)pixel = color;
	}
}

long	ft_convert_rgb(int r, int g, int b)
{
	return (r * 256 * 256 + g * 256 + b);
}

void	ft_draw_bckg(t_map *map, t_img *bckg)
{
	int	x;
	int	y;
	long	color;

	color = ft_convert_rgb(map->ceiling[0], map->ceiling[1], map->ceiling[2]);
	y = 0;
	while (y < HEIGHT)
	{
		x = 0;
		while (x < WIDTH)
		{
			my_put_pixel(bckg, x, y, color);
			x++;
		}
		y++;
		if (y == HEIGHT / 2)
			color = ft_convert_rgb(map->floor[0], map->floor[1], map->floor[2]);
	}
}