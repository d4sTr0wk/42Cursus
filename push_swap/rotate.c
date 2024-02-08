/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maxgarci <maxgarci@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 17:42:53 by maxgarci          #+#    #+#             */
/*   Updated: 2024/01/31 22:14:07 by maxgarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ra(t_stack **a)
{
	t_stack	*tmp;
	t_stack *iterator;

	tmp = *a;
	iterator = tmp->next;
	*a = iterator;
	while (iterator->next)
		iterator = iterator->next;
	iterator->next = tmp;
	tmp->next = NULL;
	ft_printf("ra\n");
}

void	rb(t_stack **b)
{
	t_stack	*tmp;
	t_stack *iterator;

	tmp = *a;
	iterator = tmp->next;
	*a = iterator;
	while (iterator->next)
		iterator = iterator->next;
	iterator->next = tmp;
	tmp->next = NULL;
	ft_printf("ra\n");
}

void	rr(t_stack **a, t_stack **b)
{
	ra(a);
	rb(b);
}
