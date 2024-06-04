/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: najeuneh <najeuneh@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 16:46:54 by najeuneh          #+#    #+#             */
/*   Updated: 2024/06/04 16:41:05 by najeuneh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inc/libft.h"

void	rotate(t_stack *stack)
{
	t_node	*tmp;
	t_node	*tmp2;

	if (!stack || dl_lstsize(stack) < 2)
		return ;
	tmp = stack->up;
	tmp2 = stack->low;
	stack->up = stack->up->next;
	stack->up->prev = NULL;
	stack->low->next = tmp;
	stack->low = tmp;
	stack->low->prev = tmp2;
	stack->low->next = NULL;
}

void	ra(t_stack *a)
{
	rotate(a);
	ft_printf("ra\n");
}

void	rb(t_stack *b)
{
	rotate(b);
	ft_printf("rb\n");
}

void	rr(t_stack *a, t_stack *b)
{
	rotate(a);
	rotate(b);
	ft_printf("rr\n");
}
