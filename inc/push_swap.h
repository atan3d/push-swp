/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: najeuneh <najeuneh@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/24 13:30:16 by najeuneh          #+#    #+#             */
/*   Updated: 2024/05/31 15:46:27 by najeuneh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>

typedef struct s_node
{
	struct s_node	*next;
	struct s_node	*prev;
	int				cost;
	int				index;
	struct s_node	*best;
	long long		nbr;
}				t_node;

typedef struct s_stack
{
	t_node	*up;
	t_node	*low;
	int		median;
}				t_stack;

// SWAP
void	push_swap(t_stack *stack);
void	sa(t_stack *stack);
void	sb(t_stack *stack);
void	ss(t_stack *a, t_stack *b);

// PUSH
void	push(t_stack *a, t_stack *b);
void	pa(t_stack *a, t_stack *b);
void	pb(t_stack *a, t_stack *b);

// ROTATE
void	rotate(t_stack *list);
void	ra(t_stack *list);
void	rb(t_stack *b);
void	rr(t_stack *a, t_stack *b);

//REVERSE ROTATE
void	reverse_rotate(t_stack *stack);
void	rra(t_stack *a);
void	rrb(t_stack *b);
void	rrr(t_stack *a, t_stack *b);

//ALGO
float	moyen_cal(t_stack *stack);
void	algoritme(t_stack *stack);
t_stack	*ft_init(t_stack *stack);
void	suite_main(t_stack *stack);
void	ft_try(t_stack *a, t_stack *b, float moy);
void	ft_bestfriends(t_stack *stack, t_stack *b);
void	ft_cost(t_stack *stack);
int		ft_median(t_stack *stack);

#endif