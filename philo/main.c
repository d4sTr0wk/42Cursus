/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maxgarci <maxgarci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 09:14:39 by maxgarci          #+#    #+#             */
/*   Updated: 2025/05/06 17:46:13 by maxgarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/philo.h"

static int	args_are_valid(int argc, char **args __attribute__((unused)),
							t_args *arguments)
{
	if (argc <= 4 || argc > 6)
		return (print_error(ARGS_NUM_ERROR));
	arguments->nphilosophers = ft_atoi(args[1]);
	if (arguments->nphilosophers <= 1 || arguments->nphilosophers >= 200)
		return (print_error(INVALID_NPHIL));
	arguments->time_to_die = ft_atoi(args[2]) * MILLI_TO_MICRO;
	if (arguments->time_to_die <= 0)
		return (print_error(INVALID_TIME_2_DIE));
	arguments->time_to_eat = ft_atoi(args[3]) * MILLI_TO_MICRO;
	if (arguments->time_to_eat <= 0)
		return (print_error(INVALID_TIME_2_EAT));
	arguments->time_to_sleep = ft_atoi(args[4]) * MILLI_TO_MICRO;
	if (arguments->time_to_sleep <= 0)
		return (print_error(INVALID_TIME_2_SLEEP));
	if (argc == 6)
	{
		arguments->ntimes_eat = ft_atoi(args[5]);
		if (arguments->ntimes_eat <= 0)
			return (print_error(INVALID_NTIMES_EAT));
	}
	else
		arguments->ntimes_eat = -1;
	arguments->simulation_active = 1;
	return (FN_SUCESSED);
}

int	main(int argc, char **argv)
{
	int					valid_args;
	t_args				arguments;
	pthread_t			*philosophers;
	pthread_mutex_t		echo_mutex;
	pthread_mutex_t		forks_mutex;

	valid_args = args_are_valid(argc, argv, &arguments);
	philosophers = NULL;
	if (!valid_args)
	{
		if (init_philosophers(&arguments, &philosophers, &echo_mutex,
				&forks_mutex))
			return (1);
		if (!philosophers)
			return (1);
	}
	else
		return (valid_args);
	return (0);
}
