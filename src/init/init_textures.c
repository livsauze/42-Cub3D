#include "../../includes/cub3D.h"

t_img	*ft_convert_img(t_map *map, t_img *img, char *path)
{

	img->img = mlx_xpm_file_to_image(map->mlx, path, &img->x, &img->y);
	if (!img->img)
		ft_err("Texture : invalid texture\n", map);
	img->addr = mlx_get_data_addr(img->img, &img->bpp, &img->line_len, &img->endian);
	if (!img->addr)
		ft_err("Mlx\n", map);
	return (img);
}

void	ft_init_textures(t_map *map, t_text *texture)
{
	// texture->wall_so = ft_convert_img(map, texture->wall_so, map->so);
	// texture->wall_no = ft_convert_img(map, texture->wall_no, map->no);
	// texture->wall_we = ft_convert_img(map, texture->wall_we, map->we);
	// texture->wall_ea = ft_convert_img(map, texture->wall_ea, map->ea);
	texture->bckg->img = mlx_new_image(map->mlx, WIDTH, HEIGHT);
	texture->bckg->addr = mlx_get_data_addr(texture->bckg->img, &texture->bckg->bpp, &texture->bckg->line_len, &texture->bckg->endian);
	map->mini->mnmap->img = mlx_new_image(map->mlx, MINIW, MINIH);
	map->mini->mnmap->addr = mlx_get_data_addr(map->mini->mnmap->img, &map->mini->mnmap->bpp, &map->mini->mnmap->line_len, &map->mini->mnmap->endian);
	// ft_draw_bckg(map, texture->bckg);
}
