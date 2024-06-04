/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: najeuneh <najeuneh@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/24 13:29:52 by najeuneh          #+#    #+#             */
/*   Updated: 2024/06/04 15:32:16 by najeuneh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inc/libft.h"

void	push_swap(t_stack *stack)
{
	int	int1;
	int	int2;

	if (stack == NULL || stack->up == NULL)
		return ;
	int1 = stack->up->nbr;
	int2 = stack->up->next->nbr;
	stack->up->nbr = int2;
	stack->up->next->nbr = int1;
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


