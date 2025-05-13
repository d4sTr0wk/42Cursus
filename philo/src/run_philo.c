/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run_philo.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maxgarci <maxgarci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/06 10:18:02 by maxgarci          #+#    #+#             */
/*   Updated: 2025/05/12 15:43:00 by maxgarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*run_philo(void *arg)
{
	t_philo_data	*data;
	struct timeval	now;

	data = NULL;
	data = (t_philo_data *)arg;
	data->cnt_meals = data->args->ntimes_eat + 1;
	gettimeofday(&data->last_meal_time, NULL);
	while (is_simulation_active(data->args) && ((data->cnt_meals == -1)
			|| --(data->cnt_meals)))
	{
		if (ask_for_forks(data, &now))
			return (NULL);
		if (go_to_eat(data, &now))
			return (NULL);
		if (go_to_sleep(data, &now))
			return (NULL);
		go_to_think(data, &now);
	}
	free(data);
	return (NULL);
}
