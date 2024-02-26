/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maxgarci <maxgarci@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 14:29:02 by maxgarci          #+#    #+#             */
/*   Updated: 2024/02/26 14:50:22 by maxgarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	get_below(int above_index, t_stk **tmp_sol)
{
	t_stk	*tmp;
	int		check;

	tmp = *tmp_sol;
	check = 0;
	while (tmp)
	{
		if (above_index < tmp->index && \
				(!check || (check && tmp->index < (*tmp_sol)->index)))
		{
			check = 1;
			*tmp_sol = tmp;
		}
		tmp = tmp->next;
	}
	if (!check)
	{
		tmp = *tmp_sol;
		while (tmp)
		{
			if (tmp->index < (*tmp_sol)->index)
				*tmp_sol = tmp;
			tmp = tmp->next;
		}
	}
}

int	calc_mvs(int cands, int sol, t_stk *t_sol, t_stk *t_cand)
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

void	calc_cand(t_stk *cands, t_stk *sol, t_stk **above, t_stk **below, int conf)
{
	int		moves;
	int		min_moves;
	int		i;
	t_stk	*t_cand;
	t_stk	*t_sol;

	if (stksize(cands) > stksize(sol))
		min_moves = stksize(cands) + 1;
	else
		min_moves = stksize(sol) + 1;
	i = 0;
	while (++i <= stksize(cands))
	{
		moves = 0;
		t_cand = cands;
		while (t_cand->pos != i)
			t_cand = t_cand->next;
		t_sol = sol;
		while (t_sol->next && t_cand->index < t_sol->index && !conf)
			t_sol = t_sol->next;
		if (conf)
			get_below(t_cand->index, &t_sol);
		moves += calc_mvs(stksize(cands), stksize(sol), t_cand, t_sol);
		if (moves < min_moves)
		{
			min_moves = moves;
			*above = t_cand;
			*below = t_sol;
		}
	}
}

void	next_move(t_stk **cands, t_stk **sol, int conf)
{
	t_stk	*above;
	t_stk	*below;

	calc_cand(*cands, *sol, &above, &below, conf);
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
	if (conf)
		pa(sol, cands);
	else
		pb(cands, sol);
}

void	sort_stk(t_stk **a)
{
	t_stk	*tmp;
	int		i;

	if (!sorted(*a))
	{
		tmp = *a;
		while (tmp->index != 1)
			tmp = tmp->next;
		if (tmp->pos > stksize(*a) - tmp->pos + 1)
		{
			i = stksize(*a) - tmp->pos;
			while ((i--) >= 0)
				rra(a);
		}
		else
		{
			i = tmp->pos;
			while ((i--) != 1)
				ra(a);
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
			next_move(b, a, 1);
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
				next_move(a, b, 0);
		}
	}
	sort_stk(a);
}
