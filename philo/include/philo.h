/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maxgarci <maxgarci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 10:40:02 by maxgarci          #+#    #+#             */
/*   Updated: 2025/05/06 17:46:24 by maxgarci         ###   ########.fr       */
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
//phtreadtypes
# include <bits/pthreadtypes.h>

/*********************
*		DEFINES
* *******************/

# define FN_SUCESSED 0
# define FN_FAILED 1
# define NO 0
# define YES 1

# define MILLI_TO_MICRO 1000
# define INTERVAL_NAP 10000
# define LITTLE_NAP 10

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
	long			time_to_die;
	long			time_to_eat;
	long			time_to_sleep;
	int				ntimes_eat;
	volatile int	simulation_active;
	pthread_mutex_t	simulation_mutex;
}	t_args;

typedef struct s_philo_data
{
	int				id;
	int				left_fork;
	int				right_fork;
	int				cnt_meals;
	int				*forks_taken;
	t_args			*args;
	pthread_mutex_t	*echo_mutex;
	pthread_mutex_t	*forks_mutexes;
	struct timeval	last_meal_time;
}	t_philo_data;

/****************
 *	run_philo.c
 ***************/
void	*run_philo(void *arg);

/******************
 *	philo_utils.c
 *****************/

int		am_i_dead(struct timeval *now, struct timeval *last_time,
			long *time_to_die);

int		check_forks_freed(t_philo_data *data, struct timeval *init_time,
			struct timeval *now);

int		is_simulation_active(t_args *args);

int		is_simulation_active(t_args *args);

void	kill_philosopher(t_philo_data *data, struct timeval *now,
			struct timeval *init_time);

/*************************
 *	init_philosophers.c
 ************************/

int		init_philosophers(t_args *args, pthread_t **philosophers,
			pthread_mutex_t *echo_mutex, pthread_mutex_t *forks_mutex);

/*******************
 *	print_error.c
 ******************/
int		print_error(enum e_error_codes error);

/*******************
 *	libft_utils.c
 ******************/
int		ft_atoi(const char *str);

void	ft_putstr_fd(char *s, int fd);

#endif
