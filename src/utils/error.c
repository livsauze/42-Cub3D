/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: livsauze <livsauze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/05 22:37:00 by estepere          #+#    #+#             */
/*   Updated: 2025/03/06 17:47:12 by livsauze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

void	ft_free_img(t_img *img1, t_img *img2)
{
	if (img1)
	{
		if (img1->wall)
			free(img1->wall);
		free(img1);
	}
	if (img2)
	{
		if (img2->wall)
			free(img2->wall);
		free(img2);
	}
}

void	ft_end(t_map *map)
{
	if (map->player)
		free(map->player);
	if (map->ray)
		free(map->ray);
	if (map->t)
	{
		ft_free_img(map->t->wall_no, map->t->wall_so);
		ft_free_img(map->t->wall_ea, map->t->wall_we);
		free(map->t);
	}
	ft_free_all(map);
	close(map->fd);
}
