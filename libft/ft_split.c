/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: livsauze <livsauze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 09:32:21 by livsauze          #+#    #+#             */
/*   Updated: 2025/03/05 17:57:30 by livsauze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_countwords(char const *str, char c)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (str[i])
	{
		while (str[i] && str[i] == c)
			i++;
		if (str[i])
			count++;
		while (str[i] && str[i] != c)
			i++;
	}
	return (count);
}

int	ft_lenwords(char const *str, int c)
{
	int	i;

	i = 0;
	while (str[i] && str[i] != c)
		i++;
	return (i);
}

char	**ft_free(char **str, int j)
{
	while (j >= 0)
	{
		free(str[j]);
		j--;
	}
	free(str);
	str = NULL;
	return (str);
}

char	**ft_split(char const *s, char c)
{
	char	**str;
	int		j;
	int		i;

	if (!s)
		return (NULL);
	i = 0;
	str = (char **)ft_calloc(sizeof(char *), (ft_countwords(s, c) + 1));
	if (!str)
		return (NULL);
	j = 0;
	while (s[i])
	{
		if (s[i] != c)
		{
			str[j] = ft_substr(s, i, ft_lenwords(s + i, c));
			if (!str[j])
				return (ft_free(str, j - 1));
			i = i + ft_lenwords(&s[i], c);
			j++;
		}
		else
			i++;
	}
	return (str);
}
