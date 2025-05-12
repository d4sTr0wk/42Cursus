/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_forks_freed.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maxgarci <maxgarci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/08 15:33:18 by maxgarci          #+#    #+#             */
/*   Updated: 2025/05/12 00:32:48 by maxgarci         ###   ########.fr       */
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
	printf("init_time: %ld.%06ld\n", data->init_time->tv_sec, data->init_time->tv_usec);
	printf("now: %ld.%06ld\n", now->tv_sec, now->tv_usec);
	pthread_mutex_unlock(data->echo_mutex);
}

static void	add_my_turn(t_philo_data *data)
{
	t_queue_node	*my_ticket;
	t_queue_node	*tmp;

	if (data->in_queue == YES)
		return;
	my_ticket = (t_queue_node *)malloc(sizeof(t_queue_node));
	if (my_ticket == NULL)
	{
		ft_putstr_fd("Allocating my ticket node error", 2);
		return ;
	}
	my_ticket->id = data->id;
	my_ticket->next = NULL;
	pthread_mutex_lock(&data->args->fqueue->queue_mutex);
	tmp = data->args->fqueue->front;
	if (tmp == NULL)
		data->args->fqueue->front = my_ticket;
	else
	{
		while (tmp->next != NULL)
		{
			tmp = tmp->next;
		}
		tmp->next = my_ticket;
	}
	pthread_mutex_unlock(&data->args->fqueue->queue_mutex);
	data->in_queue = YES;
}

int	my_turn(t_philo_data *data)
{
	t_queue_node	*tmp;
	t_queue_node	*prev = NULL;

	pthread_mutex_lock(&data->args->fqueue->queue_mutex);
	tmp = data->args->fqueue->front;
	while (tmp != NULL)
	{
		if (tmp->id == data->id - 1 || tmp->id == data->id + 1)
		{
			if (data->in_queue == NO)
				add_my_turn(data);
			pthread_mutex_unlock(&data->args->fqueue->queue_mutex);
			return (NO);
		}
		if (tmp->id == data->id)
		{
			if (prev == NULL)
				data->args->fqueue->front = tmp->next;
			else
				prev->next = tmp->next;
			free(tmp);
			pthread_mutex_unlock(&data->args->fqueue->queue_mutex);
			return (YES);
		}
		prev = tmp;
		tmp = tmp->next;
	}
	return (pthread_mutex_unlock(&data->args->fqueue->queue_mutex), YES);
}

int	check_forks_freed(t_philo_data *data, struct timeval *now)
{
	if (my_turn(data) == NO)
		return (FN_FAILED);
	pthread_mutex_lock(&data->forks_mutexes[data->left_fork]);
	pthread_mutex_lock(&data->forks_mutexes[data->right_fork]);
	if (data->forks_taken[data->left_fork] == NO
		&& data->forks_taken[data->right_fork] == NO)
	{
		data->in_queue = NO;
		take_forks(data, now);

		return (FN_SUCESSED);
	}
	pthread_mutex_unlock(&data->forks_mutexes[data->left_fork]);
	pthread_mutex_unlock(&data->forks_mutexes[data->right_fork]);
	if (data->in_queue == NO)
		add_my_turn(data);
	return (FN_FAILED);
}
