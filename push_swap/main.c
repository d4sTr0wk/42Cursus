/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maxgarci <maxgarci@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/28 23:25:42 by maxgarci          #+#    #+#             */
/*   Updated: 2024/01/30 18:55:23 by maxgarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	initialize_args(int argc, char **argv, t_stack **a)
{
	int	i;
	int	arg;
	int	error;

	error = 0;
	if (argc < 2)
		return (1);
	i = 1;
	while (i < argc)
	{
		arg = ft_atoi(argv[i], &error);
		if (arg == 0 && error == 1)
			return (1);
		ft_stackadd_back(a, ft_stacknew(arg));
		i++;
	}
	assign_index(a);
	return (0);
}

int	main(int argc, char **argv)
{
	t_stack	*a;

	a = NULL;
	if (initialize_args(argc, argv, &a))
	{
		ft_printf("Error\n");
		exit(-1);
	}
	show_stack(a);
	push_swap(&a);
	ft_printf("\n\nRESULTADO:\n");
	show_stack(a);

	exit(0);
}
