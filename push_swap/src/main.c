/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maxgarci <maxgarci@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/28 23:25:42 by maxgarci          #+#    #+#             */
/*   Updated: 2024/03/05 15:28:25 by maxgarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/include.h"

static int	initialize_args(int argc, char **argv, t_stk **a)
{
	int	i;
	int	arg;
	int	error;

	error = 0;
	if (argc < 2)
		return (1);
	if (argc == 2)
	{
		argv = ft_split(argv[1], ' ');
		argc = ft_split_count(argv);
	}
	i = 1;
	while (i < argc)
	{
		arg = ft_atoi(argv[i], &error);
		if (arg == 0 && error == 1)
			return (1);
		stackadd_back(a, stacknew(arg, i));
		i++;
	}
	assign_index(a);
	return (0);
}

void	free_stack(t_stk **a)
{
	t_stk	*tmp;

	while (*a)
	{
		tmp = *a;
		*a = (*a)->next;
		free(tmp);
	}
}

int	main(int argc, char **argv)
{
	t_stk	*a;
	t_stk	*b;

	a = NULL;
	b = NULL;
	if (initialize_args(argc, argv, &a))
	{
		ft_printf("Error\n");
		exit(-1);
	}
	push_swap(&a, &b);
	show_stack(a, b);
	free_stack(&a);
	return (0);
}
