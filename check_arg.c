/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_arg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: najeuneh <najeuneh@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/30 15:26:11 by najeuneh          #+#    #+#             */
/*   Updated: 2024/06/04 17:37:19 by najeuneh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inc/libft.h"

t_stack	*ft_init(t_stack *stack)
{
	stack = malloc(sizeof(t_stack));
	if (!stack)
	{
		ft_printf("error\n");
		return (stack);
	}
	stack->up = NULL;
	stack->low = NULL;
	return (stack);
}

int	init_lst(char	*str, t_stack **stack)
{
	char	**strs;
	int		i;

	i = -1;
	strs = ft_split(str, ' ');
	if (!strs)
		return (ft_printf("Error\n"), 0);
	*stack = ft_init(*stack);
	while (strs[++i])
	{
		dl_lstadd_back(*stack, ft_atoi(strs[i]));
		if (ft_atoi(strs[i]) > 2147483647 || ft_atoi(strs[i]) < -2147483648)
			return (ft_printf("Error\n"), free(strs), 0);
	}
	(*stack)->low->next = NULL;
	(*stack)->up->prev = NULL;
	return (free(strs[1]), 1);
}

int	main(int ac, char **av)
{
	t_stack	*stack;
	char	*str;

	str = NULL;
	stack = NULL;
	if (ac == 1)
		return (ft_printf("Error\n"), 0);
	else if (ac == 2)
	{
		if (init_lst(av[1], &stack) == 0)
			return (0);
	}
	else if (ac > 2)
	{
		ac = 1;
		str = ft_strdup(av[1]);
		while (av[++ac] != NULL)
		{
			str = ft_strjoin(str, " ");
			str = ft_strjoin(str, av[ac]);
		}
		if (init_lst(str, &stack) == 0)
			return (0);
	}
	suite_main(stack);
}

void	suite_main(t_stack *stack)
{
	t_node	*node_a;
	int		size;

	algoritme(stack);
	size = dl_lstsize(stack);
	ft_median(stack);
	ft_min_int(stack);
	node_a = stack->up;
	if (node_a->index <= stack->median)
	{
		while (node_a->index > 0)
		{
			ra(stack);
			node_a->index--;
		}
	}
	else
	{
		while (node_a->index < size)
		{
			rra(stack);
			node_a->index++;
		}
	}
}


