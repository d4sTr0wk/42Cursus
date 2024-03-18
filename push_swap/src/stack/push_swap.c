/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maxgarci <maxgarci@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 14:29:02 by maxgarci          #+#    #+#             */
/*   Updated: 2024/03/17 16:47:12 by maxgarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	calc_mvs(int cands, int sol, t_stk *t_cand, t_stk *t_sol)
{
	int	moves;

	moves = 0;
	if (t_sol->pos > sol - t_sol->pos + 1 && \
		t_cand->pos > cands - t_cand->pos + 1)
	{
		if (cands - t_cand->pos > sol - t_sol->pos)
			moves += cands - t_cand->pos + 1;
		else
			moves += sol - t_sol->pos + 1;
	}
	else if (t_sol->pos <= sol - t_sol->pos + 1 && \
		t_cand->pos <= cands - t_cand->pos + 1)
	{
		if (t_cand->pos > t_sol->pos)
			moves += t_cand->pos - 1;
		else
			moves += t_sol->pos - 1;
	}
	else if (t_sol->pos > sol - t_sol->pos + 1 && \
			t_cand->pos <= cands - t_cand->pos + 1)
		moves += t_cand->pos + sol - t_sol->pos;
	else
		moves += t_sol->pos + cands - t_cand->pos;
	return (moves + 1);
}

static void	calc_cand(t_stk *cands, t_stk *sol, t_stk **above, t_stk **below)
{
	int		moves;
	int		min_moves;
	int		i;
	t_stk	*t_cand;
	t_stk	*t_sol;

	min_moves = stksize(cands) + stksize(sol);
	i = 0;
	t_cand = cands;
	while (++i <= stksize(cands))
	{
		moves = 0;
		t_sol = sol;
		get_below(t_cand->index, &t_sol);
		moves += calc_mvs(stksize(cands), stksize(sol), t_cand, t_sol);
		if (moves < min_moves)
		{
			min_moves = moves;
			*above = t_cand;
			*below = t_sol;
		}
		t_cand = t_cand->next;
	}
}

static void	next_move(t_stk **cands, t_stk **sol)
{
	t_stk	*above;
	t_stk	*below;

	calc_cand(*cands, *sol, &above, &below);
	if (above->pos > stksize(*cands) - above->pos + 1 && \
			below->pos > stksize(*sol) - below->pos + 1)
		both_dwn(cands, sol, above, below);
	else if (above->pos <= stksize(*cands) - above->pos + 1 && \
			below->pos <= stksize(*sol) - below->pos + 1)
		both_up(cands, sol, above, below);
	else if (above->pos <= stksize(*cands) - above->pos + 1 && \
			below->pos > stksize(*sol) - below->pos + 1)
		up_down(cands, sol, above, below);
	else
		down_up(cands, sol, above, below);
	if ((*cands)->stk_id == 'b')
		pa(sol, cands);
	else
		pb(cands, sol);
}

static void	sort_stk(t_stk **a)
{
	t_stk	*tmp;

	if (!sorted(*a))
	{
		tmp = *a;
		while (tmp->index != 1)
			tmp = tmp->next;
		if (tmp->pos > stksize(*a) - tmp->pos + 1)
		{
			while ((*a)->index != 1)
				revrot(a, 0);
		}
		else
		{
			while ((*a)->index != 1)
				rotate(a, 0);
		}
	}
}

void	push_swap(t_stk **a, t_stk **b)
{
	while (!partially_sorted(*a) || *b)
	{
		if (stksize(*a) <= 3 && !partially_sorted(*a))
			sa(a);
		else if (partially_sorted(*a) && *b)
			next_move(b, a);
		else
		{
			if (!(*b))
			{
				pb(a, b);
				pb(a, b);
				if ((*b)->index < (*b)->next->index)
					sb(b);
			}
			else
				next_move(a, b);
		}
	}
	sort_stk(a);
}
