/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algoritme.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: najeuneh <najeuneh@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/30 18:05:03 by najeuneh          #+#    #+#             */
/*   Updated: 2024/05/31 16:03:02 by najeuneh         ###   ########.fr       */
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
	while (dl_lstsize(stack) > 5)
	{
		moy = moyen_cal(stack);
		ft_try(stack, b, moy);
	}
	ft_bestfriends(stack, b);
	ft_cost(b);
	node_a = stack;
	node_b = b;
	while(node_b != NULL)
	{
		ft_min_cost
	}
}
