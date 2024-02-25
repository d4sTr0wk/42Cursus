/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maxgarci <maxgarci@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 14:37:58 by maxgarci          #+#    #+#             */
/*   Updated: 2024/02/25 14:35:06 by maxgarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	pa(t_stack **a, t_stack **b)
{
	t_stack	*tmp;

	if (*b)
	{
		tmp = (*b)->next;
		stackadd_front(a, *b);
		*b = tmp;
	}
	assign_positions(a);
	assign_positions(b);
	ft_printf("pa\n");
}

void	pb(t_stack **a, t_stack **b)
{
	t_stack	*tmp;

	if (*a)
	{
		tmp = (*a)->next;
		stackadd_front(b, *a);
		*a = tmp;
	}
	assign_positions(a);
	assign_positions(b);
	ft_printf("pb\n");
}
