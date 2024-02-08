/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maxgarci <maxgarci@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 14:37:58 by maxgarci          #+#    #+#             */
/*   Updated: 2024/01/31 22:12:28 by maxgarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	pa(t_stack **b, t_stack **a)
{
	t_stack *tmp;

	if (b)
	{
		tmp = (*b)->next;
		ft_stackadd_front(a, *b);
		*b = tmp;
	}
	ft_printf("pa\n");
}

void	pb(t_stack **a, t_stack **b)
{
	t_stack *tmp;

	if (a)
	{
		tmp = (*a)->next;
		ft_stackadd_front(b, *a);
		*a = tmp;
	}
	ft_printf("pb\n");
}
