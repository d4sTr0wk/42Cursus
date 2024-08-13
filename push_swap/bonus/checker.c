/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maxgarci <maxgarci@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/28 23:25:42 by maxgarci          #+#    #+#             */
/*   Updated: 2024/08/13 18:55:58 by maxgarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/include.h"
#include <stdio.h>

static int	perform_op(char *operation, t_stk **a, t_stk **b)
{
	if (ft_strncmp(operation, "sa\n", ft_strlen(operation)) == 0)
		sa(a, MUTE);
	else if (ft_strncmp(operation, "sb\n", ft_strlen(operation)) == 0)
		sb(b, MUTE);
	else if (ft_strncmp(operation, "pa\n", ft_strlen(operation)) == 0)
		pa(a, b, MUTE);
	else if (ft_strncmp(operation, "pb\n", ft_strlen(operation)) == 0)
		pb(a, b, MUTE);
	else if (ft_strncmp(operation, "ra\n", ft_strlen(operation)) == 0)
		rotate(a, MUTE);
	else if (ft_strncmp(operation, "rb\n", ft_strlen(operation)) == 0)
		rotate(b, MUTE);
	else if (ft_strncmp(operation, "rr\n", ft_strlen(operation)) == 0)
		rr(a, b, MUTE);
	else if (ft_strncmp(operation, "rra\n", ft_strlen(operation)) == 0)
		revrot(a, MUTE);
	else if (ft_strncmp(operation, "rrb\n", ft_strlen(operation)) == 0)
		revrot(b, MUTE);
	else if (ft_strncmp(operation, "rrr\n", ft_strlen(operation)) == 0)
		rrr(a, b, MUTE);
	else
		return (1);
	return (0);
}

static void	check(t_stk **a, t_stk **b)
{
	char	*operation;

	operation = get_next_line(0);
	while (operation)
	{
		if (perform_op(operation, a, b))
		{
			ft_putstr_fd("Error\n", 2);
			free(operation);
			return ;
		}
		free(operation);
		operation = get_next_line(0);
	}
	if (sorted(*a) && !*b)
		ft_printf("OK\n");
	else
		ft_printf("KO\n");
}

int	main(int argc, char **argv)
{
	t_stk	*a;
	t_stk	*b;

	a = NULL;
	b = NULL;
	if (initialize_args(argc, argv, &a))
	{
		ft_putstr_fd("Error\n", 2);
		free_stack(&a);
		exit(-1);
	}
	check(&a, &b);
	free_stack(&a);
	return (0);
}
