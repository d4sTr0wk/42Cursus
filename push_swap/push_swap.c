/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maxgarci <maxgarci@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 14:29:02 by maxgarci          #+#    #+#             */
/*   Updated: 2024/02/12 18:50:00 by maxgarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_swap(t_stack **a)
{
	t_stack	*b;
	t_stack	*tmp;
	int		i;

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

			}	
		}
	}
	if (!sorted(*a))
	{
		tmp = *a;
		while (tmp->index != 1)
			tmp = tmp->next;
		if (tmp->pos > ft_stacksize(*a) - tmp->pos)
		{
			i = ft_stacksize(*a) - tmp->pos;
			while ((i--) >= 0)
				rra(a);
		}
		else
		{
			i = tmp->pos;
			while ((i--) != 1)
				ra(a);
		}
	}
}
