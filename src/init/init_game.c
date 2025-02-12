#include "../../includes/cub3D.h"

void	ft_start_game(t_map *map)
{
	ft_init_mlx(map);
	mlx_loop_hook(map->mlx->mlx, ft_minimap, map);
}


int	ft_init_player(t_map *map, int x, int y, int player)
{
	if (player > 0)
	{
		ft_err("Map : more than one player detected\n", map);
		return (2);
	}
	map->player = malloc(sizeof(t_player));
	map->player->pos_x = x;
	map->player->pos_y = y;
	return (1);
}