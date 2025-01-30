#include "../../includes/cub3D.h"

void	ft_get_F(t_map *map, char *line, int i)
{
	char	**tmp;
	int		j;

	while (line[i] && (line[i] == '\t' || line[i] == ' '))
		i++;
	if (!line[i])
	{
		map->err = 1;
		return ;
	}
	tmp = ft_split(line + i + 1, ',');
	j = -1;
	while (++j < 3)
		map->floor[j] = ft_atoi(tmp[j]);
	ft_free_tab(tmp);
	return ;
}

void	ft_get_C(t_map *map, char *line, int i)
{
	char	**tmp;
	int		j;

	while (line[i] && (line[i] == '\t' || line[i] == ' '))
		i++;
	if (!line[i])
	{
		map->err = 1;
		return ;
	}
	tmp = ft_split(line + i + 1, ',');
	j = -1;
	while (++j < 3)
		map->ceiling[j] = ft_atoi(tmp[j]);
	ft_free_tab(tmp);
	return ;
}

void	ft_get_color(t_map *map, char *line)
{
	int	i;

	i = 0;
	if (!line)
		return ;
	while (line[i] && (line[i] == '\t' || line[i] == ' '))
		i++;
	while (line[i] && map->err == 0)
	{
		if (line[i] && line[i] == 'F')
			ft_get_F(map, line, i);
		else if (line[i] && line[i] == 'C')
			ft_get_C(map, line, i);
		i++;
	}
	return ;
}
