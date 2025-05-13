/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maxgarci <maxgarci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/06 10:27:25 by maxgarci          #+#    #+#             */
/*   Updated: 2025/05/13 19:34:03 by maxgarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	am_i_dead(struct timeval *now, struct timeval *last_time,
				long *time_to_die, t_args *args)
{
	long	elapsed_time;

	if (!is_simulation_active(args))
		return (NO);
	gettimeofday(now, NULL);
	elapsed_time = (long)(((now->tv_sec * 1000000) + now->tv_usec)
			- ((last_time->tv_sec * 1000000) + last_time->tv_usec));
	if (elapsed_time > *time_to_die)
		return (YES);
	return (NO);
}

int	is_simulation_active(t_args *args)
{
	int	active;

	pthread_mutex_lock(&args->simulation_mutex);
	active = args->simulation_active;
	pthread_mutex_unlock(&args->simulation_mutex);
	return (active);
}

void	kill_philosopher(t_philo_data *data, struct timeval *now)
{
	pthread_mutex_lock(&data->args->simulation_mutex);
	if (data->args->simulation_active == YES)
	{
		data->args->simulation_active = NO;
		pthread_mutex_lock(data->echo_mutex);
		printf(RED "%ld %d died\n",
			(long)(((now->tv_sec - data->init_time->tv_sec) * 1000)
				+ (long)((now->tv_usec - data->init_time->tv_usec) / 1e3)),
			data->id);
		pthread_mutex_unlock(data->echo_mutex);
	}
	pthread_mutex_unlock(&data->args->simulation_mutex);
	free(data);
}
