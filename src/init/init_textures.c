#include "../../includes/cub3D.h"

t_img	*ft_convert_img(t_map *map, t_img *img, char *path)
{
	img->img = mlx_xpm_file_to_image(map->mlx, path, &img->x, &img->y);
	if (!img->img)
		ft_err("Texture : invalid texture\n", map);
	img->addr = mlx_get_data_addr(img->img, &img->bpp,
			&img->line_len, &img->endian);
	if (!img->addr)
		ft_err("Mlx\n", map);
	return (img);
}

void	ft_init_textures(t_map *map, t_text *t, t_img *mn)
{
	t->wall_so = ft_convert_img(map, t->wall_so, map->so);
	t->wall_no = ft_convert_img(map, t->wall_no, map->no);
	t->wall_we = ft_convert_img(map, t->wall_we, map->we);
	t->wall_ea = ft_convert_img(map, t->wall_ea, map->ea);
	t->bckg->img = mlx_new_image(map->mlx, WIDTH, HEIGHT);
	t->bckg->addr = mlx_get_data_addr(t->bckg->img, &t->bckg->bpp,
			&t->bckg->line_len, &t->bckg->endian);
	mn->img = mlx_new_image(map->mlx, MINIW, MINIH);
	mn->addr = mlx_get_data_addr(mn->img, &mn->bpp, &mn->line_len, &mn->endian);
}
