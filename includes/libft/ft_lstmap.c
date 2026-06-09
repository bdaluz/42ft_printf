/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bda-luz- <bda-luz-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/29 15:18:55 by bda-luz-          #+#    #+#             */
/*   Updated: 2026/06/03 13:04:56 by bda-luz-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static t_list	*ft_lstfree_null(t_list **lst, void (*del)(void *))
{
	ft_lstclear(lst, del);
	return (NULL);
}

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	dummy;
	t_list	*tail;
	t_list	*new_node;
	void	*content;

	if (!lst || !f || !del)
		return (NULL);
	dummy.next = NULL;
	tail = &dummy;
	while (lst)
	{
		content = (*f)(lst->content);
		if (!content)
			return (ft_lstfree_null(&dummy.next, del));
		new_node = ft_lstnew(content);
		if (!new_node)
		{
			(*del)(content);
			return (ft_lstfree_null(&dummy.next, del));
		}
		tail->next = new_node;
		tail = new_node;
		lst = lst->next;
	}
	return (dummy.next);
}
