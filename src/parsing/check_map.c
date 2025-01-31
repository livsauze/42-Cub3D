#include "../../includes/cub3D.h"

int	ft_check_struct(t_map *map)
{
	if (!map->so || !map->no || !map->ea || !map->we
		|| map->ceiling[0] < 0 || map->floor[0] < 0)
		return (1);
	return (0);
}

t_map	*ft_get_map(t_map *map)
{
	char	*line;

	line = get_next_line(map->fd);
	if (!line)
		return (ft_err("File empty\n", map), map);
	while (line && map->err == 0)
	{
		ft_get_color(map, line);
		ft_get_text(map, line);
		free(line);
		line = get_next_line(map->fd);
	}
	if (ft_check_struct(map) == 1)
		ft_err("The .cub file is not complete\n", map);
	return (map);
}
