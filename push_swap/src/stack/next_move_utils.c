/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   next_move_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maxgarci <maxgarci@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/25 19:59:03 by maxgarci          #+#    #+#             */
/*   Updated: 2024/02/25 20:49:51 by maxgarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	both_dwn(t_stack **cands, t_stack **sol, t_stack *above, t_stack *below)
{
	if (stacksize(*cands) - above->index > stacksize(*sol) - below->index)
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

void	both_up(t_stack **cands, t_stack **sol, t_stack *above, t_stack *below)
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

void	up_down(t_stack **cands, t_stack **sol, t_stack *above, t_stack *below)
{
	while ((*sol)->index != below->index)
		rra(sol);
	while ((*cands)->index != above->index)
		rb(cands);
}

void	down_up(t_stack **cands, t_stack **sol, t_stack *above, t_stack *below)
{
	while ((*sol)->index != below->index)
		ra(sol);
	while ((*cands)->index != above->index)
		rrb(cands);
}
