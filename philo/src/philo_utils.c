/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maxgarci <maxgarci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/06 10:27:25 by maxgarci          #+#    #+#             */
/*   Updated: 2025/05/08 09:17:48 by maxgarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	am_i_dead(struct timeval *now, struct timeval *last_time,
				long *time_to_die)
{
	long	elapsed_time;

	gettimeofday(now, NULL);
	elapsed_time = (long)(((now->tv_sec * 1000000) + now->tv_usec)
			- ((last_time->tv_sec * 1000000) + last_time->tv_usec));
	if (elapsed_time > *time_to_die)
		return (YES);
	return (NO);
}

int	check_forks_freed(t_philo_data *data, struct timeval *now)
{
	pthread_mutex_lock(&data->forks_mutexes[data->left_fork]);
	pthread_mutex_lock(&data->forks_mutexes[data->right_fork]);
	if (data->forks_taken[data->left_fork] == NO
		&& data->forks_taken[data->right_fork] == NO)
	{
		data->forks_taken[data->left_fork] = YES;
		data->forks_taken[data->right_fork] = YES;
		pthread_mutex_unlock(&data->forks_mutexes[data->left_fork]);
		pthread_mutex_unlock(&data->forks_mutexes[data->right_fork]);
		pthread_mutex_lock(data->echo_mutex);
		gettimeofday(now, NULL);
		printf(RESET "%ld %d has taken fork %d\n",
			(long)(((now->tv_sec * 1000) + (now->tv_usec / 1e3))
				- ((data->init_time->tv_sec * 1000)
					+ (data->init_time->tv_usec / 1e3))),
			data->id, data->left_fork);
		printf(RESET "%ld %d has taken fork %d\n",
			(long)(((now->tv_sec * 1000) + (now->tv_usec / 1e3))
				- ((data->init_time->tv_sec * 1000)
					+ (data->init_time->tv_usec / 1e3))),
			data->id, data->right_fork);
		pthread_mutex_unlock(data->echo_mutex);
		return (FN_SUCESSED);
	}
	pthread_mutex_unlock(&data->forks_mutexes[data->left_fork]);
	pthread_mutex_unlock(&data->forks_mutexes[data->right_fork]);
	return (FN_FAILED);
}

int	is_simulation_active(t_args *args)
{
	int	active;

	pthread_mutex_lock(&args->simulation_mutex);
	active = args->simulation_active;
	pthread_mutex_unlock(&args->simulation_mutex);
	return (active);
}

void	set_simulation_active(t_args *args, int value)
{
	pthread_mutex_lock(&args->simulation_mutex);
	args->simulation_active = value;
	pthread_mutex_unlock(&args->simulation_mutex);
}

void	kill_philosopher(t_philo_data *data, struct timeval *now)
{
	pthread_mutex_lock(data->echo_mutex);
	printf(RED "%ld %d died\n",
		(long)(((now->tv_sec - data->init_time->tv_sec) * 1000)
			+ (long)((now->tv_usec - data->init_time->tv_usec) / 1e3)),
		data->id);
	set_simulation_active(data->args, 0);
	pthread_mutex_unlock(data->echo_mutex);
	free(data);
}
