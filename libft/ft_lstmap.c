/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmkhize <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/17 03:48:45 by bmkhize           #+#    #+#             */
/*   Updated: 2018/06/18 15:03:40 by bmkhize          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*node;
	t_list	*newl;

	if (!lst || !f)
		return (NULL);
	node = f(lst);
	newl = node;
	while (lst->next)
	{
		lst = lst->next;
		node->next = f(lst);
		if (!node->next)
		{
			free(node->next);
			return (NULL);
		}
		node = node->next;
	}
	return (newl);
}
