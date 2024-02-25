/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maxgarci <maxgarci@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 14:29:02 by maxgarci          #+#    #+#             */
/*   Updated: 2024/02/25 15:37:23 by maxgarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	get_below(int above_index, t_stack **tmp_sol)
{
	t_stack	*tmp;
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

void	calc_cand(t_stack *candidates, t_stack *solution, t_stack **above, t_stack **below, int conf)
{
	int		moves;
	int		min_moves;
	int		i;
	t_stack	*tmp_cand;
	t_stack	*tmp_sol;

	if (stacksize(candidates) > stacksize(solution))
		min_moves = stacksize(candidates) + 1;
	else
		min_moves = stacksize(solution) + 1;
	i = 0;
	while (++i <= stacksize(candidates))
	{
		moves = 0;
		tmp_cand = candidates;
		while (tmp_cand->pos != i)
			tmp_cand = tmp_cand->next;
		tmp_sol = solution;
		while (tmp_sol->next && tmp_cand->index < tmp_sol->index && !conf)
			tmp_sol = tmp_sol->next;
		if (conf)
			get_below(tmp_cand->index, &tmp_sol);
		if (!tmp_sol->next)
			moves += 2;
		else
		{
			if (tmp_sol->pos > stacksize(solution) - tmp_sol->pos + 1 && \
				tmp_cand->pos > stacksize(candidates) - tmp_cand->pos + 1)
			{
				if (stacksize(candidates) - tmp_cand->pos > stacksize(solution) - tmp_sol->pos)
					moves += stacksize(candidates) - tmp_cand->pos + 1;
				else
					moves += stacksize(solution) - tmp_sol->pos + 1;
			}
			else if (tmp_sol->pos <= stacksize(solution) - tmp_sol->pos + 1 && \
				tmp_cand->pos <= stacksize(candidates) - tmp_cand->pos + 1)
			{
				if (tmp_cand->pos > tmp_sol->pos)
					moves += tmp_cand->pos - 1;
				else
					moves += tmp_sol->pos - 1;
			}
			else if (tmp_sol->pos > stacksize(solution) - tmp_sol->pos + 1 && \
					tmp_cand->pos <= stacksize(candidates) - tmp_cand->pos + 1)
				moves += tmp_cand->pos + stacksize(solution) - tmp_sol->pos;
			else
				moves += tmp_sol->pos + stacksize(candidates) - tmp_cand->pos;
			moves += 1;
		}
		if (moves < min_moves)
		{
			min_moves = moves;
			*above = tmp_cand;
			*below = tmp_sol;
		}
	}
}

void	next_move(t_stack **cands, t_stack **sol, int conf)
{
	t_stack	*above;
	t_stack	*below;

	calc_cand(*cands, *sol, &above, &below, conf);
	if (below->pos > stacksize(*sol) - below->pos + 1 && \
			above->pos > stacksize(*cands) - above->pos + 1)
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
	else if (below->pos <= stacksize(*sol) - below->pos + 1 && \
			above->pos <= stacksize(*cands) - above->pos + 1)
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
	else if (below->pos > stacksize(*sol) - below->pos + 1 && \
			above->pos <= stacksize(*cands) - above->pos + 1)
	{
		while ((*sol)->index != below->index)
			rra(sol);
		while ((*cands)->index != above->index)
			rb(cands);
	}
	else
	{
		while ((*sol)->index != below->index)
			ra(sol);
		while ((*cands)->index != above->index)
			rrb(cands);
	}
	if (conf)
		pa(sol, cands);
	else
		pb(cands, sol);
}

void	push_swap(t_stack **a, t_stack **b)
{
	t_stack	*tmp;
	int		i;

	while (!partially_sorted(*a) || *b)
	{
		if (stacksize(*a) <= 3 && !partially_sorted(*a))
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
	if (!sorted(*a))
	{
		tmp = *a;
		while (tmp->index != 1)
			tmp = tmp->next;
		if (tmp->pos > stacksize(*a) - tmp->pos + 1)
		{
			i = stacksize(*a) - tmp->pos;
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
