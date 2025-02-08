/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maxgarci <maxgarci@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 10:40:02 by maxgarci          #+#    #+#             */
/*   Updated: 2025/02/08 22:46:17 by maxgarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

/***********************
*		INCLUDES
* *********************/

// printf
# include <stdio.h>
// malloc, memset, free, write
# include <stdlib.h>
// pthread functions
# include <pthread.h>
// usleep
# include <unistd.h>
// gettimeofday
# include <sys/time.h>

/*********************
*		DEFINES
* *******************/

# define FN_SUCESSED 0
# define FN_FAILED 1

# define RESET   "\033[0m"  // Restablecer el color
# define RED     "\033[91m" // Rojo
# define GREEN   "\033[32m" // Verde
# define YELLOW  "\033[93m" // Amarillo
# define BLUE    "\033[34m" // Azul
# define MAGENTA "\033[35m" // Magenta
# define CYAN    "\033[36m" // Cian

/*******************
*		ENUM
* *****************/

enum	e_error_codes
{
	ARGS_NUM_ERROR = 1,
	INVALID_NPHIL,
	INVALID_TIME_2_DIE,
	INVALID_TIME_2_EAT,
	INVALID_TIME_2_SLEEP
};

/*********************
*		STRUCTS
* ********************/

typedef struct s_args
{
	int	nphilosophers;
	int	time_to_die;
	int	time_to_eat;
	int	time_to_sleep;
	int	ntimes_eat;
}	t_args;

/******************
*		MAIN
* *****************/

// print_error.c
int		print_error(enum e_error_codes error);

// libft_utils.c
int		ft_atoi(const char *str);

size_t	ft_strlen(const char *str);

void	ft_putstr_fd(char *s, int fd);

#endif
