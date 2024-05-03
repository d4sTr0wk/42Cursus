/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maxgarci <maxgarci@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/28 23:25:42 by maxgarci          #+#    #+#             */
/*   Updated: 2024/03/05 18:58:49 by maxgarci         ###   ########.fr       */
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

static int	initialize_args(int argc, char **argv, t_stk **a)
{
	int	i;
	int	arg;
	
	if (argc < 2)
		return (1);
	if (argc == 2)
	{
		argv = ft_split(argv[1], ' ');
		argc = ft_split_count(argv);
		i = 0;
	}
	else
		i = 1;
	while (i < argc)
	{
		arg = ft_atoi(argv[i]);
		if (stackadd_back(a, stacknew(arg, i)))
			return (1);
		i++;
	}
	assign_index(a);
	return (0);
}

static int ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] && s2[i] && s1[i] == s2[i])
		i++;
	return (s1[i] - s2[i]);
}

void	check(t_stk **a, t_stk **b)
{
	char	*line;

	do	
	{
		line = get_next_line(0);
		if (ft_strcmp(line, "sa") == 0)
			sa(a);
		else if (ft_strcmp(line, "sb\n") == 0)
			sb(b);
		else if (ft_strcmp(line, "pa\n") == 0)
			pa(a, b);
		else if (ft_strcmp(line, "pb\n") == 0)
			pb(b, a);
		else if (ft_strcmp(line, "ra\n") == 0)
			rotate(a, 0);
		else if (ft_strcmp(line, "rb\n") == 0)
			rotate(b, 0);
		else if (ft_strcmp(line, "rr\n") == 0)
			rr(a, b);
		else if (ft_strcmp(line, "rra\n") == 0)
			revrot(a, 0);
		else if (ft_strcmp(line, "rrb\n") == 0)
			revrot(b, 0);
		else if (ft_strcmp(line, "rrr\n") == 0)
			rrr(a, b);
		else if (ft_strcmp(line, "\n") == 0)
		{
			free(line);
			break;
		}
		else
		{
			ft_printf("Error\n");
			free(line);
			break ;
		}
		free(line);
	} while(1);
	
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
