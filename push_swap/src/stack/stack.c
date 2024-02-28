/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maxgarci <maxgarci@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 11:22:12 by maxgarci          #+#    #+#             */
/*   Updated: 2024/02/28 09:02:31 by maxgarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	stksize(t_stk *stack)
{
	int	cnt;

	cnt = 0;
	while (stack)
	{
		cnt++;
		stack = stack->next;
	}
	return (cnt);
}

t_stk	*stacknew(int value, int pos)
{
	t_stk	*stack;

	stack = (t_stk *)malloc(sizeof(t_stk));
	if (!stack)
		return (NULL);
	stack->value = value;
	stack->index = 0;
	stack->pos = pos;
	stack->stk_id = 'a';
	stack->next = NULL;
	return (stack);
}

void	stackadd_back(t_stk **stack, t_stk *new)
{
	t_stk	*tmp;

	if (!(*stack))
		*stack = new;
	else
	{
		tmp = *stack;
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = new;
	}
}

void	stackadd_front(t_stk **stack, t_stk *new)
{
	if (stack && new)
	{
		new->next = *stack;
		*stack = new;
	}
	else if (!stack && new)
	{
		*stack = new;
	}
}
