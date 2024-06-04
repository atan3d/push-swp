/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: najeuneh <najeuneh@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/30 18:17:10 by najeuneh          #+#    #+#             */
/*   Updated: 2024/06/04 17:34:38 by najeuneh         ###   ########.fr       */
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

void	ft_min_cost(t_stack *stack,t_stack *b)
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
	// node_b = b->up;
	// while (node_b != NULL)
	// {
	// 	printf("a : %lld  b : %lld  bool : %d index a : %d  index b : %d\n", node_a->nbr, node_b->nbr, node_b->bool, node_b->best->index, node_b->index);
	// 	node_b = node_b->next;
	// }
}

void	ft_a_try(t_stack *stack, t_stack *b)
{
	t_node	*node;
	while (dl_lstsize(stack) > 3 && is_tryed(stack) == 0)
	{
		node = ft_min_int(stack);
		while (node->index-- >= 0)
			ra(stack);
		pb(stack, b);
	}
	node = ft_min_int(stack);
	if (dl_lstsize(stack) > 3 && is_tryed(stack) == 0)
	{
		while (node->index-- != 0)
			ra(stack);
	}
	node = ft_max_int(stack);
	if (node->index == 0 && is_tryed(stack) == 0)
	{
		ra(stack);
	}
	node = ft_max_int(stack);
	if (node->index == 1 && is_tryed(stack) == 0)
		rra(stack);
	if (stack->up->nbr > stack->up->next->nbr)
		sa(stack);
	while (dl_lstsize(stack) < 5)
		pa(stack, b);
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

void	ft_last_b(t_stack *a, t_stack *b)
{
	t_node	*node_b;

	node_b = b->up;
	ft_median(a);
	ft_bestfriends(a, b);
	algo_a(node_b, a);
	pa(a, b);
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
