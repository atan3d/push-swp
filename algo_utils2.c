/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_utils2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: najeuneh <najeuneh@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/04 18:13:24 by najeuneh          #+#    #+#             */
/*   Updated: 2024/06/05 14:51:46 by najeuneh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inc/libft.h"

void	ft_min_cost(t_stack *stack, t_stack *b)
{
	t_node	*node_a;
	t_node	*node_b;
	t_node	*tmp;

	node_a = stack->up;
	node_b = b->up;
	while (node_b != NULL)
	{
		node_b->cost2 = node_b->best->cost + node_b->cost;
		node_b = node_b->next;
	}
	node_b = b->up;
	tmp = node_b;
	while (node_b != NULL)
	{
		node_b->bool = 0;
		if (tmp->cost2 >= node_b->cost2)
		{
			tmp->bool = 0;
			node_b->bool = 1;
			tmp = node_b;
		}
		node_b = node_b->next;
	}
}

void	ft_a_try(t_stack *stack, t_stack *b, t_node *node)
{
	stack->median = ft_median(stack);
	while (dl_lstsize(stack) > 3 && is_tryed(stack) == 0)
	{
		node = ft_min_int(stack);
		if (node->index < stack->median)
		{
			while (node->index-- > 0)
				ra(stack);
			pb(stack, b);
		}
		else
		{
			while (node->index++ < dl_lstsize(stack))
				rra(stack);
			pb(stack, b);
		}
	}
	node = ft_min_int(stack);
	if (dl_lstsize(stack) > 3 && is_tryed(stack) == 0)
	{
		while (node->index-- != 0)
			ra(stack);
	}
	ft_a_try2(stack, b);
}

t_node	*ft_min_int(t_stack *stack)
{
	t_node	*smal;
	t_node	*node;
	int		min;

	ft_median(stack);
	node = stack->up;
	min = node->nbr;
	smal = node;
	ft_index(stack);
	while (node != NULL)
	{
		if (min > node->nbr)
		{
			smal = node;
			min = node->nbr;
		}
		node = node->next;
	}
	return (smal);
}

t_node	*ft_max_int(t_stack *stack)
{
	t_node	*maximum;
	t_node	*node;
	int		max;

	ft_median(stack);
	node = stack->up;
	max = node->nbr;
	maximum = node;
	while (node != NULL)
	{
		if (max < node->nbr)
		{
			maximum = node;
			max = node->nbr;
		}
		node = node->next;
	}
	return (maximum);
}

int	is_tryed(t_stack *stack)
{
	int		value;
	t_node	*node;

	node = stack->up;
	value = node->nbr;
	while (node != NULL)
	{
		if (value > node->nbr)
			return (0);
		value = node->nbr;
		node = node->next;
	}
	return (1);
}
