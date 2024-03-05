/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverserotate.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maxgarci <maxgarci@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 17:45:41 by maxgarci          #+#    #+#             */
/*   Updated: 2024/03/05 11:55:21 by maxgarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	revrot(t_stk **stk, int conf)
{
	t_stk	*tmp;

	tmp = *stk;
	while (tmp->next->next)
		tmp = tmp->next;
	tmp->next->next = *stk;
	*stk = tmp->next;
	tmp->next = NULL;
	assign_positions(stk);
	if ((*stk)->stk_id == 'a' && conf == 0)
		ft_printf("rra\n");
	else if ((*stk)->stk_id == 'b' && conf == 0)
		ft_printf("rrb\n");
}

void	rrr(t_stk **a, t_stk **b)
{
	revrot(a, 1);
	revrot(b, 1);
	ft_printf("rrr\n");
}
