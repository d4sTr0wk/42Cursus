/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maxgarci <maxgarci@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 14:29:02 by maxgarci          #+#    #+#             */
/*   Updated: 2024/02/12 19:25:44 by maxgarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	get_below(int above_index, t_stack **tmp_sol)
{
	t_stack	*tmp;
	int check;

	tmp = *tmp_sol;
	check = 0;
	while (tmp)
	{
		if (above_index < tmp->index && (!check || (check && tmp->index < (*tmp_sol)->index)))
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
	int	moves;
	int	min_moves;
	int	i;
	t_stack	*tmp_cand;
	t_stack	*tmp_sol;

	if (ft_stacksize(candidates) > ft_stacksize(solution))
		min_moves = ft_stacksize(candidates) + 1;
	else
		min_moves = ft_stacksize(solution) + 1;
	i = 0;
	while (++i <= ft_stacksize(candidates))
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
			if (tmp_sol->pos > ft_stacksize(solution) - tmp_sol->pos + 1 && tmp_cand->pos > ft_stacksize(candidates) - tmp_cand->pos + 1)
			{
				if (ft_stacksize(candidates) > ft_stacksize(solution))
			       		moves += ft_stacksize(candidates) - tmp_cand->pos + 1;	
				else
					moves += ft_stacksize(solution) - tmp_sol->pos + 1;
			}
			else if (tmp_sol->pos <= ft_stacksize(solution) - tmp_sol->pos + 1 && tmp_cand->pos <= ft_stacksize(candidates) - tmp_cand->pos + 1)
			{
				if (tmp_cand->pos > tmp_sol->pos)
					moves += tmp_cand->pos - 1;
				else
					moves += tmp_sol->pos - 1;
			}
			else if(tmp_sol->pos > ft_stacksize(solution) - tmp_sol->pos + 1 && tmp_cand->pos <= ft_stacksize(candidates) - tmp_cand->pos + 1)
				moves += tmp_cand->pos + ft_stacksize(solution) - tmp_sol->pos;
			else
				moves += tmp_sol->pos + ft_stacksize(candidates) - tmp_cand->pos;
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

void	push_swap(t_stack **a)
{
	t_stack	*b;
	t_stack	*tmp;
	int	i;
	t_stack	*above;
	t_stack	*below;

	b = NULL;
	while (!partially_sorted(*a) || b)
	{
		if (ft_stacksize(*a) <= 3 && !partially_sorted(*a))
			sa(a);
		else if (partially_sorted(*a) && b)
		{
			calc_cand(b, *a, &above, &below, 1);
			if (below->pos > ft_stacksize(*a) - below->pos + 1 && above->pos > ft_stacksize(b) - above->pos + 1)
			{
				if (ft_stacksize(b) > ft_stacksize(*a))
			       	{
					while ((*a)->index != below->index)
						rrr(a, &b);
					while (b->index != above->index)
						rrb(&b);
				}		
				else
				{
					while (b->index != above->index)
						rrr(a, &b);
					while ((*a)->index != below->index)
						rra(a);	
				}
			}
			else if (below->pos <= ft_stacksize(*a) - below->pos + 1 && above->pos <= ft_stacksize(b) - above->pos + 1)
			{
				if (above->pos > below->pos)
				{
					while ((*a)->index != below->index)
						rr(a, &b);
					while (b->index != above->index)
						rb(&b);
				}
				else
				{
					while (b->index != above->index)
						rr(a, &b);
					while ((*a)->index != below->index)
						ra(a);
				}
			}
			else if(below->pos > ft_stacksize(*a) - below->pos + 1 && above->pos <= ft_stacksize(b) - above->pos + 1)
			{
				while ((*a)->index != below->index)
					rra(a);
				while (b->index != above->index)
					rb(&b);
			}
			else
			{
				while ((*a)->index != below->index)
					ra(a);
				while (b->index != above->index)
					rrb(&b);
			}
			pa(a, &b);
		}
		else
		{
			if (!b)
			{
				pb(a, &b);
				pb(a, &b);
				if (b->index < b->next->index)
					sb(&b);
			}
			else
			{

			}	
		}
	}
	if (!sorted(*a))
	{
		tmp = *a;
		while (tmp->index != 1)
			tmp = tmp->next;
		if (tmp->pos > ft_stacksize(*a) - tmp->pos + 1)
		{
			i = ft_stacksize(*a) - tmp->pos;
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
