/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maxgarci <maxgarci@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 09:14:39 by maxgarci          #+#    #+#             */
/*   Updated: 2025/02/08 22:16:59 by maxgarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/philo.h"
#include <stdio.h>

static int	args_are_valid(int argc, char **args __attribute__((unused)), t_args *arguments)
{
	if (argc <= 4)
		return (print_error(ARGS_NUM_ERROR));
	arguments->nphilosophers = ft_atoi(args[1]);
	if (arguments->nphilosophers <= 0)
		return (print_error(INVALID_NPHIL));
	arguments->time_to_die = ft_atoi(args[2]);
	if (arguments->time_to_die <= 0)
		return (print_error(INVALID_TIME_2_DIE));
	arguments->time_to_eat = ft_atoi(args[3]);
	if (arguments->time_to_eat <= 0)
		return (print_error(INVALID_TIME_2_EAT));
	arguments->time_to_sleep = ft_atoi(args[4]);
	if (arguments->time_to_sleep <= 0)
		return (print_error(INVALID_TIME_2_SLEEP));
	return (FN_SUCESSED);
}

int main(int argc, char **argv) 
{
	int		valid_args;
	t_args	arguments;

	valid_args = args_are_valid(argc, argv, &arguments);
	if (!valid_args)
		printf("Todo ha ido bien");
	else
		return (valid_args);
}
