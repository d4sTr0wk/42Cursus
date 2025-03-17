/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maxgarci <maxgarci@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 10:40:02 by maxgarci          #+#    #+#             */
/*   Updated: 2025/03/11 10:18:41 by maxgarci         ###   ########.fr       */
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

# define TIME_THINKING_US 5000

# define RESET   "\e[0;0m"
# define RED     "\e[0;31m"
# define GREEN   "\e[0;32m"
# define YELLOW  "\e[0;93m"
# define BLUE    "\e[0;34m"
# define MAGENTA "\e[0;35m"
# define CYAN    "\e[0;36m"
# define GREY	"\e[0;127m"

/*******************
*		ENUM
* *****************/

enum	e_error_codes
{
	ARGS_NUM_ERROR = 1,
	INVALID_NPHIL,
	INVALID_TIME_2_DIE,
	INVALID_TIME_2_EAT,
	INVALID_TIME_2_SLEEP,
	INVALID_NTIMES_EAT
};

/*********************
*		STRUCTS
* ********************/

typedef struct s_args
{
	int				nphilosophers;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				ntimes_eat;
	volatile int	simulation_active;
}	t_args;

typedef struct s_philo_data
{
	int				id;
	int				cnt_meals;
	t_args			*args;
	pthread_mutex_t	*forks;
	pthread_mutex_t	*mutex_simulation;
	struct timeval	last_meal_time;
} t_philo_data;

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
