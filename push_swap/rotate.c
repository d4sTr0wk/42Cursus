/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maxgarci <maxgarci@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 17:42:53 by maxgarci          #+#    #+#             */
/*   Updated: 2024/02/24 14:32:09 by maxgarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ra(t_stack **a, int *cnt_moves)
{
	t_stack	*tmp;
	t_stack	*iterator;

	tmp = *a;
	iterator = tmp->next;
	*a = iterator;
	while (iterator->next)
		iterator = iterator->next;
	iterator->next = tmp;
	tmp->next = NULL;
	assign_positions(a);
	ft_printf("ra\n");
	(*cnt_moves)++;
}

void	rb(t_stack **b, int *cnt_moves)
{
	t_stack	*tmp;
	t_stack	*iterator;

	tmp = *b;
	iterator = tmp->next;
	*b = iterator;
	while (iterator->next)
		iterator = iterator->next;
	iterator->next = tmp;
	tmp->next = NULL;
	assign_positions(b);
	ft_printf("rb\n");
	(*cnt_moves)++;
}

void	rr(t_stack **a, t_stack **b, int *cnt_moves)
{
	ra(a, cnt_moves);
	rb(b, cnt_moves);
}
