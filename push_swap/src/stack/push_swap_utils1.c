/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils1.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maxgarci <maxgarci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 14:11:19 by maxgarci          #+#    #+#             */
/*   Updated: 2024/08/09 12:37:28 by maxgarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	assign_positions(t_stk **stack)
{
	t_stk	*tmp;
	int		i;

	i = 1;
	tmp = *stack;
	while (tmp)
	{
		tmp->pos = i++;
		tmp = tmp->next;
	}
}

static int	connected(t_stk *stack, int greatest, int lowest)
{
	t_stk	*tmp;

	tmp = stack;
	while (tmp)
	{
		if (greatest < tmp->index || lowest > tmp->index)
			return (0);
		tmp = tmp->next;
	}
	return (1);
}

int	partially_sorted(t_stk *stack)
{
	t_stk	*tmp;

	tmp = stack;
	while (stack)
	{
		if ((stack->next && stack->index > stack->next->index && \
			!connected(tmp, stack->index, stack->next->index)) || \
			(!stack->next && tmp->index < stack->index && \
			!connected(tmp, stack->index, tmp->index)))
			return (0);
		stack = stack->next;
	}
	return (1);
}

int	sorted(t_stk *stack)
{
	while (stack->next)
	{
		if (stack->index != stack->pos)
			return (0);
		stack = stack->next;
	}
	return (1);
}
