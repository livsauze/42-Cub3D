#include "../../includes/cub3D.h"

int	ft_ismap(char *line)
{
	int	i;

	i = 0;
	if (line[i] == '\n')
		return (0);
	while (line[i] && (line[i] == '\t' || line[i] == ' '))
		i++;
	if (line[i] == '1')
		return (1);
	return (0);
}

void	ft_check_map(t_map *map)
{
	int	x;
	int	y;
	int	player;

	player = 0;
	y = 0;
	while (map->map[y] && map->err == 0)
	{
		x = 0;
		while (map->map[y][x] && map->err == 0)
		{
			if (ft_strrchr("NSEW", map->map[y][x]))
				player = ft_init_player(map, x, y, player);
			else if (!ft_strrchr("NSEW01 ", map->map[y][x]))
				ft_err("Map : invalid character detected\n", map);
			else if (map->map[y][x] == '0' && ft_map_unclosed(map, x, y))
				ft_err("Map : unclosed map\n", map);
			x++;
		}
		y++;
	}
	if (!player && map->err == 0)
		ft_err("Map : Need a player, please use N, S, E or W\n", map);
	return ;
}

void	ft_parse_map(t_map *map, char *line)
{
	char *tmp;

	tmp = ft_strdup(line);
	while (line)
	{
		if (ft_empty_line(line))
		{
			free(tmp);
			free(line);
			ft_err("Map incorrect\n", map);
			return ;
		}
		tmp = ft_strjoin(tmp, line);
		free(line);
		line = get_next_line(map->fd);
	}
	map->map = ft_split(tmp, '\n');
	free(tmp);
	free(line);
	ft_check_map(map);
}

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
	while (line && map->err == 0 && !ft_ismap(line))
	{
		ft_get_color(map, line);
		ft_get_text(map, line);
		free(line);
		line = get_next_line(map->fd);
	}
	if (map->err > 0)
		return (map);
	else if (ft_check_struct(map) == 1)
		ft_err("The .cub file is not complete\n", map);
	ft_parse_map(map, line);
	return (map);
}
