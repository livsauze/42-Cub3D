#include "../includes/cub3D.h"

void	ft_change_mnmap(char **map, t_player *player)
{
	int	x;
	int	y;

	y = -1;
	while (map[++y])
	{
		x = -1;
		while (map[y][++x])
		{
			if (map[y][x] == 'P')
				map[y][x] = '0';
			if (x == (int)player->pos_x && y == (int)player->pos_y)
			{
				if (map[(int)player->pos_y][(int)player->pos_x] != '1')
					map[y][x] = 'P';
			}
		}
	}
}
