/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maxgarci <maxgarci@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/08 19:29:39 by maxgarci          #+#    #+#             */
/*   Updated: 2024/08/09 10:37:08 by maxgarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	initial_case(char c, int *error, int *sign, int *j)
{
	if (c == '-')
	{
		*error = 1;
		*sign = -1;
		*j += 1;
	}
	else
	{
		*error = 0;
		*sign = 1;
	}
}

int	check_args(char **args, int argc)
{
	int		i;
	int		j;
	int		sign;
	int		error;
	long	num;

	i = -1;
	while (++i < argc)
	{
		num = 0;
		j = 0;
		initial_case(args[i][j], &error, &sign, &j);
		while (args[i][j])
		{
			if (!ft_isdigit(args[i][j]))
				return (1);
			error = 0;
			num *= 10;
			num += args[i][j++] - '0';
		}
		num *= sign;
		if (num > INT_MAX || num < INT_MIN || error)
			return (1);
	}
	return (0);
}
