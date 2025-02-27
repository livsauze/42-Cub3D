#include "../../includes/cub3D.h"

void	ft_err(char *str, t_map *map)
{
	map->err = 1;
	write(2, "Error\n", 6);
	while (*str)
		write(2, str++, 1);
}

void	ft_free_all(t_map *map)
{
	if (map->mini)
	{
		free(map->mini->mnmap);
		free(map->mini);
	}
	if (map->img)
		free(map->img);
	if (map->so)
		free(map->so);
	if (map->no)
		free(map->no);
	if (map->we)
		free(map->we);
	if (map->ea)
		free(map->ea);
	if (map->map)
		ft_free_tab(map->map);
}
void	ft_free_img(t_text *texture)
{
	if (texture->wall_no)
		free(texture->wall_no);
	if (texture->wall_so)
		free(texture->wall_so);
	if (texture->wall_we)
		free(texture->wall_we);
	if (texture->wall_ea)
		free(texture->wall_ea);
}

void	ft_end(t_map *map)
{
	ft_free_all(map);
	if (map->player)
		free(map->player);
	if (map->ray)
		free(map->ray);
	if (map->t)
	{
		ft_free_img(map->t);
		free(map->t);
	}
	close(map->fd);
}
