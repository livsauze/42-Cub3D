/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: estepere <estepere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/05 21:47:05 by estepere          #+#    #+#             */
/*   Updated: 2025/03/05 21:47:36 by estepere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3D.h"

void	ft_destroy_img(t_map *map, t_text *texture)
{
	(void)texture;
	if (map->img->img)
		mlx_destroy_image(map->mlx, map->img->img);
	if (map->mini->mnmap)
		mlx_destroy_image(map->mlx, map->mini->mnmap->img);
}

int	ft_close_handler(t_map *map)
{
	ft_destroy_img(map, map->t);
	ft_end(map);
	if (map->window)
		mlx_destroy_window(map->mlx, map->window);
	if (map->mlx)
	{
		mlx_loop_end(map->mlx);
		mlx_destroy_display(map->mlx);
		free(map->mlx);
	}
	free(map);
	exit(EXIT_SUCCESS);
	return (0);
}

int	key_press(int keycode, t_map *map)
{
	int	key;

	key = convert_key(keycode);
	if (key >= 0)
		map->key_states[key] = 1;
	return (0);
}

int	key_release(int keycode, t_map *map)
{
	int	key;

	key = convert_key(keycode);
	if (key >= 0)
		map->key_states[key] = 0;
	return (0);
}

void	ft_events_init(t_map *map)
{
	mlx_hook(map->window, KeyPress, KeyPressMask, key_press, map);
	mlx_hook(map->window, KeyRelease, KeyReleaseMask, key_release, map);
	mlx_hook(map->window, 17, (1L << 17), ft_close_handler, map);
}
