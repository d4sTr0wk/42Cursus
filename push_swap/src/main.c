/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maxgarci <maxgarci@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/28 23:25:42 by maxgarci          #+#    #+#             */
/*   Updated: 2024/08/08 10:55:06 by maxgarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/include.h"

static int	check_args(char **args, int argc)
{
	int		i;
	int		j;
	int		sign;
	long	num;
	int		error;

	i = 0;
	while (i < argc && !*error)
	{
		num = 0;
		j = 0;
		sign = 1;
		if (args[i][j] == '-')
		{
			j++;
			error = 1;
			sign = -1;
		}
		while (args[i][j])
		{
			num *= 10;
			error = 0;
			if (!ft_isdigit(args[i][j]))
			{
				error = 1;
				return ;
			}
			num += args[i][j] - '0';
			j++;
		}
		num *= sign;
		if (num > INT_MAX || num < INT_MIN)
			error = 1;
		i++;
	}
	return (error);
}

static void	free_stack(t_stk **a)
{
	t_stk	*tmp;

	while (*a)
	{
		tmp = *a;
		*a = (*a)->next;
		free(tmp);
	}
}

static int	initialize_args(int argc, char **argv, t_stk **a)
{
	int		i;
	int		free_args;
	char	**args;

	if (argc < 2)
		return (1);
	if (argc == 2)
	{
		if (argv[1][0] == '\0')
			return (1);
		args = ft_split(argv[1], ' ');
		argc = ft_split_count(args);
		free_args = 1;
	}
	else
	{
		args = argv + 1;
		argc -= 1;
		free_args = 0;
	}
	i = 0;
	if (check_args(args, argc))
		return (1);
	while (i < argc)
	{
		if (stackadd_back(a, stacknew(ft_atoi(args[i]), i)))
			return (1);
		i++;
	}
	assign_index(a);
	if (free_args)
	{
		i = 0;
		while (i < argc)
		{
			free(args[i]);
			i++;
		}
		free(args);
	}
	return (0);
}

int	main(int argc, char **argv)
{
	t_stk	*a;
	t_stk	*b;

	a = NULL;
	b = NULL;
	if (argc == 0 || initialize_args(argc, argv, &a))
	{
		write(2, "Error", 5);
		free_stack(&a);
		exit(-1);
	}
	push_swap(&a, &b);
	free_stack(&a);
	return (0);
}
