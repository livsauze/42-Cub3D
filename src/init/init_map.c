#include "../../includes/cub3D.h"

t_map	*ft_clean_init(t_map *map)
{
	int	i;

	map->fd = -1;
	map->err = 0;
	map->no = NULL;
	map->so = NULL;
	map->we = NULL;
	map->ea = NULL;
	i = -1;
	while (++i < 3)
	{
		map->ceiling[i] = -1;
		map->floor[i] = -1;
	}
	return (map);
}

t_map	*ft_init_struct(char *file)
{
	t_map	*map;

	map = malloc(sizeof(t_map));
	ft_clean_init(map);
	map->fd = open(file, O_RDONLY);
	if (map->fd < 0)
		return (printf("%s\n", "Error\nCannot open file"), map->err = 2, map);
	ft_get_map(map);
	return (map);
}
