/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtse <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/28 22:35:01 by dtse              #+#    #+#             */
/*   Updated: 2016/09/28 22:40:00 by dtse             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list		*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*node;
	t_list	*tmp;
	t_list	*first;

	if (!lst)
		return (NULL);
	else
	{
		node = f(lst);
		tmp = ft_lstnew(node->content, node->content_size);
		first = tmp;
		lst = lst->next;
	}
	while (lst)
	{
		node = f(lst);
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = ft_lstnew(node->content, node->content_size);
		lst = lst->next;
	}
	return (first);
}
