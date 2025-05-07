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

static pthread_mutex_t	*init_forks(int nforks)
{
	pthread_mutex_t	*forks_mutex;

	forks_mutex = (pthread_mutex_t *)malloc(sizeof(pthread_mutex_t) * nforks);
	return (forks_mutex);
}

int	main(int argc, char **argv)
{
	int					valid_args;
	t_args				arguments;
	pthread_t			*philosophers;
	pthread_mutex_t		echo_mutex;
	pthread_mutex_t		*forks_mutexes;

	valid_args = args_are_valid(argc, argv, &arguments);
	philosophers = NULL;
	if (!valid_args)
	{
		forks_mutexes = init_forks(arguments.nphilosophers);
		if (forks_mutexes == NULL)
			return (ft_putstr_fd("Failed allocating forks' mutexes!", 2),
				FN_FAILED);
		if (init_philosophers(&arguments, &philosophers, &echo_mutex,
				forks_mutexes))
			return (free(forks_mutexes), FN_FAILED);
		if (!philosophers)
			return (free(forks_mutexes), FN_FAILED);
	}
	else
		return (valid_args);
	free(forks_mutexes);
	return (FN_SUCESSED);
}
