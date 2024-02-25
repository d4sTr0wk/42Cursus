/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maxgarci <maxgarci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 14:11:19 by maxgarci          #+#    #+#             */
/*   Updated: 2024/02/24 14:07:35 by maxgarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	assign_index(t_stack **stack)
{
	int		cnt;
	t_stack	*tmp1;
	t_stack	*tmp2;

	tmp1 = *stack;
	while (tmp1)
	{
		cnt = 1;
		tmp2 = *stack;
		while (tmp2)
		{
			if (tmp1->value > tmp2->value)
				cnt++;
			tmp2 = tmp2->next;
		}
		tmp1->index = cnt;
		tmp1 = tmp1->next;
	}
}

void	assign_positions(t_stack **stack)
{
	t_stack	*tmp;
	int		i;

	i = 1;
	tmp = *stack;
	while (tmp)
	{
		tmp->pos = i++;
		tmp = tmp->next;
	}
}

static int	connected(t_stack *stack, int greatest, int lowest)
{
	t_stack	*tmp;

	tmp = stack;
	while (tmp)
	{
		if (greatest < tmp->index || lowest > tmp->index)
			return (0);
		tmp = tmp->next;
	}
	return (1);
}

int	partially_sorted(t_stack *stack)
{
	while (stack->next)
	{
		if ((stack->index > stack->next->index && !connected(stack,
					stack->index, stack->next->index))
			|| (stack->index < stack->next->index && stack->next->next
				&& connected(stack, stack->next->index, stack->index)))
			return (0);
		stack = stack->next;
	}
	return (1);
}

int	sorted(t_stack *stack)
{
	while (stack->next)
	{
		if (stack->index != stack->pos)
			return (0);
		stack = stack->next;
	}
	return (1);
}
