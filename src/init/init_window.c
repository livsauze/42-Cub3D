/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_window.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: estepere <estepere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/05 22:02:32 by estepere          #+#    #+#             */
/*   Updated: 2025/03/05 22:02:33 by estepere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

void	ft_malloc_error(void)
{
	perror("malloc problems");
	exit(EXIT_FAILURE);
}

void	ft_window_init(t_map *map)
{
	map->mlx = mlx_init();
	if (map->mlx == NULL)
		ft_malloc_error();
	map->window = mlx_new_window(map->mlx, WIDTH, HEIGHT, "CUB3D");
	if (map->window == NULL)
	{
		mlx_destroy_display(map->mlx);
		free(map->mlx);
		ft_malloc_error();
	}
	map->img->img = mlx_new_image(map->mlx, WIDTH, HEIGHT);
	map->img->addr = mlx_get_data_addr(map->img->img, &map->img->bpp,
			&map->img->line_len, &map->img->endian);
}
