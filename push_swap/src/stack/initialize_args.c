/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize_args.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maxgarci <maxgarci@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/08 18:46:29 by maxgarci          #+#    #+#             */
/*   Updated: 2024/08/09 12:40:46 by maxgarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	assign_index(t_stk **stack)
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

static int	ft_split_count(char **tab)
{
	int	i;

	i = 0;
	while (tab[i])
		i++;
	return (i);
}

static void	free_args(char **args, int argc)
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

static char	**create_args(int *argc, char **argv, int *args_splitted)
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

int	initialize_args(int argc, char **argv, t_stk **a)
{
	int		i;
	int		args_splitted;
	char	**args;

	if ((argc == 2 && argv[1][0] == '\0') || argc == 1)
		return (1);
	args = create_args(&argc, argv, &args_splitted);
	if (check_args(args, argc))
	{
		if (args_splitted)
			free_args(args, argc);
		return (1);
	}
	i = 0;
	while (i < argc)
	{
		if (stackadd_back(a, stacknew(ft_atoi(args[i]), i)))
			return (1);
		i++;
	}
	assign_index(a);
	if (args_splitted)
		free_args(args, argc);
	return (0);
}
