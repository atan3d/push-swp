/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: najeuneh <najeuneh@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/24 13:30:16 by najeuneh          #+#    #+#             */
/*   Updated: 2024/05/28 18:27:40 by najeuneh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>

typedef struct s_node
{
	struct s_node	*next;
	struct s_node	*prev;
	int				nbr;
}				t_node;

typedef struct s_stack
{
	t_node	*up;
	t_node	*low;
}				t_stack;

// ROTATE
void	rotate(t_stack *list);
void	ra(t_stack *list);

// PUSH
void	pa(t_stack *a, t_stack *b);
void	pb(t_stack *a, t_stack *b);

// SWAP
void	push_swap(t_stack *stack);
void	sa(t_stack *stack);
void	sb(t_stack *stack);
void	ss(t_stack *a, t_stack *b);

#endif