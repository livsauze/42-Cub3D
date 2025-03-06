/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: estepere <estepere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/05 22:37:15 by estepere          #+#    #+#             */
/*   Updated: 2025/03/05 22:38:05 by estepere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

void	ft_free_tab(char **str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		free(str[i]);
		i++;
	}
	free(str);
}

int	ft_empty_line(char *str)
{
	int	i;

	i = 0;
	while (str[i] && (str[i] == '\t' || str[i] == ' '))
		i++;
	if (str[i] != '\n')
		return (0);
	return (1);
}

int	ft_tab_len(char **str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int	len_map_width(char **map)
{
	int	max_width;
	int	i;
	int	len;

	max_width = 0;
	i = 0;
	while (map[i])
	{
		len = ft_strlen(map[i]);
		if (len > max_width)
			max_width = len;
		i++;
	}
	return (max_width);
}

int	convert_key(int key)
{
	if (key == UP)
		return (0);
	else if (key == LEFT)
		return (1);
	else if (key == DOWN)
		return (2);
	else if (key == RIGHT)
		return (3);
	else if (key == XK_Left)
		return (4);
	else if (key == XK_Right)
		return (5);
	else if (key == XK_Escape)
		return (6);
	return (-1);
}
