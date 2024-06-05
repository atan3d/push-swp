/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_arg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: najeuneh <najeuneh@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/30 15:26:11 by najeuneh          #+#    #+#             */
/*   Updated: 2024/06/05 17:34:36 by najeuneh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inc/libft.h"

t_stack	*ft_init(t_stack *stack)
{
	stack = malloc(sizeof(t_stack));
	if (!stack)
	{
		write(2, "Error\n", 6);
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
	if (ft_strncmp(str, "", 2) == 0)
		return (0);
	strs = ft_split(str, ' ');
	if (!strs)
		return (write(2, "Error\n", 6), 0);
	if (parsing(strs) == 0)
		return (write(2, "Error\n", 6), 0);
	*stack = ft_init(*stack);
	while (strs[++i])
	{
		dl_lstadd_back(*stack, ft_atoi(strs[i]));
		if (ft_atoi(strs[i]) > 2147483647 || ft_atoi(strs[i]) < -2147483648)
			return (write(2, "Error\n", 6), free_all(stack, strs),0);
	}
	(*stack)->low->next = NULL;
	(*stack)->up->prev = NULL;
	if (ft_check2(*stack) == 0)
		return (write(2, "Error\n", 6), 0);
	free_all(NULL, strs);
	return (1);
}

int	main(int ac, char **av)
{
	t_stack	*stack;
	char	*str;

	str = NULL;
	stack = NULL;
	if (ac == 1)
		return (0);
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
	node_a = ft_min_int(stack);
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
	free_all(&stack, NULL);
}
void	free_all(t_stack **stack, char **strs)
{
	t_node	*temp;
	int	i;

	i = 0;
	if (stack)
	{
		while ((*stack)->up != NULL)
		{
			temp = (*stack)->up->next;
			free((*stack)->up);
			(*stack)->up = temp;
		}
		(*stack)->up = NULL;
		(*stack)->low = NULL;
		free (*stack);
	}
	if (!strs)
		return ;
	while (strs[i] != NULL)
	{
		free(strs[i]);
		i++;
	}
	free (strs);
}
