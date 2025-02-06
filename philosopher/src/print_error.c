/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maxgarci <maxgarci@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 11:26:17 by maxgarci          #+#    #+#             */
/*   Updated: 2025/02/05 12:03:13 by maxgarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

static const char *error_messages[] = {
	"Not enough args"
};

int print_error(enum e_error_codes error)
{
	write(STDERR_FILENO, error_messages[error - 1], ft_strlen(error_messages[error - 1]));
	return (1);
}
