/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   next_move_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maxgarci <maxgarci@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/25 19:59:03 by maxgarci          #+#    #+#             */
/*   Updated: 2024/08/13 16:19:12 by maxgarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	both_dwn(t_stk **cands, t_stk **sol, t_stk *above, t_stk *below)
{
	if (stksize(*cands) - above->pos > stksize(*sol) - below->pos)
	{
		while ((*sol)->index != below->index)
			rrr(sol, cands, ECHO);
		while ((*cands)->index != above->index)
			revrot(cands, ECHO);
	}
	else
	{
		while ((*cands)->index != above->index)
			rrr(sol, cands, ECHO);
		while ((*sol)->index != below->index)
			revrot(sol, ECHO);
	}
}

void	both_up(t_stk **cands, t_stk **sol, t_stk *above, t_stk *below)
{
	if (above->pos > below->pos)
	{
		while ((*sol)->index != below->index)
			rr(sol, cands, ECHO);
		while ((*cands)->index != above->index)
			rotate(cands, ECHO);
	}
	else
	{
		while ((*cands)->index != above->index)
			rr(sol, cands, ECHO);
		while ((*sol)->index != below->index)
			rotate(sol, ECHO);
	}
}

void	up_down(t_stk **cands, t_stk **sol, t_stk *above, t_stk *below)
{
	while ((*sol)->index != below->index)
		revrot(sol, ECHO);
	while ((*cands)->index != above->index)
		rotate(cands, ECHO);
}

void	down_up(t_stk **cands, t_stk **sol, t_stk *above, t_stk *below)
{
	while ((*sol)->index != below->index)
		rotate(sol, ECHO);
	while ((*cands)->index != above->index)
		revrot(cands, ECHO);
}
