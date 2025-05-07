/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maxgarci <maxgarci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 11:26:17 by maxgarci          #+#    #+#             */
/*   Updated: 2025/05/05 15:28:00 by maxgarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"
#include <unistd.h>

static void	help_panel(void)
{
	ft_putstr_fd(YELLOW \
		"\nUse: ./philo <number_of_philosophers> <time_to_die> <time_to_eat> \
		<time_to_sleep> [optional: \
		<number_of_times_each_philosopher_must_eat>]" RESET, STDERR_FILENO);
}

int	print_error(enum e_error_codes error)
{
	char	*error_messages[6];

	error_messages[0] = "not enough args";
	error_messages[1] = "number_of_philosophers is not valid";
	error_messages[2] = "time_to_die is not valid";
	error_messages[3] = "time_to_eat is not valid";
	error_messages[4] = "time_to_sleep is not valid";
	error_messages[5] = "ntimes_eat is not valid";
	ft_putstr_fd(RED"./philo: ", 2);
	ft_putstr_fd(error_messages[error - 1], STDERR_FILENO);
	help_panel();
	return (FN_FAILED);
}
