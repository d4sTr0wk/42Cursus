/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maxgarci <maxgarci@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/28 23:20:55 by maxgarci          #+#    #+#             */
/*   Updated: 2024/02/12 19:06:02 by maxgarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include "ft_printf.h"

typedef struct s_stack
{
	int		value;
	int		index;
	int		pos;
	struct s_stack	*next;
}	t_stack;

// main.c
int		main(int argc, char **argv);

// push_swap.c
void		calc_cand(t_stack *candidates, t_stack *solution, t_stack **above, t_stack **below, int conf);
void		push_swap(t_stack **a, int *cnt_moves);

// switch.c
void		sa(t_stack **a, t_stack *b, int *cnt_moves);
void		sb(t_stack *a, t_stack **b, int *cnt_moves);

// push.c
void		pa(t_stack **b, t_stack **a, int *cnt_moves);
void		pb(t_stack **a, t_stack **b, int *cnt_moves);

// rotate.c
void    	ra(t_stack **a, t_stack *b, int *cnt_moves);
void		rb(t_stack *a, t_stack **b, int *cnt_moves);
void		rr(t_stack **a, t_stack **b, int *cnt_moves);

// reverserotate.c
void    	rra(t_stack **a, t_stack *b, int *cnt_moves);
void		rrb(t_stack *a, t_stack **b, int *cnt_moves);
void		rrr(t_stack **a, t_stack **b, int *cnt_moves);

// push_swap_utils.c
void		assign_index(t_stack **stack);
int     	partially_sorted(t_stack *stack);
int		sorted(t_stack *stack);
void		show_stack(t_stack *a, t_stack *b);
int		ft_atoi(const char *nptr, int *error);
void	assign_positions(t_stack **stack);

// stack.c
int     	ft_stacksize(t_stack *stack);
t_stack 	*ft_stacklast(t_stack *stack);
t_stack 	*ft_stacknew(int value, int pos);
void		ft_stackadd_back(t_stack **stack, t_stack *new);
void		ft_stackadd_front(t_stack **stack, t_stack *new);

#endif
