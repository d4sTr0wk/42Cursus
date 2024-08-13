/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maxgarci <maxgarci@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 14:06:50 by maxgarci          #+#    #+#             */
/*   Updated: 2024/08/13 16:07:48 by maxgarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa(t_stk **a, int echo)
{
	t_stk	*tmp;

	tmp = (*a)->next;
	(*a)->next = (*a)->next->next;
	tmp->next = (*a);
	(*a) = tmp;
	assign_positions(a);
	if (echo)
		ft_printf("sa\n");
}

void	sb(t_stk **b, int echo)
{
	t_stk	*tmp;

	tmp = (*b)->next;
	(*b)->next = (*b)->next->next;
	tmp->next = (*b);
	(*b) = tmp;
	assign_positions(b);
	if (echo)
		ft_printf("sb\n");
}
