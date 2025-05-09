/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   end_philosophers.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maxgarci <maxgarci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/08 13:39:48 by maxgarci          #+#    #+#             */
/*   Updated: 2025/05/08 15:52:48 by maxgarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	destroy_forks_mutexes(pthread_mutex_t *forks_mutexes, int nforks)
{
	int	i;

	i = -1;
	while (++i < nforks)
		pthread_mutex_destroy(&forks_mutexes[i]);
}

static void	print_simulation_end(pthread_mutex_t *echo_mutex)
{
	pthread_mutex_lock(echo_mutex);
	printf(YELLOW "Simulation has finished!\n" RESET);
	pthread_mutex_unlock(echo_mutex);
}

int	end_philosophers(pthread_mutex_t **mutexes, int nforks,
	pthread_t **philosophers, int *forks_taken)
{
	print_simulation_end(mutexes[0]);
	destroy_forks_mutexes(mutexes[1], nforks);
	return (free(*philosophers), free(forks_taken),
		pthread_mutex_destroy(mutexes[0]),
		pthread_mutex_destroy(mutexes[2]), FN_SUCESSED);
}
