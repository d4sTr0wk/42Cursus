/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maxgarci <maxgarci@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 14:11:19 by maxgarci          #+#    #+#             */
/*   Updated: 2024/01/31 12:09:42 by maxgarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	calc_cand(t_stack *a, t_stack *b)
{

}

void	assign_index(t_stack **stack)
{
	int		cnt;
	t_stack		*tmp1;
	t_stack		*tmp2;
	
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
	t_stack	*tmp;

	tmp = stack;
	while (stack->next)
	{
		if (!(stack->index < stack->next->index) || (stack->index > stack->next->index && !connected(tmp, stack->index, stack->next->index)))
			return (0);
		stack = stack->next;
	}
	return (1);
}

int	sorted(t_stack *stack)
{
	int	tam;

	tam = ft_stacksize(stack);
	while (stack->next)
	{
		if ((stack->index != (stack->next->index - 1)) && (stack->index != tam || stack->next->index != 1))
			return (0);
		stack = stack->next;
	}
	return (1);
}

void	show_stack(t_stack *stack)
{
	while (stack)
	{
		ft_printf("%i\n", stack->value);
		stack = stack->next;
	}
	ft_printf("-\na");
}

int     ft_atoi(const char *nptr, int *error)
{
        long    num;
        int             sign;
        int             i;

        i = 0;
        while ((nptr[i] >= 9 && nptr[i] <= 13) || nptr[i] == ' ')
                ++i;
        sign = 1;
        if (nptr[i] == '+' || nptr[i] == '-')
                if (nptr[i++] == '-')
                        sign = -1;
        num = 0;
        while (nptr[i] >= '0' && nptr[i] <= '9')
        {
                num *= 10;
                num += nptr[i] - '0';
                ++i;
        }
        if (nptr[i] != '\0')
        {
                num = 0;
                *error = 1;
        }
        return ((int)(num * sign));
}

