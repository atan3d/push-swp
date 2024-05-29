/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dl_lstadd_front.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: najeuneh <najeuneh@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/12 14:27:35 by najeuneh          #+#    #+#             */
/*   Updated: 2024/05/29 15:37:26 by najeuneh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/libft.h"

void	dl_lstadd_front(t_stack *a, int nbr)
{
	t_node	*new;

	new = dl_lstnew(nbr);
	if (a->up == NULL)
	{
		a->up = new;
		a->low = new;
	}
	else
	{
		new->next = a->up;
		a->up->prev = new;
		a->up = new;
	}
}