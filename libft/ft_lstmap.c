/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: livsauze <livsauze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 18:40:55 by livsauze          #+#    #+#             */
/*   Updated: 2023/10/25 19:57:39 by livsauze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*newli;
	t_list	*temp;

	if (!lst || !del || !f)
		return (NULL);
	newli = ft_lstnew(f(lst->content));
	if (!newli)
		return (NULL);
	temp = newli;
	lst = lst->next;
	while (lst)
	{
		newli->next = ft_lstnew(f(lst->content));
		if (!newli->next)
		{
			ft_lstclear(&temp, del);
			return (NULL);
		}
		newli = newli->next;
		lst = lst->next;
	}
	newli->next = NULL;
	return (temp);
}
