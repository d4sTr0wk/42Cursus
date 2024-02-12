/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maxgarci <maxgarci@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 14:29:02 by maxgarci          #+#    #+#             */
/*   Updated: 2024/01/31 22:11:37 by maxgarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	calc_cand(t_stack *a, t_stack *b, t_stack *tmp)
{
	int	i;
	int	min_moves;
	int	moves;
	int	pos;

	i = 0;
	min_moves = 1;
	while (i != 4 && ft_stacksize(a) - i > 3)
	{
		tmp = a;
		while (tmp)
		{

			tmp = tmp->next;
		i++;
	}
	return (0);
}

void	push_swap(t_stack **a)
{
	t_stack	*b;
	t_stack	*tmp;
	int	candidate_pos;
	int	cnt;

	b = NULL;
	while ((!partially_sorted(*a) && (*a)->index != 1) || b)
	{
		if (ft_stacksize(*a) <= 3 && !partially_sorted(*a))
		{
			if (!partially_sorted(*a))
				sa(a);
			if ((*a)->index < (*a)->next->index)
				rra(a);
			else
				ra(a);
		}
		else
		{
			if (!b)
			{
				pb(a, &b);
				pb(a, &b);
				if (b->index < b->next->index)
					sb(&b);
			}
			else
			{
				candidate_pos = calc_cand(*a, b, tmp);

			}	
		}
	}
	if (!sorted(*a))
	{
		tmp = *a;
		while (tmp->index != 1)
			tmp = tmp->next;
		
	}
}
