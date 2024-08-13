/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maxgarci <maxgarci@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 17:42:53 by maxgarci          #+#    #+#             */
/*   Updated: 2024/08/13 16:15:04 by maxgarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate(t_stk **stk, int echo)
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
	if ((*stk)->stk_id == 'a' && echo)
		ft_printf("ra\n");
	else if ((*stk)->stk_id == 'b' && echo)
		ft_printf("rb\n");
}

void	rr(t_stk **a, t_stk **b, int echo)
{
	rotate(a, MUTE);
	rotate(b, MUTE);
	if (echo)
		ft_printf("rr\n");
}
