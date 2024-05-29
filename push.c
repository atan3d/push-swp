/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: najeuneh <najeuneh@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 15:01:46 by najeuneh          #+#    #+#             */
/*   Updated: 2024/05/28 17:41:22 by najeuneh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inc/libft.h"

void	pa(t_stack *a, t_stack *b)
{
	dl_lstadd_front(a, b->up->nbr);
	dl_lstdelfront(b);
	printf("pa\n");
}

void	pb(t_stack *a, t_stack *b)
{
	dl_lstadd_front(b, a->up->nbr);
	dl_lstdelback(a);
	printf("pb\n");
}