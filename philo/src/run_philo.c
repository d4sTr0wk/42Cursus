/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run_philo.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maxgarci <maxgarci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/06 10:18:02 by maxgarci          #+#    #+#             */
/*   Updated: 2025/05/06 18:34:05 by maxgarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	init_variables(t_philo_data **data, void *arg,
	struct timeval *init_time)
{
	*data = (t_philo_data *)arg;
	(*data)->cnt_meals = (*data)->args->ntimes_eat + 1;
	gettimeofday(init_time, NULL);
	gettimeofday(&(*data)->last_meal_time, NULL);
}

static void	go_to_eat(t_philo_data *data, struct timeval *now,
	struct timeval *init_time)
{
	int	elapsed;

	gettimeofday(now, NULL);
	pthread_mutex_lock(data->echo_mutex);
	printf(GREEN "%ld %d is eating\n",
		(long)(((now->tv_sec - init_time->tv_sec) * 1000)
			+ (long)((now->tv_usec - init_time->tv_usec) / 1e3)), data->id);
	pthread_mutex_unlock(data->echo_mutex);
	elapsed = 0;
	while (elapsed < data->args->time_to_eat)
	{
		if (is_simulation_active(data->args) == NO)
			(free(data), exit(FN_FAILED));
		gettimeofday(now, NULL);
		if (am_i_dead(now, &data->last_meal_time, &data->args->time_to_die)
			&& data->args->simulation_active == YES)
			(kill_philosopher(data, now, init_time), exit(FN_FAILED));
		usleep(INTERVAL_NAP);
		elapsed += INTERVAL_NAP;
	}
	gettimeofday(&data->last_meal_time, NULL);
	pthread_mutex_lock(data->forks_mutex);
	data->forks_taken[data->left_fork] = 0;
	data->forks_taken[data->right_fork] = 0;
	pthread_mutex_unlock(data->forks_mutex);
}

static void	go_to_sleep(t_philo_data *data, struct timeval *now,
	struct timeval *init_time)
{
	int	elapsed;

	gettimeofday(now, NULL);
	pthread_mutex_lock(data->echo_mutex);
	printf(MAGENTA "%ld %d is sleeping\n",
		(long)(((now->tv_sec - init_time->tv_sec) * 1000)
			+ (long)((now->tv_usec - init_time->tv_usec) / 1e3)),
		data->id);
	pthread_mutex_unlock(data->echo_mutex);
	elapsed = 0;
	while (elapsed < data->args->time_to_sleep)
	{
		if (is_simulation_active(data->args) == NO)
			(free(data), exit(FN_FAILED));
		gettimeofday(now, NULL);
		if (am_i_dead(now, &data->last_meal_time, &data->args->time_to_die)
			&& data->args->simulation_active == YES)
		{
			kill_philosopher(data, now, init_time);
			exit(FN_FAILED);
		}
		usleep(INTERVAL_NAP);
		elapsed += INTERVAL_NAP;
	}
}

void	ask_for_forks(t_philo_data *data, struct timeval *now,
	struct timeval *init_time)
{
	while (check_forks_freed(data, init_time, now))
	{
		if (is_simulation_active(data->args) == NO)
		{
			free(data);
			exit(FN_FAILED);
		}
		gettimeofday(now, NULL);
		if (am_i_dead(now, &data->last_meal_time, &data->args->time_to_die)
			&& data->args->simulation_active == YES)
		{
			kill_philosopher(data, now, init_time);
			exit(FN_FAILED);
		}
		usleep(LITTLE_NAP);
	}
}

void	*run_philo(void *arg)
{
	t_philo_data	*data;
	struct timeval	init_time;
	struct timeval	now;

	data = NULL;
	init_variables(&data, arg, &init_time);
	while (is_simulation_active(data->args) && ((data->cnt_meals == -1)
			|| --(data->cnt_meals)))
	{
		gettimeofday(&now, NULL);
		pthread_mutex_lock(data->echo_mutex);
		printf(BLUE "%ld %d is thinking\n",
			(long)(((now.tv_sec * 1000) + (now.tv_usec / 1e3))
				- ((init_time.tv_sec * 1000) + (init_time.tv_usec / 1e3))),
			data->id);
		pthread_mutex_unlock(data->echo_mutex);
		ask_for_forks(data, &now, &init_time);
		go_to_eat(data, &now, &init_time);
		go_to_sleep(data, &now, &init_time);
	}
	free(data);
	return (NULL);
}
