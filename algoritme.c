/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algoritme.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: najeuneh <najeuneh@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/30 18:05:03 by najeuneh          #+#    #+#             */
/*   Updated: 2024/06/05 18:13:05 by najeuneh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inc/libft.h"

void	algoritme(t_stack *stack)
{
	t_stack	*b;
	t_node	*node_b;
	t_node	*node_a;
	float	moy;

	b = NULL;
	b = ft_init(b);
	b->median = 0;
	node_a = stack->up;
	node_b = b->up;
	if (is_tryed(stack) == 1)
		return ;
	while (dl_lstsize(stack) > 5)
	{
		moy = moyen_cal(stack);
		ft_try(stack, b, moy);
	}
	ft_index(stack);
	ft_a_try(stack, b, node_a);
	if (is_tryed(stack) == 1 && b->up == NULL)
		return ;
	algoritme1(stack, b);
}

void	algoritme1(t_stack *stack, t_stack *b)
{
	t_node	*node_a;
	t_node	*node_b;

	ft_cost(b);
	ft_cost(stack);
	ft_bestfriends(stack, b);
	ft_min_cost(stack, b);
	node_a = stack->up;
	node_b = b->up;
	algo_b(node_b, b, stack);
	pa(stack, b);
	algortime2(stack, b);
}

void	algortime2(t_stack *a, t_stack *b)
{
	int		size;
	t_node	*node_a;
	t_node	*node_b;

	size = dl_lstsize(b);
	while (size > 1)
	{
		node_a = a->up;
		node_b = b->up;
		a->median = ft_median(a);
		b->median = ft_median(b);
		ft_bestfriends(a, b);
		ft_cost(b);
		ft_cost(a);
		node_a = a->up;
		node_b = b->up;
		ft_min_cost(a, b);
		algo_b(node_b, b, a);
		pa(a, b);
		size--;
	}
	ft_last_b(a, b);
}

void	algo_b(t_node *node_b, t_stack *b, t_stack *a)
{
	while (node_b != NULL)
	{
		if (node_b->bool == 1)
		{
			if (node_b->index < b->median)
			{
				while (node_b->index > 0)
				{
					rb(b);
					node_b->index--;
				}
				algo_a(node_b, a);
			}
			else
			{
				while (node_b->index < dl_lstsize(b))
				{
					rrb(b);
					node_b->index++;
				}
				algo_a(node_b, a);
			}
		}
		node_b = node_b->next;
	}
}

void	algo_a(t_node *node_b, t_stack *a)
{
	int	size;

	size = dl_lstsize(a);
	if (node_b->best->index < a->median)
	{
		while (node_b->best->index > 0)
		{
			ra(a);
			node_b->best->index--;
		}
	}
	else
	{
		while (node_b->best->index < size)
		{
			rra(a);
			node_b->best->index++;
		}
	}
}
