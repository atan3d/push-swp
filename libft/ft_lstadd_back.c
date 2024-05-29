/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: najeuneh <najeuneh@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/12 14:48:09 by najeuneh          #+#    #+#             */
/*   Updated: 2024/05/28 17:27:29 by najeuneh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/libft.h"

void ft_lstadd_back(t_list **lst, t_list *new)
{
	if (!lst)
		return ;
	else if ((*lst) == NULL)
	{
		*lst = new;
		return ;
	}
	ft_lstlast(*lst)->next = new;
	return ;
}