/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_reverse_rotate.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: najeuneh <najeuneh@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 15:06:40 by najeuneh          #+#    #+#             */
/*   Updated: 2024/05/28 15:35:44 by najeuneh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	reverse_rotate(t_dlist *list)
{
	t_dlist
}

int	main()
{
	int	i;
	t_list *lst;

	lst = NULL;
	i = 1;
	while(i < 5)
	{
		ft_lstadd_back(&lst, ft_lstnew(i));
		i++;
	}
	reverse_rotate(lst);
	while (lst)
	{
		printf("%d\n", lst->content);
		lst = lst->next;
	}
}
