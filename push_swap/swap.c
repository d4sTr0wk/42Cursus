/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maxgarci <maxgarci@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 14:06:50 by maxgarci          #+#    #+#             */
/*   Updated: 2024/02/12 19:08:17 by maxgarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa(t_stack **a)
{
	t_stack	*tmp;

	tmp = (*a)->next;
	(*a)->next = (*a)->next->next;
	tmp->next = (*a);
	(*a) = tmp;
	assign_positions(a);
	ft_printf("sa\n");
}


void	sb(t_stack **b)
{
	t_stack	*tmp;

	tmp = (*b)->next;
	(*b)->next = (*b)->next->next;
	tmp->next = (*b);
	(*b) = tmp;
	assign_positions(b);
	ft_printf("sb\n");
}
