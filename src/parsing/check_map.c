#include "../../includes/cub3D.h"

void	ft_get_text(t_map *map, char *line)
{
	int	i;

	i = 0;
	if (!line)
		return ;
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

t_map	*ft_get_map(t_map *map)
{
	char	*line;

	line = get_next_line(map->fd);
	if (!line)
		return (map->err = 1, printf("Error\nFile empty\n"), map);
	while (line && map->err == 0)
	{
		ft_get_color(map, line);
		ft_get_text(map, line);
		free(line);
		line = get_next_line(map->fd);
	}
	return (map);
}