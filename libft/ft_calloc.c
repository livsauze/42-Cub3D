/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: livsauze <livsauze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/08 12:33:03 by livsauze          #+#    #+#             */
/*   Updated: 2024/11/05 13:56:43 by livsauze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*s;
	size_t	len;

	len = nmemb * size;
	//if ((len / nmemb) != size)
	//return (NULL);
	s = (void *)malloc(len);
	if (s == NULL)
		return (NULL);
	ft_bzero(s, len);
	return ((void *)s);
}
