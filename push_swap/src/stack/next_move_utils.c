/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   next_move_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maxgarci <maxgarci@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/25 19:59:03 by maxgarci          #+#    #+#             */
/*   Updated: 2024/03/05 12:10:07 by maxgarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	both_dwn(t_stk **cands, t_stk **sol, t_stk *above, t_stk *below)
{
	if (stksize(*cands) - above->pos > stksize(*sol) - below->pos)
	{
		while ((*sol)->index != below->index)
			rrr(sol, cands);
		while ((*cands)->index != above->index)
			revrot(cands, 0);
	}
	else
	{
		while ((*cands)->index != above->index)
			rrr(sol, cands);
		while ((*sol)->index != below->index)
			revrot(sol, 0);
	}
}

void	both_up(t_stk **cands, t_stk **sol, t_stk *above, t_stk *below)
{
	if (above->pos > below->pos)
	{
		while ((*sol)->index != below->index)
			rr(sol, cands);
		while ((*cands)->index != above->index)
			rotate(cands, 0);
	}
	else
	{
		while ((*cands)->index != above->index)
			rr(sol, cands);
		while ((*sol)->index != below->index)
			rotate(sol, 0);
	}
}

void	up_down(t_stk **cands, t_stk **sol, t_stk *above, t_stk *below)
{
	while ((*sol)->index != below->index)
		revrot(sol, 0);
	while ((*cands)->index != above->index)
		rotate(cands, 0);
}

void	down_up(t_stk **cands, t_stk **sol, t_stk *above, t_stk *below)
{
	while ((*sol)->index != below->index)
		rotate(sol, 0);
	while ((*cands)->index != above->index)
		revrot(cands, 0);
}
