/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maxgarci <maxgarci@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 17:42:53 by maxgarci          #+#    #+#             */
/*   Updated: 2024/03/05 18:39:32 by maxgarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate(t_stk **stk, int conf)
{
	t_stk	*tmp;
	t_stk	*iterator;

	tmp = *stk;
	iterator = tmp->next;
	*stk = iterator;
	while (iterator->next)
		iterator = iterator->next;
	iterator->next = tmp;
	tmp->next = NULL;
	assign_positions(stk);
	if ((*stk)->stk_id == 'a' && conf == 0)
		ft_printf("ra\n");
	else if ((*stk)->stk_id == 'b' && conf == 0)
		ft_printf("rb\n");
}

void	rr(t_stk **a, t_stk **b)
{
	rotate(a, 1);
	rotate(b, 1);
	ft_printf("rr\n");
}
