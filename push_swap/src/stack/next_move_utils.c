/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   next_move_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maxgarci <maxgarci@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/25 19:59:03 by maxgarci          #+#    #+#             */
/*   Updated: 2024/02/29 21:00:05 by maxgarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	both_dwn(t_stk **cands, t_stk **sol, t_stk *above, t_stk *below)
{
	if (stksize(*cands) - above->index > stksize(*sol) - below->index)
	{
		while ((*sol)->index != below->index)
			rrr(sol, cands);
		while ((*cands)->index != above->index)
			rrb(cands);
	}
	else
	{
		while ((*cands)->index != above->index)
			rrr(sol, cands);
		while ((*sol)->index != below->index)
			rra(sol);
	}
}

void	both_up(t_stk **cands, t_stk **sol, t_stk *above, t_stk *below)
{
	if (above->pos > below->pos)
	{
		while ((*sol)->index != below->index)
			rr(sol, cands);
		while ((*cands)->index != above->index)
			rb(cands);
	}
	else
	{
		while ((*cands)->index != above->index)
			rr(sol, cands);
		while ((*sol)->index != below->index)
			ra(sol);
	}
}

void	up_down(t_stk **cands, t_stk **sol, t_stk *above, t_stk *below)
{
	while ((*sol)->index != below->index)
		rra(sol);
	while ((*cands)->index != above->index)
		rb(cands);
}

void	down_up(t_stk **cands, t_stk **sol, t_stk *above, t_stk *below)
{
	while ((*sol)->index != below->index)
		ra(sol);
	while ((*cands)->index != above->index)
		rrb(cands);
}
