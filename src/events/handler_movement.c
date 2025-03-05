/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handler_movement.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: estepere <estepere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/05 21:54:06 by estepere          #+#    #+#             */
/*   Updated: 2025/03/05 21:55:41 by estepere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3D.h"

int	hit_the_wall(t_map *map, double new_x, double new_y)
{
	double	top;
	double	bottom;
	double	left;
	double	right;

	top = new_y - COLLISION_MARGIN;
	bottom = new_y + COLLISION_MARGIN;
	left = new_x - COLLISION_MARGIN;
	right = new_x + COLLISION_MARGIN;
	if (map->map[(int)top][(int)left] == '1')
		return (1);
	if (map->map[(int)top][(int)right] == '1')
		return (1);
	if (map->map[(int)bottom][(int)left] == '1')
		return (1);
	if (map->map[(int)bottom][(int)right] == '1')
		return (1);
	return (0);
}

void	ft_move(t_map *map, t_player *player, int *keystate)
{
	if (keystate[4] == 1)
		rotation_player(map, player, -ROT_SPEED);
	if (keystate[5] == 1)
		rotation_player(map, player, ROT_SPEED);
	if (keystate[0] == 1)
		front_mov(map, player);
	if (keystate[2] == 1)
		back_mov(map, player);
	if (keystate[1] == 1)
		left_mov(map, player);
	if (keystate[3] == 1)
		right_mov(map, player);
	if (keystate[6] == 1)
		ft_close_handler(map);
	ft_change_mnmap(map->map, map->player);
}
