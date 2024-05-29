/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: najeuneh <najeuneh@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/12 15:13:50 by najeuneh          #+#    #+#             */
/*   Updated: 2024/04/15 16:40:06 by najeuneh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new;
	t_list	*node;
	void	*old_list_content;

	if (!lst || !f || !del)
		return (NULL);
	new = NULL;
	while (lst)
	{
		old_list_content = f(lst->content);
		node = ft_lstnew(old_list_content);
		if (!node)
		{
			del(old_list_content);
			ft_lstclear(&new, *del);
			return (NULL);
		}
		ft_lstadd_back(&new, node);
		lst = lst->next;
	}
	return (new);
}
