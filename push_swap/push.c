/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maxgarci <maxgarci@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 14:37:58 by maxgarci          #+#    #+#             */
/*   Updated: 2024/02/12 19:07:36 by maxgarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	pa(t_stack **a, t_stack **b, int *cnt_moves)
{
	t_stack *tmp;

	if (*b)
	{
		tmp = (*b)->next;
		ft_stackadd_front(a, *b);
		*b = tmp;
	}
	assign_positions(a);
	assign_positions(b);
	ft_printf("%i: pa\n", (*cnt_moves)++);
}

void	pb(t_stack **a, t_stack **b, int *cnt_moves)
{
	t_stack *tmp;

	if (*a)
	{
		tmp = (*a)->next;
		ft_stackadd_front(b, *a);
		*a = tmp;
	}
	assign_positions(a);
	assign_positions(b);
	ft_printf("%i: pb\n", (*cnt_moves)++);
}
