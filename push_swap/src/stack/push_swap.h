/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maxgarci <maxgarci@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/28 23:20:55 by maxgarci          #+#    #+#             */
/*   Updated: 2024/02/25 10:44:37 by maxgarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include "../../include/include.h"

typedef struct s_stack
{
	int				value;
	int				index;
	int				pos;
	struct s_stack	*next;
}	t_stack;

// main.c
int			main(int argc, char **argv);

// push_swap.c
void		get_below(int above_index, t_stack **tmp_sol);
void		calc_cand(t_stack *candidates, t_stack *solution, t_stack **above, t_stack **below, int conf);
void		push_swap(t_stack **a, int *cnt_moves);

// swap.c
void		sa(t_stack **a, int *cnt_moves);
void		sb(t_stack **b, int *cnt_moves);

// push.c
void		pa(t_stack **a, t_stack **b, int *cnt_moves);
void		pb(t_stack **a, t_stack **b, int *cnt_moves);

// rotate.c
void		ra(t_stack **a, int *cnt_moves);
void		rb(t_stack **b, int *cnt_moves);
void		rr(t_stack **a, t_stack **b, int *cnt_moves);

// reverserotate.c
void		rra(t_stack **a, int *cnt_moves);
void		rrb(t_stack **b, int *cnt_moves);
void		rrr(t_stack **a, t_stack **b, int *cnt_moves);

// push_swap_utils1.c
void		assign_index(t_stack **stack);
void		assign_positions(t_stack **stack);
int			partially_sorted(t_stack *stack);
int			sorted(t_stack *stack);

//push_swap_utils2.c
void		show_stack(t_stack *a, t_stack *b);
int			ft_atoi(const char *nptr, int *error);

// stack.c
int			stacksize(t_stack *stack);
t_stack		*stacklast(t_stack *stack);
t_stack		*stacknew(int value, int pos);
void		stackadd_back(t_stack **stack, t_stack *new);
void		stackadd_front(t_stack **stack, t_stack *new);

#endif
