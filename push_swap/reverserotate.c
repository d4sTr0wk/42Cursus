/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverserotate.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maxgarci <maxgarci@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 17:45:41 by maxgarci          #+#    #+#             */
/*   Updated: 2024/02/12 19:07:09 by maxgarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rra(t_stack **a, t_stack *b, int *cnt_moves)
{
	t_stack	*tmp;

	tmp = *a;
	while(tmp->next->next)
		tmp = tmp->next;
	tmp->next->next = *a;
	*a = tmp->next;
	tmp->next = NULL;
	assign_positions(a);
	ft_printf("%i: Exec rra:\n", (*cnt_moves)++);
	show_stack(*a, b);
}


void	rrb(t_stack *a, t_stack **b, int *cnt_moves)
{
	t_stack	*tmp;

	tmp = *b;
	while(tmp->next->next)
		tmp = tmp->next;
	tmp->next->next = *b;
	*b = tmp->next;
	tmp->next = NULL;
	assign_positions(b);
	ft_printf("%i: Exec rrb:\n", (*cnt_moves)++);
	show_stack(a, *b);
}

void	rrr(t_stack **a, t_stack **b, int *cnt_moves)
{
	rra(a, *b, cnt_moves);
	rrb(*a, b, cnt_moves);
}
