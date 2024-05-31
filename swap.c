/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: najeuneh <najeuneh@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/24 13:29:52 by najeuneh          #+#    #+#             */
/*   Updated: 2024/05/30 16:32:26 by najeuneh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inc/libft.h"

void	push_swap(t_stack *stack)
{
	t_node	*tmp;

	if (stack == NULL || stack->up == NULL)
		return ;
	tmp = stack->up;
	stack->up = tmp->next;
	tmp->next = stack->up->next;
	stack->up->next = tmp;
}

void	sa(t_stack *stack)
{
	push_swap(stack);
	ft_printf("sa\n");
}

void	sb(t_stack *stack)
{
	push_swap(stack);
	ft_printf("sb\n");
}

void	ss(t_stack *a, t_stack *b)
{
	push_swap(a);
	push_swap(b);
	ft_printf("ss\n");
}


