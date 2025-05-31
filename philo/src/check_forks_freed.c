/* ************************************************************************** */
/*																			*/
/*														:::	  ::::::::   */
/*   check_forks_freed.c                                :+:      :+:    :+:   */
/*													+:+ +:+		 +:+	 */
/*   By: maxgarci <maxgarci@student.42.fr>		  +#+  +:+	   +#+		*/
/*												+#+#+#+#+#+   +#+		   */
/*   Created: 2025/05/08 15:33:18 by maxgarci		  #+#	#+#			 */
/*   Updated: 2025/05/31 10:32:22 by maxgarci         ###   ########.fr       */
/*																			*/
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

static void	add_my_turn(t_philo_data *data)
{
	t_queue_node	*tmp;

	pthread_mutex_lock(&data->args->fqueue->queue_mutex);
	if (data->in_queue == YES || data->my_ticket != NULL)
	{
		pthread_mutex_unlock(&data->args->fqueue->queue_mutex);
		return;
	}
	data->my_ticket = (t_queue_node *)malloc(sizeof(t_queue_node));
	if (data->my_ticket == NULL)
	{
		ft_putstr_fd("Allocating my ticket node error", 2);
		pthread_mutex_unlock(&data->args->fqueue->queue_mutex);
		return ;
	}
	data->my_ticket->id = data->id;
	data->my_ticket->next = NULL;
	data->my_ticket->prev = NULL;
	tmp = data->args->fqueue->front;
	if (tmp == NULL)
		data->args->fqueue->front = data->my_ticket;
	else
	{
		while (tmp->next != NULL)
		{
			tmp = tmp->next;
		}
		tmp->next = data->my_ticket;
		data->my_ticket->prev = tmp;
	}
	data->in_queue = YES;
	pthread_mutex_unlock(&data->args->fqueue->queue_mutex);
}

static void	delete_node(t_philo_data *data)
{
	t_queue_node	*tmp;

	pthread_mutex_lock(&data->args->fqueue->queue_mutex);
	if (data->my_ticket == NULL)
	{
		pthread_mutex_unlock(&data->args->fqueue->queue_mutex);
		return ;
	}
	if (data->my_ticket->prev == NULL)
	{
		if (data->my_ticket->next != NULL)
			data->my_ticket->next->prev = NULL;
		data->args->fqueue->front = data->my_ticket->next;
	}
	else
	{
		tmp = data->my_ticket->prev;
		tmp->next = data->my_ticket->next;
	}
	free(data->my_ticket);
	data->my_ticket = NULL;
	data->in_queue = NO;
	pthread_mutex_unlock(&data->args->fqueue->queue_mutex);
}

int	my_turn(t_philo_data *data)
{
	t_queue_node	*tmp;

	if (data->in_queue == NO)
		add_my_turn(data);
	if (data->first_round == YES)
	{
		data->first_round = NO;
		return (YES);
	}
	pthread_mutex_lock(&data->args->fqueue->queue_mutex);
	tmp = data->args->fqueue->front;
	while (tmp != NULL)
	{
		if (((data->id == 0 && tmp->id == (data->id + data->args->nphilosophers - 1))
			|| (data->id != 0 && tmp->id == (data->id - 1)))
			|| tmp->id == (data->id + 1) % data->args->nphilosophers)
		{
			pthread_mutex_unlock(&data->args->fqueue->queue_mutex);
			return (NO);
		}
		if (tmp->id == data->id)
		{
			pthread_mutex_unlock(&data->args->fqueue->queue_mutex);
			return (YES);
		}
		tmp = tmp->next;
	}
	pthread_mutex_unlock(&data->args->fqueue->queue_mutex);
	return (YES);
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
		take_forks(data, now);
		delete_node(data);
		return (FN_SUCESSED);
	}
	pthread_mutex_unlock(&data->forks_mutexes[data->left_fork]);
	pthread_mutex_unlock(&data->forks_mutexes[data->right_fork]);
	return (FN_FAILED);
}
