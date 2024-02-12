/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maxgarci <maxgarci@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 14:29:02 by maxgarci          #+#    #+#             */
/*   Updated: 2024/02/12 19:25:44 by maxgarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_swap(t_stack **a)
{
	t_stack	*b;
	t_stack	*tmp;
	int		i;

	b = NULL;
	while (!partially_sorted(*a) || b)
	{
		if (ft_stacksize(*a) <= 3)
			sa(a);
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
		if (tmp->pos > ft_stacksize(*a) - tmp->pos + 1)
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
