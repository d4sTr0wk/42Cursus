/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   go_to_sleep.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maxgarci <maxgarci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/08 15:47:37 by maxgarci          #+#    #+#             */
/*   Updated: 2025/05/12 15:43:49 by maxgarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	go_to_sleep(t_philo_data *data, struct timeval *now)
{
	int	elapsed;

	if (is_simulation_active(data->args) == NO)
		return (free(data), FN_FAILED);
	pthread_mutex_lock(data->echo_mutex);
	gettimeofday(now, NULL);
	printf(MAGENTA "%ld %d is sleeping\n",
		(long)(((now->tv_sec - data->init_time->tv_sec) * 1000)
			+ (long)((now->tv_usec - data->init_time->tv_usec) / 1e3)),
		data->id);
	printf("init_time: %ld.%06ld, now: %ld.%06ld\n",
		(long)data->init_time->tv_sec, (long)data->init_time->tv_usec,
		(long)now->tv_sec, (long)now->tv_usec);
	pthread_mutex_unlock(data->echo_mutex);
	elapsed = 0;
	while (elapsed < data->args->time_to_sleep)
	{
		if (is_simulation_active(data->args) == NO)
			return (free(data), FN_FAILED);
		if (am_i_dead(now, &data->last_meal_time, &data->args->time_to_die,
				data->args))
			return (kill_philosopher(data, now), FN_FAILED);
		usleep(INTERVAL_NAP);
		elapsed += INTERVAL_NAP;
	}
	return (FN_SUCESSED);
}
