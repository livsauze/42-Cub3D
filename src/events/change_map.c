/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   change_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: estepere <estepere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/05 21:46:28 by estepere          #+#    #+#             */
/*   Updated: 2025/03/05 21:46:29 by estepere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3D.h"

void	ft_change_mnmap(char **map, t_player *player)
{
	int	x;
	int	y;

	y = -1;
	while (map[++y])
	{
		x = -1;
		while (map[y][++x])
		{
			if (map[y][x] == 'P')
				map[y][x] = '0';
			if (x == (int)player->pos_x && y == (int)player->pos_y)
			{
				if (map[(int)player->pos_y][(int)player->pos_x] != '1')
					map[y][x] = 'P';
			}
		}
	}
}
