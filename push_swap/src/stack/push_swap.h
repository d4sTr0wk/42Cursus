/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maxgarci <maxgarci@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/28 23:20:55 by maxgarci          #+#    #+#             */
/*   Updated: 2024/08/05 19:27:25 by maxgarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include "../../include/include.h"

# define INT_MAX 2147483647
# define INT_MIN -2147483648

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

// initialize_utils.c
char	*ft_strdup(const char *s1);
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	**ft_split(char const *s, char c);
int		ft_split_count(char **tab);

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
void	rotate(t_stk **stk, int conf);
void	rr(t_stk **a, t_stk **b);

// reverserotate.c
void	revrot(t_stk **stk, int conf);
void	rrr(t_stk **a, t_stk **b);

// push_swap_utils1.c
void	assign_index(t_stk **stack);
void	assign_positions(t_stk **stack);
int		partially_sorted(t_stk *stack);
int		sorted(t_stk *stack);

//push_swap_utils2.c
void	show_stack(t_stk *a, t_stk *b);
void	lowest_greatest(int conf, t_stk **tmp_sol);
void	get_below(int above_index, t_stk **tmp_sol);

// stack.c
int		stksize(t_stk *stack);
t_stk	*stacknew(int value, int pos);
int		stackadd_back(t_stk **stack, t_stk *new);
void	stackadd_front(t_stk **stack, t_stk *new);

#endif
