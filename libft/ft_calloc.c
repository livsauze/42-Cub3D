/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: livsauze <livsauze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/08 12:33:03 by livsauze          #+#    #+#             */
/*   Updated: 2025/01/23 16:44:31 by livsauze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(int nmemb, int size)
{
	void	*s;
	int	len;

	len = nmemb * size;
	//if ((len / nmemb) != size)
	//return (NULL);
	s = (void *)malloc(len);
	if (s == NULL)
		return (NULL);
	ft_bzero(s, len);
	return ((void *)s);
}
