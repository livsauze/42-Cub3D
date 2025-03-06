/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: livsauze <livsauze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/05 21:44:11 by estepere          #+#    #+#             */
/*   Updated: 2025/03/06 17:07:51 by livsauze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3D.h"

int	main(int ac, char **av)
{
	t_map	*map;

	if (ac != 2)
		return (printf("Error\nBad arguments nb\n"), 1);
	if (ft_check_ext(av[1], "cub") == 1)
		return (printf("Error\nPlease use a .cub extension file\n"), 1);
	map = ft_init_struct(av[1]);
	if (map->err > 0)
		return (ft_end(map), free(map), 1);
	ft_start_game(map);
	if (map->err > 0)
		return (ft_end(map), free(map), 1);
	return (0);
}
