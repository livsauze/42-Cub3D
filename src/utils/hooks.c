#include "../../includes/cub3D.h"

int	check_key(int *keys)
{
	int	i;

	i = -1;
	while (++i <= 8)
	{
		if (keys[i] == 1)
			return (i);
	}
	return (-1);
}

int	ft_hook(t_map *map)
{
	int	key_pressed;

	key_pressed = check_key(map->key_states);
	if (key_pressed >= 0)
		ft_move(map, map->player, map->key_states);
	ft_draw_bckg(map, map->img);
	ray_casting(map->ray, map->player, map);
	ft_minimap(map, map->mini);
	mlx_put_image_to_window(map->mlx, map->window, map->img->img, 0, 0);
	return (0);
}
