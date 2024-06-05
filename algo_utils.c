/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: najeuneh <najeuneh@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/30 18:17:10 by najeuneh          #+#    #+#             */
/*   Updated: 2024/06/05 17:39:57 by najeuneh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inc/libft.h"

float	moyen_cal(t_stack *stack)
{
	float	i;
	float	count;
	float	moy;
	t_node	*node;

	i = 0;
	count = 0;
	count = dl_lstsize(stack);
	node = stack->up;
	while (node != NULL)
	{
		i += node->nbr;
		node = node->next;
	}
	moy = i / count;
	return (moy);
}

void	ft_try(t_stack *a, t_stack *b, float moy)
{
	if (a->up->nbr < moy)
		pb(a, b);
	else
		ra(a);
}

void	ft_bestfriends(t_stack *stack, t_stack *b)
{
	long	max;
	t_node	*node_a;
	t_node	*node_b;

	node_b = b->up;
	while (node_b != NULL)
	{
		max = 2147483648;
		node_a = stack->up;
		while (node_a != NULL)
		{
			if (max > node_a->nbr && node_a->nbr > node_b->nbr)
			{
				max = node_a->nbr;
				node_b->best = node_a;
			}
			node_a = node_a->next;
		}
		node_b = node_b->next;
	}
}

int	ft_median(t_stack *stack)
{
	int		i;
	int		median;
	t_node	*node;

	i = 0;
	node = stack->up ;
	median = (dl_lstsize(stack) / 2);
	while (node != NULL)
	{
		node->index = i;
		i++;
		node = node->next;
	}
	stack->median = median;
	return (median);
}

void	ft_cost(t_stack *stack)
{
	t_node	*node;
	int		median;
	int		i;
	int		count;

	i = 0;
	median = ft_median(stack);
	node = stack->up;
	while (node != NULL)
	{
		count = 0;
		i = node->index;
		while (i > 0 && i < dl_lstsize(stack))
		{
			if (i <= median)
				i--;
			else
				i++;
			count++;
		}
		node->cost = count;
		node = node->next;
	}
}
