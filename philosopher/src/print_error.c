/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maxgarci <maxgarci@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 11:26:17 by maxgarci          #+#    #+#             */
/*   Updated: 2025/03/09 12:37:40 by maxgarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"
#include <unistd.h>

static char *error_messages[] = {
	"not enough args",
	"number_of_philosophers is not valid",
	"time_to_die is not valid",
	"time_to_eat is not valid",
	"time_to_sleep is not valid",
	"ntimes_eat is not valid"
};

static void	help_panel()
{
	ft_putstr_fd(YELLOW "\nUse: ./philo <number_of_philosophers> <time_to_die> <time_to_eat> <time_to_sleep> [optional: <number_of_times_each_philosopher_must_eat>]" RESET, STDERR_FILENO);
}

int print_error(enum e_error_codes error)
{
	ft_putstr_fd(RED"./philo: ", 2);
	ft_putstr_fd(error_messages[error - 1], STDERR_FILENO);
	help_panel();
	return (FN_FAILED);
}
