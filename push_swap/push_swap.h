/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maxgarci <maxgarci@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/28 23:20:55 by maxgarci          #+#    #+#             */
/*   Updated: 2024/01/31 22:15:16 by maxgarci         ###   ########.fr       */
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
void		push_swap(t_stack **a);

// switch.c
void		sa(t_stack **a);
void		sb(t_stack **b);

// push.c
void		pa(t_stack **b, t_stack **a);
void		pb(t_stack **a, t_stack **b);

// rotate.c
void    	ra(t_stack **a);
void		rb(t_stack **b);
void		rr(t_stack **a, t_stack **b);

// reverserotate.c
void    	rra(t_stack **a);
void		rrb(t_stack **b);
void		rrr(t_stack **a, t_stack **b);

// push_swap_utils.c
void		assign_index(t_stack **stack);
int     	partially_sorted(t_stack *stack);
int		sorted(t_stack *stack);
void		show_stack(t_stack *stack);
int		ft_atoi(const char *nptr, int *error);

// stack.c
int     	ft_stacksize(t_stack *stack);
t_stack 	*ft_stacklast(t_stack *stack);
t_stack 	*ft_stacknew(int value);
void		ft_stackadd_back(t_stack **stack, t_stack *new);
void		ft_stackadd_front(t_stack **stack, t_stack *new);

#endif
