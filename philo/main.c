/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maxgarci <maxgarci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 09:14:39 by maxgarci          #+#    #+#             */
/*   Updated: 2025/05/05 15:11:42 by maxgarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/philo.h"
#include <bits/pthreadtypes.h>
#include <pthread.h>
#include <stdio.h>
#include <sys/time.h>

static int	args_are_valid(int argc, char **args __attribute__((unused)), t_args *arguments)
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

int		am_i_dead(struct timeval *now, struct timeval *last_time, long *time_to_die)
{
	long elapsed_time = (long)(((now->tv_sec * 1000000) + now->tv_usec) - ((last_time->tv_sec * 1000000) + last_time->tv_usec));
	if (elapsed_time > *time_to_die)
		return (YES);
	return (NO);
}

int		check_forks_freed(t_philo_data *data, struct timeval *init_time, struct timeval *now)
{
	pthread_mutex_lock(data->forks_mutex);
	gettimeofday(now, NULL);
	if (data->forks_taken[data->left_fork] == NO
		&& data->forks_taken[data->right_fork] == NO)
	{
		data->forks_taken[data->left_fork] = YES;
		data->forks_taken[data->right_fork] = YES;
		pthread_mutex_lock(data->echo_mutex);
		printf(RESET "%ld %d has taken fork %d\n", (long)(((now->tv_sec * 1000) + (now->tv_usec / 1e3)) - ((init_time->tv_sec * 1000) + (init_time->tv_usec / 1e3))), data->id, data->left_fork);
		printf(RESET "%ld %d has taken fork %d\n", (long)(((now->tv_sec * 1000) + (now->tv_usec / 1e3)) - ((init_time->tv_sec * 1000) + (init_time->tv_usec / 1e3))), data->id, data->right_fork);
		pthread_mutex_unlock(data->echo_mutex);
		pthread_mutex_unlock(data->forks_mutex);
		return (FN_SUCESSED);
	}
	pthread_mutex_unlock(data->forks_mutex);
	return (FN_FAILED);
}

int		is_simulation_active(t_args *args)
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

void	kill_philosopher(t_philo_data *data, struct timeval *now, struct timeval *init_time)
{
	pthread_mutex_lock(data->echo_mutex);
	printf(RED "%ld %d died\n", (long)(((now->tv_sec - init_time->tv_sec) * 1000) + (long)((now->tv_usec - init_time->tv_usec) / 1e3)), data->id);
	set_simulation_active(data->args, 0);
	pthread_mutex_unlock(data->echo_mutex);
	free(data);
}

void	*run_philo(void *arg)
{
	t_philo_data	*data;
	struct timeval	init_time;
	struct timeval	now;
	long			elapsed;

	data = (t_philo_data *)arg;
	data->cnt_meals = data->args->ntimes_eat + 1;
	gettimeofday(&init_time, NULL);
	gettimeofday(&data->last_meal_time, NULL);
	while (is_simulation_active(data->args) && ((data->cnt_meals == -1) || --(data->cnt_meals)))
	{
		gettimeofday(&now, NULL);
		pthread_mutex_lock(data->echo_mutex);
		printf(BLUE "%ld %d is thinking\n", (long)(((now.tv_sec * 1000) + (now.tv_usec / 1e3)) - ((init_time.tv_sec * 1000) + (init_time.tv_usec / 1e3))), data->id);
		pthread_mutex_unlock(data->echo_mutex);
		
		while (check_forks_freed(data, &init_time, &now))
		{
			usleep(LITTLE_NAP);
			gettimeofday(&now, NULL);
			if (is_simulation_active(data->args) == NO)
				return (free(data), NULL);
			if (am_i_dead(&now, &data->last_meal_time, &data->args->time_to_die))
			{
				kill_philosopher(data, &now, &init_time);	
				return (NULL);
			}
		}
		gettimeofday(&now, NULL);
		pthread_mutex_lock(data->echo_mutex);
		printf(GREEN "%ld %d is eating\n", (long)(((now.tv_sec - init_time.tv_sec) * 1000) + (long)((now.tv_usec - init_time.tv_usec) / 1e3)), data->id);
		pthread_mutex_unlock(data->echo_mutex);

		elapsed = 0;
		while (elapsed < data->args->time_to_eat)
		{
			if (is_simulation_active(data->args) == NO)
				return (free(data), NULL);
			gettimeofday(&now, NULL);
			if (am_i_dead(&now, &data->last_meal_time, &data->args->time_to_die))
			{
				kill_philosopher(data, &now, &init_time);
				return (NULL);
			}
			usleep(INTERVAL_NAP);
			elapsed += INTERVAL_NAP;
		}

		gettimeofday(&data->last_meal_time, NULL);

		pthread_mutex_lock(data->forks_mutex);
		data->forks_taken[data->left_fork] = 0;
		data->forks_taken[data->right_fork] = 0;
		pthread_mutex_unlock(data->forks_mutex);

		gettimeofday(&now, NULL);
		pthread_mutex_lock(data->echo_mutex);
		printf(MAGENTA "%ld %d is sleeping\n", (long)(((now.tv_sec - init_time.tv_sec) * 1000) + (long)((now.tv_usec - init_time.tv_usec) / 1e3)), data->id);
		pthread_mutex_unlock(data->echo_mutex);

		elapsed = 0;
		while (elapsed < data->args->time_to_sleep)
		{
			if (is_simulation_active(data->args) == NO)
				return (free(data), NULL);
			gettimeofday(&now, NULL);
			if (am_i_dead(&now, &data->last_meal_time, &data->args->time_to_die))
			{
				kill_philosopher(data, &now, &init_time);
				return (NULL);
			}
			usleep(INTERVAL_NAP);
			elapsed += INTERVAL_NAP;
		}
	}
	free(data);
	return (NULL);
}

void	init_philosophers(t_args *args, pthread_t **philosophers, pthread_mutex_t *echo_mutex, pthread_mutex_t *forks_mutex)
{
	int				i;
	int				*forks_taken;
	t_philo_data	*data;

	*philosophers = (pthread_t *)malloc(sizeof(pthread_t) * args->nphilosophers);
	forks_taken = (int *)malloc(sizeof(int) * args->nphilosophers);
	if (!*philosophers || !forks_taken)
	{
		if (*philosophers)
			free(*philosophers);
		if (forks_taken)
			free(forks_taken);
		ft_putstr_fd("Allocating memory error", 2);
		return ;
	}
	pthread_mutex_init(echo_mutex, NULL);
	pthread_mutex_init(forks_mutex, NULL);
	pthread_mutex_init(&args->simulation_mutex, NULL);
	i = -1;
	while (++i < args->nphilosophers)
		forks_taken[i] = NO;
	i = -1;
	while (++i < args->nphilosophers)
	{
		data = (t_philo_data *)malloc(sizeof(t_philo_data));
		if (!data)
		{
			ft_putstr_fd("Allocating memory error", 2);
			break;
		}
		data->forks_taken = forks_taken;
		data->args = args;
		data->id = i;
		data->left_fork = data->id;
		data->right_fork = (data->id + 1) % data->args->nphilosophers;
		data->echo_mutex = echo_mutex;
		data->forks_mutex = forks_mutex;
		if (pthread_create(&(*philosophers)[i], NULL, run_philo, data))
		{
			ft_putstr_fd("Error creating thread", 2);
			free(data);
			break;
		}
	}

	if (i < args->nphilosophers)
	{
		while (--i >= 0)
			pthread_join((*philosophers)[i], NULL);
		free(*philosophers);
		free(forks_taken);
		pthread_mutex_destroy(echo_mutex);
		pthread_mutex_destroy(forks_mutex);
		pthread_mutex_destroy(&args->simulation_mutex);
		return ;
	}

	i = -1;
	while (++i < args->nphilosophers)
	{
		pthread_join((*philosophers)[i], NULL);
	}

	pthread_mutex_lock(echo_mutex);
	printf(YELLOW "Simulation has finished!\n" RESET);
	pthread_mutex_unlock(echo_mutex);

	free(*philosophers);
	free(forks_taken);
	pthread_mutex_destroy(echo_mutex);
	pthread_mutex_destroy(forks_mutex);
	pthread_mutex_destroy(&args->simulation_mutex);
}

int main(int argc, char **argv) 
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
		init_philosophers(&arguments, &philosophers, &echo_mutex, &forks_mutex);
		if (!philosophers)
			return (1);
	}
	else
		return (valid_args);
	return (0);
}
