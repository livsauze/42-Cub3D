#include "../includes/cub3D.h"

char	ft_dir_p(t_player *player)
{
	if (player->dir_x == 0.0 && player->dir_y == 1.0)
		return ('N');
	else if (player->dir_x == 0.0 && player->dir_y == -1.0)
		return ('S');
	else if (player->dir_x == -1.0 && player->dir_y == 0.0)
		return ('W');
	else if (player->dir_x == 1.0 && player->dir_y == 0.0)
		return ('E');
	return (0);
}

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
			if (ft_strchr("NSWE", map[y][x]))
				map[y][x] = '0';
			if (x == player->pos_x && y == player->pos_y)
				map[y][x] = ft_dir_p(player);
		}
	}
}

int	ft_check_wall(char **map, t_player *player, int key)
{
	if (key == 119)
	{
		if (map[(int)player->pos_y - 1][(int)player->pos_x] == '1')
			return (1);
	}
	else if (key == 97)
	{
		if (map[(int)player->pos_y][(int)player->pos_x - 1] == '1')
			return (1);
	}
	else if (key == 115)
	{
		if (map[(int)player->pos_y + 1][(int)player->pos_x] == '1')
			return (1);
	}
	else if (key == 100)
	{
		if (map[(int)player->pos_y][(int)player->pos_x + 1] == '1')
			return (1);
	}
	return (0);
}