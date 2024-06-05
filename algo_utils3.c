/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_utils3.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: najeuneh <najeuneh@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/04 18:15:16 by najeuneh          #+#    #+#             */
/*   Updated: 2024/06/05 17:32:16 by najeuneh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inc/libft.h"

void	ft_last_b(t_stack *a, t_stack *b)
{
	t_node	*node_b;

	node_b = b->up;
	if (is_tryed(a) == 1 && b->up == NULL)
		return ;
	ft_median(a);
	ft_bestfriends(a, b);
	algo_a(node_b, a);
	pa(a, b);
	free_all(&b, NULL);
}

void	ft_index(t_stack *stack)
{
	t_node	*node;
	int		i;

	i = 0;
	node = stack->up;
	while (node != NULL)
	{
		node->index = i;
		i++;
		node = node->next;
	}
}

void	ft_a_try2(t_stack *stack, t_stack *b)
{
	t_node	*node;

	node = ft_max_int(stack);
	if (node->index == 0 && is_tryed(stack) == 0)
		ra(stack);
	node = ft_max_int(stack);
	if (node->index == 1 && is_tryed(stack) == 0)
		rra(stack);
	if (stack->up->nbr > stack->up->next->nbr)
		sa(stack);
	while (dl_lstsize(stack) < 5 && b->up != NULL)
	{
		pa(stack, b);
	}
}
