/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maxgarci <maxgarci@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/28 23:25:42 by maxgarci          #+#    #+#             */
/*   Updated: 2024/03/17 17:00:25 by maxgarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/include.h"

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

static int	initialize_args(int *argc, char **argv, t_stk **a)
{
	int	i;
	int	arg;
	int	error;
	char	**args;

	error = 0;
	if (*argc < 2)
		return (1);
	if (*argc == 2)
	{
		args = ft_split(argv[1], ' ');
		*argc = ft_split_count(args);
		i = 0;
		error = -1;
	}
	else
	{
		args = argv;
		i = 1;
	}
	while (i < *argc)
	{
		arg = ft_atoi(args[i]);
		if ((arg == 0 && error == 1) || stackadd_back(a, stacknew(arg, i)))
			return (1);
		i++;
	}
	assign_index(a);
	if (error == -1)
		free_args(args, *argc);
	return (0);
}

int	main(int argc, char **argv)
{
	t_stk	*a;
	t_stk	*b;

	a = NULL;
	b = NULL;
	if (initialize_args(&argc, argv, &a) || argc == 0)
	{
		write(2, "Error", 5);
		free_stack(&a);
		exit(-1);
	}
	push_swap(&a, &b);
	free_stack(&a);
	return (0);
}
