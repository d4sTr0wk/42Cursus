/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maxgarci <maxgarci@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/24 14:05:16 by maxgarci          #+#    #+#             */
/*   Updated: 2024/08/10 20:01:55 by maxgarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_stack(t_stk **a)
{
	t_stk	*tmp;

	while (*a)
	{
		tmp = *a;
		*a = (*a)->next;
		free(tmp);
	}
}

void	show_stack(t_stk *a, t_stk *b)
{
	while (a || b)
	{
		if (a)
		{
			ft_printf("%i", a->value);
			a = a->next;
		}
		else
			ft_printf(" ");
		ft_printf(" ");
		if (b)
		{
			ft_printf("%i", b->value);
			b = b->next;
		}
		else
			ft_printf(" ");
		ft_printf("\n");
	}
	ft_printf("- -\na b\n\n");
}

void	lowest_greatest(int conf, t_stk **tmp_sol)
{
	t_stk	*tmp;

	tmp = *tmp_sol;
	while (tmp)
	{
		if ((tmp->index < (*tmp_sol)->index && conf) || \
			(tmp->index > (*tmp_sol)->index && !conf))
			*tmp_sol = tmp;
		tmp = tmp->next;
	}
}

void	get_below(int above_index, t_stk **tmp_sol)
{
	t_stk	*tmp;
	int		check;
	int		conf;

	tmp = *tmp_sol;
	check = 0;
	if (tmp->stk_id == 'a')
		conf = 1;
	else
		conf = 0;
	while (tmp)
	{
		if (((above_index < tmp->index && conf) || \
			(above_index > tmp->index && !conf)) && \
			(!check || (check && \
			((tmp->index < (*tmp_sol)->index && conf) || \
			(tmp->index > (*tmp_sol)->index && !conf)))))
		{
			check = 1;
			*tmp_sol = tmp;
		}
		tmp = tmp->next;
	}
	if (!check)
		lowest_greatest(conf, tmp_sol);
}
