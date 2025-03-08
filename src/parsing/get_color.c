/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_color.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: livsauze <livsauze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/05 22:04:59 by estepere          #+#    #+#             */
/*   Updated: 2025/03/06 17:03:28 by livsauze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

int	ft_check_rgb(t_map *map, char **tab, char c)
{
	int	i;
	int	j;

	if (ft_tab_len(tab) != 3)
		return (0);
	i = -1;
	while (tab[++i])
	{
		j = -1;
		while (tab[i][++j])
		{
			if (tab[i][j] != '\n' && !ft_isdigit(tab[i][j]))
				return (0);
		}
		if (ft_atoi(tab[i]) < 0 || ft_atoi(tab[i]) > 255)
			ft_err("RGB color invalid\n", map);
		else
		{
			if (c == 'F')
				map->floor[i] = ft_atoi(tab[i]);
			else
				map->ceiling[i] = ft_atoi(tab[i]);
		}
	}
	return (1);
}

void	ft_get_floor(t_map *map, char *line, int i)
{
	char	**tmp;

	if (map->floor[0] != -1)
	{
		ft_err("You have more than 1 declaration of floor color\n", map);
		return ;
	}
	while (line[i] && (line[i] == '\t' || line[i] == ' '))
		i++;
	tmp = ft_split(line + i, ',');
	if (!ft_check_rgb(map, tmp, 'F'))
	{
		ft_free_tab(tmp);
		ft_err("Color : invalid color\n", map);
		return ;
	}
	ft_free_tab(tmp);
	return ;
}

void	ft_get_ceiling(t_map *map, char *line, int i)
{
	char	**tmp;

	if (map->ceiling[0] != -1)
	{
		ft_err("You have more than 1 declaration of ceiling color\n", map);
		return ;
	}
	while (line[i] && (line[i] == '\t' || line[i] == ' '))
		i++;
	tmp = ft_split(line + i, ',');
	if (!ft_check_rgb(map, tmp, 'C'))
	{
		ft_free_tab(tmp);
		ft_err("Color : invalid color\n", map);
		return ;
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
			ft_get_floor(map, line, i + 1);
		else if (line[i] && line[i] == 'C')
			ft_get_ceiling(map, line, i + 1);
		i++;
	}
	return ;
}
