/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maxgarci <maxgarci@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 14:37:58 by maxgarci          #+#    #+#             */
/*   Updated: 2024/08/13 16:08:21 by maxgarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	pa(t_stk **a, t_stk **b, int echo)
{
	t_stk	*tmp;

	if (*b)
	{
		tmp = (*b)->next;
		stackadd_front(a, *b);
		*b = tmp;
		(*a)->stk_id = 'a';
	}
	assign_positions(a);
	assign_positions(b);
	if (echo)
		ft_printf("pa\n");
}

void	pb(t_stk **a, t_stk **b, int echo)
{
	t_stk	*tmp;

	if (*a)
	{
		tmp = (*a)->next;
		stackadd_front(b, *a);
		*a = tmp;
		(*b)->stk_id = 'b';
	}
	assign_positions(a);
	assign_positions(b);
	if (echo)
		ft_printf("pb\n");
}
