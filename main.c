/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: najeuneh <najeuneh@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 16:35:45 by najeuneh          #+#    #+#             */
/*   Updated: 2024/05/29 14:26:38 by najeuneh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inc/libft.h"
#include <stdio.h>

static void	ft_init(t_stack *stack)
{
	stack = malloc(sizeof(t_stack));
	if (!stack)
		return ;
	stack->up = NULL;
	stack->low = NULL;
}

int	main()
{
	int		i;
	t_stack	stack_a;
	t_stack	stack_b;

	ft_init(&stack_a);
	ft_init(&stack_b);
	i = 0;
	// stack_a.up = dl_lstnew(i);
	while (++i < 5)
	{
		printf("here\n");
		dl_lstadd_front(&stack_a, i);
	}
	// printf("%d", stack_a.up->nbr);
	sa(&stack_a);
	while(stack_a.up != NULL)
	{
		printf("%d\n", stack_a.up->nbr);
		stack_a.up = stack_a.up->next;
	}
}