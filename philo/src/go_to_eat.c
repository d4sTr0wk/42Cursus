/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   go_to_eat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maxgarci <maxgarci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/08 15:50:48 by maxgarci          #+#    #+#             */
/*   Updated: 2025/05/12 15:44:33 by maxgarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	free_forks(t_philo_data *data)
{
	pthread_mutex_lock(&data->forks_mutexes[data->left_fork]);
	pthread_mutex_lock(&data->forks_mutexes[data->right_fork]);
	data->forks_taken[data->left_fork] = 0;
	data->forks_taken[data->right_fork] = 0;
	pthread_mutex_unlock(&data->forks_mutexes[data->left_fork]);
	pthread_mutex_unlock(&data->forks_mutexes[data->right_fork]);
}

int	go_to_eat(t_philo_data *data, struct timeval *now)
{
	int	elapsed;

	if (is_simulation_active(data->args) == NO)
		return (free(data), FN_FAILED);
	gettimeofday(&data->last_meal_time, NULL);
	pthread_mutex_lock(data->echo_mutex);
	gettimeofday(now, NULL);
	printf(GREEN "%ld %d is eating\n",
		(long)(((now->tv_sec - data->init_time->tv_sec) * 1000)
			+ (long)((now->tv_usec - data->init_time->tv_usec) / 1e3)),
		data->id);
	printf("init_time: %ld.%06ld, now: %ld.%06ld\n",
		(long)data->init_time->tv_sec, (long)data->init_time->tv_usec,
		(long)now->tv_sec, (long)now->tv_usec);
	pthread_mutex_unlock(data->echo_mutex);
	elapsed = 0;
	while (elapsed < data->args->time_to_eat)
	{
		if (is_simulation_active(data->args) == NO)
			return (free(data), FN_FAILED);
		if (am_i_dead(now, &data->last_meal_time, &data->args->time_to_die,
				data->args))
			return (kill_philosopher(data, now), FN_FAILED);
		usleep(INTERVAL_NAP);
		elapsed += INTERVAL_NAP;
	}
	gettimeofday(&data->last_meal_time, NULL);
	free_forks(data);
	return (FN_SUCESSED);
}
