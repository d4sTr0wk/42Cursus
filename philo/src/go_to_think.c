/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   go_to_think.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maxgarci <maxgarci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/08 15:43:47 by maxgarci          #+#    #+#             */
/*   Updated: 2025/05/12 15:47:00 by maxgarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	go_to_think(t_philo_data *data, struct timeval *now)
{
	if (is_simulation_active(data->args) == NO)
		return ;
	pthread_mutex_lock(data->echo_mutex);
	gettimeofday(now, NULL);
	printf(BLUE "%ld %d is thinking\n",
		(long)(((now->tv_sec * 1000) + (now->tv_usec / 1e3))
			- ((data->init_time->tv_sec * 1000)
				+ (data->init_time->tv_usec / 1e3))),
		data->id);
	printf("init_time: %ld.%06ld, now: %ld.%06ld\n",
		(long)data->init_time->tv_sec, (long)data->init_time->tv_usec,
		(long)now->tv_sec, (long)now->tv_usec);
	pthread_mutex_unlock(data->echo_mutex);
}
