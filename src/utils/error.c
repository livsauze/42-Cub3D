#include "../../includes/cub3D.h"

int	ft_err(char *str)
{
	write(2, "Error\n", 6);
	while (*str)
		write(2, str++, 1);
	return (1);
}

void	ft_free_all(t_map *map)
{
	if (map->so)
		free(map->so);
	if (map->no)
		free(map->no);
	if (map->we)
		free(map->we);
	if (map->ea)
		free(map->ea);
}


void	ft_end(t_map *map)
{
	ft_free_all(map);
	// free(map);
}
