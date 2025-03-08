/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_ext.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: livsauze <livsauze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/05 22:04:27 by estepere          #+#    #+#             */
/*   Updated: 2025/03/06 17:52:40 by livsauze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

int	ft_check_ext(char *file, char *str)
{
	char	**tab;

	if (!file)
		return (1);
	tab = ft_split(file, '.');
	if (!tab[1] || ft_strncmp(tab[1], str, ft_strlen(tab[1])))
		return (ft_free_tab(tab), 1);
	ft_free_tab(tab);
	return (0);
}
