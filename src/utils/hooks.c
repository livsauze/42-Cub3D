#include "../../includes/cub3D.h"

int	ft_hooks(t_map *map)
{
	ft_draw_bckg(map, map->texture->bckg);
	mlx_put_image_to_window(map->mlx, map->window, map->texture->bckg->img, 0, 0);
	return (0);
}