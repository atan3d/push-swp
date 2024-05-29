/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dl_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: najeuneh <najeuneh@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/12 14:48:09 by najeuneh          #+#    #+#             */
/*   Updated: 2024/05/28 18:24:29 by najeuneh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/libft.h"

void	dl_lstadd_back(t_stack *a, int nbr)
{
	t_node	*new;

	new = dl_lstnew(nbr);
	if (!new || !a)
		return ;
	new->next = a->low;
	a->low->prev = new;
	a->low = new;
}