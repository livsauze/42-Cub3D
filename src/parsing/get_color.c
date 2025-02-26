#include "../../includes/cub3D.h"

void	ft_get_floor(t_map *map, char *line, int i)
{
	char	**tmp;
	int		j;

	if (map->floor[0] != -1)
	{
		ft_err("You have more than 1 declaration of floor color\n", map);
		return ;
	}
	while (line[i] && (line[i] == '\t' || line[i] == ' '))
		i++;
	tmp = ft_split(line + i + 1, ',');
	j = -1;
	while (++j < 3)
	{
		if (ft_atoi(tmp[j]) < 0 || ft_atoi(tmp[j]) > 255)
			ft_err("RGB color invalid\n", map);
		map->floor[j] = ft_atoi(tmp[j]);
	}
	ft_free_tab(tmp);
	return ;
}

void	ft_get_ceiling(t_map *map, char *line, int i)
{
	char	**tmp;
	int		j;

	if (map->ceiling[0] != -1)
	{
		ft_err("You have more than 1 declaration of ceiling color\n", map);
		return ;
	}
	while (line[i] && (line[i] == '\t' || line[i] == ' '))
		i++;
	tmp = ft_split(line + i + 1, ',');
	j = -1;
	while (++j < 3)
	{
		if (ft_atoi(tmp[j]) < 0 || ft_atoi(tmp[j]) > 255)
			ft_err("RGB color invalid\n", map);
		map->ceiling[j] = ft_atoi(tmp[j]);
	}
	ft_free_tab(tmp);
	return ;
}

void	ft_get_color(t_map *map, char *line)
{
	int	i;

	i = 0;
	while (line[i] && (line[i] == '\t' || line[i] == ' '))
		i++;
	while (line[i] && map->err == 0)
	{
		if (line[i] && line[i] == 'F')
			ft_get_floor(map, line, i);
		else if (line[i] && line[i] == 'C')
			ft_get_ceiling(map, line, i);
		i++;
	}
	return ;
}
