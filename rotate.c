/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: najeuneh <najeuneh@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 16:46:54 by najeuneh          #+#    #+#             */
/*   Updated: 2024/05/28 17:33:40 by najeuneh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inc/libft.h"

void	rotate(t_stack *stack)
{
	t_stack	*first;
	t_stack	*last;

	first = stack;
	stack = stack->up->next;
	last = ft_lstlast(stack);
	first->up->next = NULL;
	last->up->next = first;
}

void	ra(t_list *list)
{
	rotate(list);
	printf("ra\n");
}

void	rb(t_list *list)
{
	rotate(list);
	printf("rb\n");
}

void	rr(t_list list1, t_list list2)
{
	rotate(&list1);
	rotate(&list2);
	printf("ra\n");
	printf("rb\n");
}