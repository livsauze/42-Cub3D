/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: livsauze <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/08 11:50:52 by livsauze          #+#    #+#             */
/*   Updated: 2023/10/08 12:05:19 by livsauze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	char	*cpy;
	size_t	len;
	size_t	i;

	len = ft_strlen(s);
	cpy = (char *)malloc(len * sizeof(char) + 1);
	i = 0;
	if (cpy == NULL)
		return (NULL);
	else
	{
		while (s[i])
		{
			cpy[i] = s[i];
			i++;
		}
		cpy[i] = '\0';
	}
	return (cpy);
}
