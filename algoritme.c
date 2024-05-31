/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algoritme.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: najeuneh <najeuneh@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/30 18:05:03 by najeuneh          #+#    #+#             */
/*   Updated: 2024/05/31 15:39:54 by najeuneh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inc/libft.h"

void	algoritme(t_stack *stack)
{
	t_stack	*b;
	float	moy;

	b = NULL;
	b = ft_init(b);
	while (dl_lstsize(stack) > 5)
	{
		moy = moyen_cal(stack);
		ft_try(stack, b, moy);
	}
	ft_bestfriends(stack, b);
	ft_cost(b);
	
}