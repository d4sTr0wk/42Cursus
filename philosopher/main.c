/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maxgarci <maxgarci@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 09:14:39 by maxgarci          #+#    #+#             */
/*   Updated: 2025/03/09 22:06:11 by maxgarci         ###   ########.fr       */
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
	if (arguments->nphilosophers <= 0)
		return (print_error(INVALID_NPHIL));
	arguments->time_to_die = ft_atoi(args[2]);
	if (arguments->time_to_die <= 0)
		return (print_error(INVALID_TIME_2_DIE));
	arguments->time_to_eat = ft_atoi(args[3]);
	if (arguments->time_to_eat <= 0)
		return (print_error(INVALID_TIME_2_EAT));
	arguments->time_to_sleep = ft_atoi(args[4]);
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

void	*run_philo(void *arg)
{
	int				left_fork;
	int				right_fork;
	long			time_passed;
	t_philo_data	*data;
	struct timeval	init_time;
	struct timeval	now;

	data = (t_philo_data *)arg;
	data->cnt_meals = data->args->ntimes_eat + 1;
	left_fork = data->id;
	right_fork = (data->id + 1) % data->args->nphilosophers;
	gettimeofday(&init_time, NULL);
	gettimeofday(&now, NULL);
	gettimeofday(&data->last_meal_time, NULL);
	while (data->args->simulation_active && ((data->cnt_meals == -1) || --data->cnt_meals))
	{
		printf(CYAN "🤔%ldms %d has taken a fork\n", (long)(((now.tv_sec - init_time.tv_sec) * 1000) + (long)((now.tv_usec - init_time.tv_usec) / 1e3)), data->id);
		usleep(TIME_THINKING_MS);
		pthread_mutex_lock(&data->forks[left_fork]);
		printf(RESET "%ldms %d has taken a fork\n", (long)(((now.tv_sec - init_time.tv_sec) * 1000) + (long)((now.tv_usec - init_time.tv_usec) / 1e3)), data->id);
		pthread_mutex_lock(&data->forks[right_fork]);
		printf(RESET "%ldms %d has taken a fork\n", (long)(((now.tv_sec - init_time.tv_sec) * 1000) + (long)((now.tv_usec - init_time.tv_usec) / 1e3)), data->id);
		if (data->cnt_meals < data->args->ntimes_eat || data->cnt_meals == -1)
		{
			gettimeofday(&now, NULL);
			time_passed = (now.tv_sec - data->last_meal_time.tv_sec) * 1000000 + (now.tv_usec - data->last_meal_time.tv_usec);
			printf(RESET "Time passed since last meal: now %ld s %ld ms last_meal %ld s %ld ms, difference %ld\n", (long)now.tv_sec, (long)now.tv_usec, (long)data->last_meal_time.tv_sec, (long)data->last_meal_time.tv_usec, time_passed);
			if (time_passed > data->args->time_to_die)
			{
				printf(RED "☠️ %ldms %d died\n", (long)(((now.tv_sec - init_time.tv_sec) * 1000) + (long)((now.tv_usec - init_time.tv_usec) / 1e3)), data->id);
				pthread_mutex_lock(data->mutex_simulation);
				data->args->simulation_active = 0;
				pthread_mutex_unlock(data->mutex_simulation);
				break;
			}
		}
		gettimeofday(&data->last_meal_time, NULL);
		printf(RED "😋%ldms %d is eating\n", (long)(((now.tv_sec - init_time.tv_sec) * 1000) + (long)((now.tv_usec - init_time.tv_usec) / 1e3)), data->id);
		usleep(data->args->time_to_eat);
		pthread_mutex_unlock(&data->forks[left_fork]);
		pthread_mutex_unlock(&data->forks[right_fork]);
		printf(MAGENTA "😴%ldms %d goes to sleep\n", (long)(((now.tv_sec - init_time.tv_sec) * 1000) + (long)((now.tv_usec - init_time.tv_usec) / 1e3)), data->id);
		usleep(data->args->time_to_sleep);
	}
	free(data);
	return (NULL);
}

void	init_philosophers_forks(t_args *args, pthread_t *philosophers, pthread_mutex_t *mutex_simulation)
{
	int				i;
	pthread_mutex_t	*forks;
	t_philo_data	*data;

	philosophers = (pthread_t *)malloc(sizeof(pthread_t) * args->nphilosophers);
	forks = (pthread_mutex_t *)malloc(sizeof(pthread_mutex_t) * args->nphilosophers);
	if (!philosophers || !forks)
	{
		perror("Allocating memory error");
		return ;
	}
	i = 0;
	while (i < args->nphilosophers)
		pthread_mutex_init(forks + (i++), NULL);
	pthread_mutex_init(mutex_simulation, NULL);
	i = 0;
	while (i < args->nphilosophers)
	{
		data = (t_philo_data *)malloc(sizeof(t_philo_data));
		if (!data)
		{
			perror("Allocating memory error");
			return ;
		}
		data->forks = forks;
		data->args = args;
		data->id = i;
		data->mutex_simulation = mutex_simulation;
		pthread_create(philosophers + (i), NULL, run_philo, data);
		pthread_detach(philosophers[i++]);
	}
	while (args->simulation_active)
		usleep(args->time_to_die);		
	i = 0;
	while (i < args->nphilosophers)
		pthread_mutex_destroy(forks + (i++));
	printf(YELLOW "Simulation has finished!\n" RESET);
}

int main(int argc, char **argv) 
{
	int					valid_args;
	t_args				arguments;
	pthread_t			*philosophers;
	pthread_mutex_t		mutex_simulation;

	valid_args = args_are_valid(argc, argv, &arguments);
	philosophers = NULL;
	if (!valid_args)
		init_philosophers_forks(&arguments, philosophers, &mutex_simulation);
	else
		return (valid_args);
}
