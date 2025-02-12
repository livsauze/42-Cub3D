#include "../../includes/cub3D.h"
#include "../../includes/cub3D.h"

int	ft_map_unclosed(t_map *map, int x, int y)
{
	int	nb_rows;

	nb_rows = ft_tab_len(map->map);
	if (x == 0 || y == 0)
		return (1);
	else if (y == (nb_rows -1) || x == (ft_strlen(map->map[y]) - 1))
		return (1);
	else if (!map->map[y][x - 1] || !map->map[y][x + 1]
			|| map->map[y][x - 1] == ' ' || map->map[y][x + 1] == ' ')
		return (1);
	else if (!map->map[y - 1][x] || !map->map[y + 1][x]
		|| map->map[y - 1][x] == ' ' || map->map[y + 1][x] == ' ')
		return (1);
	else if (!map->map[y - 1][x - 1] || !map->map[y + 1][x - 1]
			|| map->map[y - 1][x - 1] == ' ' || map->map[y + 1][x - 1] == ' ')
		return (1);
	else if ((!map->map[y - 1][x + 1] || !map->map[y + 1][x + 1])
			|| (map->map[y - 1][x + 1] == ' ' || map->map[y + 1][x + 1] == ' '))
		return (1);
	return (0);
}
