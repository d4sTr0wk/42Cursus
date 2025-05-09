/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ask_for_forks.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maxgarci <maxgarci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/08 15:49:22 by maxgarci          #+#    #+#             */
/*   Updated: 2025/05/08 15:53:40 by maxgarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ask_for_forks(t_philo_data *data, struct timeval *now)
{
	while (check_forks_freed(data, now))
	{
		if (is_simulation_active(data->args) == NO)
			return (free(data), FN_FAILED);
		if (am_i_dead(now, &data->last_meal_time, &data->args->time_to_die)
			&& data->args->simulation_active == YES)
			return (kill_philosopher(data, now), FN_FAILED);
		usleep(LITTLE_NAP);
	}
	return (FN_SUCESSED);
}
