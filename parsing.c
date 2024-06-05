/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: najeuneh <najeuneh@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/05 12:35:49 by najeuneh          #+#    #+#             */
/*   Updated: 2024/06/05 14:29:55 by najeuneh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inc/libft.h"

int	parsing(char **strs)
{
	int	i;
	int	j;

	j = 0;
	i = 0;
	while (strs[i])
	{
		j = 1;
		if (!(strs[i][0] >= '0' && strs[i][0] <= '9') && !(strs[i][0] == '-' &&
			strs[i][1] >= '0' && strs[i][1] <= '9'))
			return (0);
		while (strs[i][j])
		{
			if (!(strs[i][j] >= 48 && strs[i][j] <= 57))
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int	ft_check2(t_stack *stack)
{
	t_node	*node;
	t_node	*node2;

	node = stack->up;
	node2 = stack->up->next;
	while (node != NULL && node2 != NULL)
	{
		while (node2 != NULL)
		{
			if (node->nbr == node2->nbr)
				return (0);
			node2 = node2->next;
		}
		node = node->next;
		node2 = node->next;
	}
	return (1);
}
