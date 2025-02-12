#include "../../includes/cub3D.h"

void	ft_get_SO(t_map *map, char *line, int i)
{
	if (map->so != NULL)
	{
		map->err = 1;
		ft_err("You have more than 1 declaration of SO\n", map);
		return ;
	}
	while (line[i] && (line[i] == '\t' || line[i] == ' '))
		i++;
	map->so = ft_strdup(line + i);
	// if (open(map->so, O_RDONLY) == -1)
	// 	ft_err("Textures SO : cannot open file\n", map);
}

void	ft_get_NO(t_map *map, char *line, int i)
{
	if (map->no != NULL)
	{
		map->err = 1;
		ft_err("You have more than 1 declaration of NO\n", map);
		return ;
	}
	while (line[i] && (line[i] == '\t' || line[i] == ' '))
		i++;
	map->no = ft_strdup(line + i);
	// if (open(map->no, O_RDONLY) == -1)
	// 	ft_err("Textures NO : cannot open file\n", map);
}

void	ft_get_WE(t_map *map, char *line, int i)
{
	if (map->we != NULL)
	{
		map->err = 1;
		ft_err("You have more than 1 declaration of WE\n", map);
		return ;
	}
	while (line[i] && (line[i] == '\t' || line[i] == ' '))
		i++;
	map->we = ft_strdup(line + i);
	// if (open(map->we, O_RDONLY) == -1)
	// 	ft_err("Textures WE : cannot open file\n", map);
}

void	ft_get_EA(t_map *map, char *line, int i)
{
	if (map->ea != NULL)
	{
		map->err = 1;
		ft_err("You have more than 1 declaration of EA\n", map);
		return ;
	}
	while (line[i] && (line[i] == '\t' || line[i] == ' '))
		i++;
	map->ea = ft_strdup(line + i);
	// if (open(map->ea, O_RDONLY) == -1)
	// 	ft_err("Textures EA : cannot open file\n", map);
}


void	ft_get_text(t_map *map, char *line)
{
	int	i;

	i = 0;
	while (line[i] && (line[i] == '\t' || line[i] == ' '))
		i++;
	while (line[i] && map->err == 0)
	{
		if (ft_strncmp(line + i, "SO", 2) == 0)
			ft_get_SO(map, line, i + 2);
		else if (ft_strncmp(line + i, "NO", 2) == 0)
			ft_get_NO(map, line, i + 2);
		else if (ft_strncmp(line + i, "WE", 2) == 0)
			ft_get_WE(map, line, i + 2);
		else if (ft_strncmp(line + i, "EA", 2) == 0)
			ft_get_EA(map, line, i + 2);
		i++;
	}
}
