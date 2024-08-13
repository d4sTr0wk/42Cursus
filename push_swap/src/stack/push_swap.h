/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maxgarci <maxgarci@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/28 23:20:55 by maxgarci          #+#    #+#             */
/*   Updated: 2024/08/13 16:14:31 by maxgarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include "../../include/include.h"

# define INT_MAX 2147483647
# define INT_MIN -2147483648
# define ECHO 1
# define MUTE 0

typedef struct s_stack
{
	int				value;
	int				index;
	int				pos;
	char			stk_id;
	struct s_stack	*next;
}	t_stk;

// main.c
int		main(int argc, char **argv);

// push_swap.c
void	push_swap(t_stk **a, t_stk **b);

// check_args.c
int		check_args(char **args, int argc);

// initialize_args.c
int		initialize_args(int argc, char **argv, t_stk **a);

// next_move_utils.c
void	both_dwn(t_stk **cands, t_stk **sol, t_stk *ab, t_stk *bel);
void	both_up(t_stk **cands, t_stk **sol, t_stk *ab, t_stk *bel);
void	up_down(t_stk **cands, t_stk **sol, t_stk *ab, t_stk *bel);
void	down_up(t_stk **cands, t_stk **sol, t_stk *ab, t_stk *bel);

// swap.c
void	sa(t_stk **a, int echo);
void	sb(t_stk **b, int echo);

// push.c
void	pa(t_stk **a, t_stk **b, int echo);
void	pb(t_stk **a, t_stk **b, int echo);

// rotate.c
void	rotate(t_stk **stk, int echo);
void	rr(t_stk **a, t_stk **b, int echo);

// reverserotate.c
void	revrot(t_stk **stk, int echo);
void	rrr(t_stk **a, t_stk **b, int echo);

// push_swap_utils1.c
void	assign_positions(t_stk **stack);
int		partially_sorted(t_stk *stack);
int		sorted(t_stk *stack);

//push_swap_utils2.c
void	free_stack(t_stk **a);
void	show_stack(t_stk *a, t_stk *b);
void	lowest_greatest(int conf, t_stk **tmp_sol);
void	get_below(int above_index, t_stk **tmp_sol);

// stack.c
int		stksize(t_stk *stack);
t_stk	*stacknew(int value, int pos);
int		stackadd_back(t_stk **stack, t_stk *new);
void	stackadd_front(t_stk **stack, t_stk *new);

#endif
