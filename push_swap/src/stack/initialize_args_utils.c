/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize_args_utils.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maxgarci <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/18 20:07:34 by maxgarci          #+#    #+#             */
/*   Updated: 2024/08/18 20:08:56 by maxgarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	assign_index(t_stk **stack)
{
	int		cnt;
	t_stk	*tmp1;
	t_stk	*tmp2;

	tmp1 = *stack;
	while (tmp1)
	{
		cnt = 1;
		tmp2 = *stack;
		while (tmp2)
		{
			if (tmp1->value > tmp2->value)
				cnt++;
			tmp2 = tmp2->next;
		}
		tmp1->index = cnt;
		tmp1 = tmp1->next;
	}
}

int	ft_split_count(char **tab)
{
	int	i;

	i = 0;
	while (tab[i])
		i++;
	return (i);
}

void	free_args(char **args, int argc)
{
	int	i;

	i = 0;
	while (i < argc)
	{
		free(args[i]);
		i++;
	}
	free(args);
}

char	**create_args(int *argc, char **argv, int *args_splitted)
{
	char	**args;

	if (*argc == 2)
	{
		args = ft_split(argv[1], ' ');
		*argc = ft_split_count(args);
		*args_splitted = 1;
	}
	else
	{
		args = argv + 1;
		*argc -= 1;
		*args_splitted = 0;
	}
	return (args);
}

int	add_elems_stk(t_stk **a, int argc, char **args)
{
	int	i;

	i = -1;
	while (++i < argc)
	{
		if (stackadd_back(a, stacknew(ft_atoi(args[i]), i)))
			return (1);
	}
	return (0);
}
