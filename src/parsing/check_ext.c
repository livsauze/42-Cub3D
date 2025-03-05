/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_ext.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: estepere <estepere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/05 22:04:27 by estepere          #+#    #+#             */
/*   Updated: 2025/03/05 22:04:28 by estepere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

int	ft_check_ext(char *file)
{
	char	**tab;

	tab = ft_split(file, '.');
	if (!tab[1] || ft_strncmp(tab[1], "cub", 3))
		return (ft_free_tab(tab), 1);
	ft_free_tab(tab);
	return (0);
}
