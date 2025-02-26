#include "../../includes/cub3D.h"

void	ft_get_so(t_map *map, char *line, int i)
{
	if (map->so != NULL)
	{
		map->err = 1;
		ft_err("You have more than 1 declaration of SO\n", map);
		return ;
	}
	while (line[i] && (line[i] == '\t' || line[i] == ' '))
		i++;
	map->so = ft_substr(line, i, ft_strlen(line + i) - 1);
	if (open(map->so, O_RDONLY) == -1)
		ft_err("Textures SO : cannot open file\n", map);
}

void	ft_get_no(t_map *map, char *line, int i)
{
	if (map->no != NULL)
	{
		map->err = 1;
		ft_err("You have more than 1 declaration of NO\n", map);
		return ;
	}
	while (line[i] && (line[i] == '\t' || line[i] == ' '))
		i++;
	map->no = ft_substr(line, i, ft_strlen(line + i) - 1);
	if (open(map->no, O_RDONLY) == -1)
		ft_err("Textures NO : cannot open file\n", map);
}

void	ft_get_we(t_map *map, char *line, int i)
{
	if (map->we != NULL)
	{
		map->err = 1;
		ft_err("You have more than 1 declaration of WE\n", map);
		return ;
	}
	while (line[i] && (line[i] == '\t' || line[i] == ' '))
		i++;
	map->we = ft_substr(line, i, ft_strlen(line + i) - 1);
	if (open(map->we, O_RDONLY) == -1)
		ft_err("Textures WE : cannot open file\n", map);
}

void	ft_get_ea(t_map *map, char *line, int i)
{
	if (map->ea != NULL)
	{
		map->err = 1;
		ft_err("You have more than 1 declaration of EA\n", map);
		return ;
	}
	while (line[i] && (line[i] == '\t' || line[i] == ' '))
		i++;
	map->ea = ft_substr(line, i, ft_strlen(line + i) - 1);
	if (open(map->ea, O_RDONLY) == -1)
		ft_err("Textures EA : cannot open file\n", map);
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
			ft_get_so(map, line, i + 2);
		else if (ft_strncmp(line + i, "NO", 2) == 0)
			ft_get_no(map, line, i + 2);
		else if (ft_strncmp(line + i, "WE", 2) == 0)
			ft_get_we(map, line, i + 2);
		else if (ft_strncmp(line + i, "EA", 2) == 0)
			ft_get_ea(map, line, i + 2);
		i++;
	}
}
