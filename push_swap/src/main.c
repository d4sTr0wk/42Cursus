/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maxgarci <maxgarci@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/28 23:25:42 by maxgarci          #+#    #+#             */
/*   Updated: 2024/06/11 13:41:07 by maxgarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/include.h"

static void	check_args(char **args, int argc, int *error)
{
	int	i;
	int	j;

	i = 0;
	while (i < argc)
	{
		j = 0;
		if (args[i][j] == '-')
			j++;
		while (args[i][j])
		{
			if (!ft_isdigit(args[i][j]))
			{
				*error = 1;
				return ;
			}
			j++;
		}
		i++;
	}
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
	int	i;
	int	arg;
	int	error;
	char	**args;

	error = 0;
	if (argc < 2)
		return (1);
	if (argc == 2)
	{
		if (argv[1][0] == '\0')
			return (1);
		args = ft_split(argv[1], ' ');
		argc = ft_split_count(args);
	}
	else
	{
		args = argv + 1;
		argc -= 1;
	}
	check_args(args, argc, &error);
	i = 0;
	while (i < argc && error != 1)
	{
		arg = ft_atoi(args[i]);
		stackadd_back(a, stacknew(arg, i));
		i++;
	}
	if (error == 1)
		return (1);
	assign_index(a);
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
