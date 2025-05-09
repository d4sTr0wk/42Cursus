/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_forks_freed.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maxgarci <maxgarci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/08 15:33:18 by maxgarci          #+#    #+#             */
/*   Updated: 2025/05/08 15:34:57 by maxgarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	take_forks(t_philo_data *data, struct timeval *now)
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
}

int	check_forks_freed(t_philo_data *data, struct timeval *now)
{
	pthread_mutex_lock(&data->forks_mutexes[data->left_fork]);
	pthread_mutex_lock(&data->forks_mutexes[data->right_fork]);
	if (data->forks_taken[data->left_fork] == NO
		&& data->forks_taken[data->right_fork] == NO)
	{
		take_forks(data, now);
		return (FN_SUCESSED);
	}
	pthread_mutex_unlock(&data->forks_mutexes[data->left_fork]);
	pthread_mutex_unlock(&data->forks_mutexes[data->right_fork]);
	return (FN_FAILED);
}
