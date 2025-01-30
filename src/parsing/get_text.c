#include "../../includes/cub3D.h"

void	ft_get_SO(t_map *map, char *line, int i)
{
	while (line[i] && (line[i] == '\t' || line[i] == ' '))
		i++;
	if (ft_strncmp(line + i, "./", 2))
	{
		map->err = 1;
		return ;
	}
	map->so = ft_strdup(line + i);
}

void	ft_get_NO(t_map *map, char *line, int i)
{
	while (line[i] && (line[i] == '\t' || line[i] == ' '))
		i++;
	if (ft_strncmp(line + i, "./", 2))
	{
		map->err = 1;
		return ;
	}
	map->no = ft_strdup(line + i);
}

void	ft_get_WE(t_map *map, char *line, int i)
{
	while (line[i] && (line[i] == '\t' || line[i] == ' '))
		i++;
	if (ft_strncmp(line + i, "./", 2))
	{
		map->err = 1;
		return ;
	}
	map->we = ft_strdup(line + i);
}

void	ft_get_EA(t_map *map, char *line, int i)
{
	while (line[i] && (line[i] == '\t' || line[i] == ' '))
		i++;
	if (ft_strncmp(line + i, "./", 2))
	{
		map->err = 1;
		return ;
	}
	map->ea = ft_strdup(line + i);
}