/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maxgarci <maxgarci@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/28 23:25:42 by maxgarci          #+#    #+#             */
/*   Updated: 2024/01/28 23:25:42 by maxgarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	initialize_args(int argc, char **argv)
{
	int	i;
	int	arg;
	int	error;

	error = 0;
	if (!argc)
		return (1);
	i = 0;
	while (i < argc)
	{
		arg = ft_atoi(argv[i], &error);
		if (arg == 0 && error == 1)
			return (1);
		i++;
	}
	return (0);
}

int main(int argc, char **argv)
{
	if (initialize_args(argc, argv))
	{
		ft_printf("Error\n");
		exit(-1);
	}
	ft_printf("Hola");
	exit(0);
}