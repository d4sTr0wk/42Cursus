/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maxgarci <maxgarci@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/28 23:20:55 by maxgarci          #+#    #+#             */
/*   Updated: 2024/02/26 14:33:52 by maxgarci         ###   ########.fr       */
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
}	t_stk;

t_stk	*stacklast(t_stk *stack);
t_stk	*stacknew(int value, int pos);

// main.c
int		main(int argc, char **argv);

// push_swap.c
void	get_below(int above_index, t_stk **tmp_sol);
void	calc_cand(t_stk *cands, t_stk *sol, t_stk **above, t_stk **below, int conf);
void	next_move(t_stk **cands, t_stk **sol, int conf);
void	sort_stk(t_stk **a);
void	push_swap(t_stk **a, t_stk **b);

// next_move_utils.c
void	both_dwn(t_stk **cands, t_stk **sol, t_stk *ab, t_stk *bel);
void	both_up(t_stk **cands, t_stk **sol, t_stk *ab, t_stk *bel);
void	up_down(t_stk **cands, t_stk **sol, t_stk *ab, t_stk *bel);
void	down_up(t_stk **cands, t_stk **sol, t_stk *ab, t_stk *bel);

// swap.c
void	sa(t_stk **a);
void	sb(t_stk **b);

// push.c
void	pa(t_stk **a, t_stk **b);
void	pb(t_stk **a, t_stk **b);

// rotate.c
void	ra(t_stk **a);
void	rb(t_stk **b);
void	rr(t_stk **a, t_stk **b);

// reverserotate.c
void	rra(t_stk **a);
void	rrb(t_stk **b);
void	rrr(t_stk **a, t_stk **b);

// push_swap_utils1.c
void	assign_index(t_stk **stack);
void	assign_positions(t_stk **stack);
int		partially_sorted(t_stk *stack);
int		sorted(t_stk *stack);

//push_swap_utils2.c
int		ft_atoi(const char *nptr, int *error);
void	show_stack(t_stk *a, t_stk *b);

// stack.c
int		stksize(t_stk *stack);
void	stackadd_back(t_stk **stack, t_stk *new);
void	stackadd_front(t_stk **stack, t_stk *new);

#endif
