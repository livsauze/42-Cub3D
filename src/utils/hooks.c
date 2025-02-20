#include "../../includes/cub3D.h"

int	ft_hook(t_map *map)
{
	ft_draw_bckg(map, map->t->bckg);
	ft_minimap(map, map->mini);
	// ray_casting(map->ray, map->player, map, map->img);
	mlx_put_image_to_window(map->mlx, map->window, map->t->bckg->img, 0, 0);
	mlx_put_image_to_window(map->mlx, map->window, map->mini->mnmap->img, 0, 0);
	return (0);
}
