/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverserotate.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maxgarci <maxgarci@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 17:45:41 by maxgarci          #+#    #+#             */
/*   Updated: 2024/02/26 14:18:21 by maxgarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rra(t_stk **a)
{
	t_stk	*tmp;

	tmp = *a;
	while (tmp->next->next)
		tmp = tmp->next;
	tmp->next->next = *a;
	*a = tmp->next;
	tmp->next = NULL;
	assign_positions(a);
	ft_printf("rra\n");
}

void	rrb(t_stk **b)
{
	t_stk	*tmp;

	tmp = *b;
	while (tmp->next->next)
		tmp = tmp->next;
	tmp->next->next = *b;
	*b = tmp->next;
	tmp->next = NULL;
	assign_positions(b);
	ft_printf("rrb\n");
}

void	rrr(t_stk **a, t_stk **b)
{
	rra(a);
	rrb(b);
}
