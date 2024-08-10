/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maxgarci <maxgarci@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/28 23:25:42 by maxgarci          #+#    #+#             */
/*   Updated: 2024/08/10 21:36:51 by maxgarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/include.h"
#include <stdio.h>

static void	check(t_stk **a, t_stk **b)
{
	char	*line;

	line = get_next_line(0);
	while (1)	
	{
		if (ft_strncmp(line, "sa\n", ft_strlen(line)) == 0)
			sa(a);
		else if (ft_strncmp(line, "sb\n", ft_strlen(line)) == 0)
			sb(b);
		else if (ft_strncmp(line, "pa\n", ft_strlen(line)) == 0)
			pa(a, b);
		else if (ft_strncmp(line, "pb\n", ft_strlen(line)) == 0)
			pb(b, a);
		else if (ft_strncmp(line, "ra\n", ft_strlen(line)) == 0)
			rotate(a, 0);
		else if (ft_strncmp(line, "rb\n", ft_strlen(line)) == 0)
			rotate(b, 0);
		else if (ft_strncmp(line, "rr\n", ft_strlen(line)) == 0)
			rr(a, b);
		else if (ft_strncmp(line, "rra\n", ft_strlen(line)) == 0)
			revrot(a, 0);
		else if (ft_strncmp(line, "rrb\n", ft_strlen(line)) == 0)
			revrot(b, 0);
		else if (ft_strncmp(line, "rrr\n", ft_strlen(line)) == 0)
			rrr(a, b);
		else if (ft_strncmp(line, "\n", ft_strlen(line)) == 0)
		{
			free(line);
			break ;
		}
		else
		{
			ft_printf("Error\n");
			free(line);
			break ;
		}
		free(line);
		line = get_next_line(0);
	} while (1);
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
		ft_printf("Error\n");
		free_stack(&a);
		exit(-1);
	}
	check(&a, &b);
	free_stack(&a);
	return (0);
}
