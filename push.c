/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: najeuneh <najeuneh@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 15:01:46 by najeuneh          #+#    #+#             */
/*   Updated: 2024/06/05 13:06:02 by najeuneh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inc/libft.h"

void	push(t_stack *giver, t_stack *reciever, t_node *tmp, t_node *tmp2)
{
	if (!giver->up)
		return ;
	tmp = giver->up->next;
	giver->up->next = NULL;
	if (!reciever->up)
	{
		reciever->up = giver->up;
		reciever->low = giver->up;
	}
	else
	{
		tmp2 = reciever->up;
		reciever->up = giver->up;
		reciever->up->next = tmp2;
		tmp2->prev = reciever->up;
	}
	giver->up->prev = NULL;
	giver->up = tmp;
}

void	pa(t_stack *a, t_stack *b)
{
	push(b, a, NULL, NULL);
	ft_printf("pa\n");
}

void	pb(t_stack *a, t_stack *b)
{
	push(a, b, NULL, NULL);
	ft_printf("pb\n");
}
