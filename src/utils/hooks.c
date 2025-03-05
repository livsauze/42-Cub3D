#include "../../includes/cub3D.h"

int	ft_hook(t_map *map)
{
	ft_move(map, map->player);
	ft_draw_bckg(map, map->img);
	ray_casting(map->ray, map->player, map);
	ft_minimap(map, map->mini);
	mlx_put_image_to_window(map->mlx, map->window, map->img->img, 0, 0);
	return (0);
}
