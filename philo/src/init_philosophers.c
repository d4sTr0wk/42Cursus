/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_philosophers.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maxgarci <maxgarci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/08 08:05:33 by maxgarci          #+#    #+#             */
/*   Updated: 2025/05/10 11:53:08 by maxgarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	create_philosophers(t_args *args, unsigned char *forks_taken,
	pthread_mutex_t **mutexes, pthread_t **philosophers)
{
	int				i;
	t_philo_data	*data;
	struct timeval	*init_time;

	i = -1;
	init_time = (struct timeval *)malloc(sizeof(struct timeval));
	gettimeofday(init_time, NULL);
	while (++i < args->nphilosophers)
	{
		data = (t_philo_data *)malloc(sizeof(t_philo_data));
		if (!data)
			return (ft_putstr_fd("Allocating memory error", 2), FN_FAILED);
		data->forks_taken = forks_taken;
		data->args = args;
		data->id = i;
		data->in_queue = NO;
		data->left_fork = data->id;
		data->right_fork = (data->id + 1) % data->args->nphilosophers;
		data->echo_mutex = mutexes[0];
		data->forks_mutexes = mutexes[1];
		data->init_time = init_time;
		if (pthread_create(&(*philosophers)[i], NULL, run_philo, data))
			return (ft_putstr_fd("Error creating thread", 2), free(data), i);
	}
	return (i);
}

static int	init_forks_mutexes(pthread_mutex_t *forks_mutexes, int nforks)
{
	int	i;

	i = -1;
	while (++i < nforks)
	{
		if (pthread_mutex_init(&forks_mutexes[i], NULL))
		{
			while (--i >= 0)
				pthread_mutex_destroy(&forks_mutexes[i]);
			return (FN_FAILED);
		}
	}
	return (FN_SUCESSED);
}

static int	init_fork_queue(t_args *args)
{
	args->fqueue = (t_fork_queue *)malloc(sizeof(t_fork_queue));
	if (args->fqueue == NULL)
		return (ft_putstr_fd("Allocating fork queue error", 2), FN_FAILED);
	args->fqueue->front = NULL;
	pthread_mutex_init(&args->fqueue->queue_mutex, NULL);
	return (FN_SUCESSED);
}

static int	init_variables(t_args *args, pthread_t **philosophers,
	pthread_mutex_t **mutexes, unsigned char **forks_taken)
{
	int	i;

	*philosophers = (pthread_t *)malloc(sizeof(pthread_t)
			* args->nphilosophers);
	*forks_taken = (unsigned char *)malloc(sizeof(unsigned char) * args->nphilosophers);
	if (!*philosophers || !*forks_taken)
	{
		if (*philosophers)
			free(*philosophers);
		if (*forks_taken)
			free(*forks_taken);
		ft_putstr_fd("Allocating memory error", 2);
		return (FN_FAILED);
	}
	if (init_forks_mutexes(mutexes[1], args->nphilosophers))
		return (free(*philosophers), free(*forks_taken), FN_FAILED);
	if (init_fork_queue(args))
		return (free(*philosophers), free(*forks_taken), FN_FAILED);
	if (pthread_mutex_init(mutexes[0], NULL)
		|| pthread_mutex_init(&args->simulation_mutex, NULL))
		return (free(*philosophers), free(*forks_taken), FN_FAILED);
	i = -1;
	while (++i < args->nphilosophers)
		(*forks_taken)[i] = NO;
	return (FN_SUCESSED);
}

int	init_philosophers(t_args *args, pthread_t **philosophers,
	pthread_mutex_t *echo_mutex, pthread_mutex_t *forks_mutex)
{
	int				i;
	unsigned char	*forks_taken;

	forks_taken = NULL;
	if (init_variables(args, philosophers,
			(pthread_mutex_t *[2]){echo_mutex, forks_mutex}, &forks_taken))
		return (FN_FAILED);
	i = create_philosophers(args, forks_taken,
			(pthread_mutex_t *[2]){echo_mutex, forks_mutex}, philosophers);
	if (i < args->nphilosophers)
	{
		while (--i >= 0)
			pthread_join((*philosophers)[i], NULL);
		destroy_forks_mutexes(forks_mutex, args->nphilosophers);
		return (free(*philosophers), free(forks_taken),
			pthread_mutex_destroy(echo_mutex),
			pthread_mutex_destroy(&args->simulation_mutex), FN_FAILED);
	}
	i = -1;
	while (++i < args->nphilosophers)
		pthread_join((*philosophers)[i], NULL);
	return (end_philosophers((pthread_mutex_t *[3]){echo_mutex, forks_mutex,
			&args->simulation_mutex}, args->nphilosophers, philosophers,
		forks_taken));
}
