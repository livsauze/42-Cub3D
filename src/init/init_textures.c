#include "../../includes/cub3D.h"

void	ft_store_t_pixels(t_img *img, int *wall)
{
	int	x;
	int	y;
	int	index;

	y = -1;
	while (++y < img->height)
	{
		x = -1;
		while (++x < img->width)
		{
			index = img->width * y + x;
			wall[index] = *(int *)(img->addr + (y * img->line_len + x * (img->bpp / 8)));
		}
	}
}

t_img	*ft_convert_img(t_map *map, t_img *img, char *path)
{
	img->img = mlx_xpm_file_to_image(map->mlx, path, &img->width, &img->height);
	if (!img->img)
		ft_err("Texture : invalid texture\n", map);
	img->addr = mlx_get_data_addr(img->img, &img->bpp,
			&img->line_len, &img->endian);
	if (!img->addr)
		ft_err("Mlx\n", map);
	img->wall = (int *)malloc(sizeof(int) * img->width * img->height);
	ft_store_t_pixels(img, img->wall);
	mlx_destroy_image(map->mlx, img->img);
	return (img);
}

void	ft_init_textures(t_map *map, t_text *t, t_img *mn)
{
	t->wall_so = ft_convert_img(map, t->wall_so, map->so);
	t->wall_no = ft_convert_img(map, t->wall_no, map->no);
	t->wall_we = ft_convert_img(map, t->wall_we, map->we);
	t->wall_ea = ft_convert_img(map, t->wall_ea, map->ea);
	mn->img = mlx_new_image(map->mlx, MINIW, MINIH);
	mn->addr = mlx_get_data_addr(mn->img, &mn->bpp, &mn->line_len, &mn->endian);
}
