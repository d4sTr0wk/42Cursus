/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maxgarci <maxgarci@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/28 23:25:42 by maxgarci          #+#    #+#             */
/*   Updated: 2024/01/29 11:42:37 by maxgarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	initialize_args(int argc, char **argv, t_stack **a)
{
	int	i;
	int	arg;
	int	error;

	error = 0;
	if (!argc)
		return (1);
	i = 1;
	while (i < argc)
	{
		arg = ft_atoi(argv[i], &error);
		if (arg == 0 && error == 1)
			return (1);
		ft_lstadd_back(a, ft_lstnew(arg));
		i++;
	}
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
	ft_printf("Hola");
	exit(0);
}
