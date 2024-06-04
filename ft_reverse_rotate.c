/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_reverse_rotate.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: najeuneh <najeuneh@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 15:06:40 by najeuneh          #+#    #+#             */
/*   Updated: 2024/06/04 15:12:11 by najeuneh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inc/libft.h"

void	reverse_rotate(t_stack *stack)
{
	t_node	*tmp;
	t_node	*tmp2;
	
	if (!stack || dl_lstsize(stack) < 2)
	return ;
	tmp = stack->low;
	tmp2 = stack->up;
	stack->low = stack->low->prev;
	stack->low->next = NULL;
	stack->up->prev = tmp;
	tmp->prev = NULL;
	stack->up = tmp;
	stack->up->prev = NULL;
	stack->up->next = tmp2;

}

void	rra(t_stack *a)
{
	reverse_rotate(a);
	ft_printf("rra\n");
}

void	rrb(t_stack *b)
{
	reverse_rotate(b);
	ft_printf("rrb\n");
}

void	rrr(t_stack *a, t_stack *b)
{
	reverse_rotate(a);
	reverse_rotate(b);
	ft_printf("rrr\n");
}
