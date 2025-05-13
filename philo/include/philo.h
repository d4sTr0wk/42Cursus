/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maxgarci <maxgarci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 10:40:02 by maxgarci          #+#    #+#             */
/*   Updated: 2025/05/13 19:28:31 by maxgarci         ###   ########.fr       */
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

typedef struct s_queue_node
{
	unsigned char		id;
	struct s_queue_node	*next;
	struct s_queue_node	*prev;
}	t_queue_node;

typedef struct s_fork_queue
{
	t_queue_node	*front;
	pthread_mutex_t	queue_mutex;
}	t_fork_queue;

typedef struct s_args
{
	unsigned char			nphilosophers;
	long					time_to_die;
	long					time_to_eat;
	long					time_to_sleep;
	int						ntimes_eat;
	volatile unsigned char	simulation_active;
	pthread_mutex_t			simulation_mutex;
	t_fork_queue			*fqueue;
	struct timeval			*init_time;
}	t_args;

typedef struct s_philo_data
{
	unsigned char	id;
	unsigned char	in_queue;
	unsigned char	left_fork;
	unsigned char	right_fork;
	int				cnt_meals;
	unsigned char	*forks_taken;
	t_args			*args;
	pthread_mutex_t	*echo_mutex;
	pthread_mutex_t	*forks_mutexes;
	struct timeval	*init_time;
	struct timeval	last_meal_time;
	t_queue_node	*my_ticket;
	char			first_round;
}	t_philo_data;

/****************
 *	run_philo.c
 ***************/

/**
 * @brief Philosopher thread's code execution
 * @param arg Philosopher's data needed (t_philo_data)
 */
void	*run_philo(void *arg);

/******************
 *	philo_utils.c
 *****************/

/**
 * @brief Checks if thread should be dead because of time passed
 * @param now timeval struct to get actual time
 * @param *ast_time Last time philosopher thread ate
 * @return 1 if the philosopher has died. Otherwise, 0.
 */
int		am_i_dead(struct timeval *now, struct timeval *last_time,
			long *time_to_die, t_args *args);

/**
 * @brief Checks if simulation is still active
 * @param args Where simulation_active bool and mutex are stored
 * @return 1 if simulation is still active. Otherwise, 0.
 */
int		is_simulation_active(t_args *args);

/**
 * @brief Kills the philosopher that resulted dead and frees the simulation
 * @param data Philosopher's data structure
 * @param now Time structure used to get actual time
 */
void	kill_philosopher(t_philo_data *data, struct timeval *now);

/*************************
 *	init_philosophers.c
 ************************/

/**
 * @brief Initialize philosopher's data structures and creates threads
 * @param args Arguments of the simulation
 * @param philosophers array of philosopher threads
 * @param echo_mutex mutex for printing on stdout what happens with philosophers
 * @param forks_mutex mutex for taking and asking for forks
 * @return 1 if some error happened, 0 if everything went correctly
 */
int		init_philosophers(t_args *args, pthread_t **philosophers,
			pthread_mutex_t *echo_mutex, pthread_mutex_t *forks_mutex);

/************************
 *	end_philosophers.c
 ***********************/


void	free_queue(t_fork_queue *fqueue);

/**
 * @brief Frees mutexes and structures allocated previously
 * @param mutexes Mutexes that have to be destroyed
 * @param nforks number of forks
 * @param philosophers array of philosopher threads
 * @param forks_taken array that registers if the fork was taken or not
 * @return FN_SUCCESSED
 */
int		end_philosophers(pthread_mutex_t **mutexes, int nforks,
			pthread_t **philosophers, unsigned char *forks_taken);

/**
 * @brief Destroys forks's mutexes
 * @param forks_mutexes array of forks mutexes
 * @param nforks number of forks
 */
void	destroy_forks_mutexes(pthread_mutex_t *forks_mutexes, int nforks);

/*************************
 *	check_forks_freed.c
 ************************/

/**
 * @brief Checks if the forks at the left and right of the philosopher are free
 * to use
 * @param data Philosopher's data structure
 * @param now Time structure used to get actual time
 */
int		check_forks_freed(t_philo_data *data, struct timeval *now);

/*************************
 *	go_to_think.c
 ************************/
/**
 * @brief Shows think message
 * @param data Philosopher's data structure
 * @param now pointer to time structure for actual time
*/
void	go_to_think(t_philo_data *data, struct timeval *now);

/*************************
 *	go_to_sleep.c
 ************************/

/**
 * @brief Shows sleep message and waits sleep time
 * @param data Philosopher's data structure
 * @param now pointer to time structure for actual time
*/
int		go_to_sleep(t_philo_data *data, struct timeval *now);

/*************************
 *	go_to_eat.c
 ************************/

/**
 * @brief Shows eat message and waits eat time
 * @param data Philosopher's data structure
 * @param now pointer to time structure for actual time
*/
int		go_to_eat(t_philo_data *data, struct timeval *now);

/*************************
 *	ask_for_forks.c
 ************************/

/**
 * @brief Checks if forks needed are available and if not takes a little nap
 * @param data Philosopher's data structure
 * @param now pointer to time structure for actual time
 * @return 0 if everything went correctly, 1 if simulation ended or thread died
 */
int		ask_for_forks(t_philo_data *data, struct timeval *now);

/*******************
 *	print_error.c
 ******************/

/**
 * @brief prints error message
 * @param error Error code identificator
 * @return FN_FAILED (1)
 */
int		print_error(enum e_error_codes error);

/*******************
 *	libft_utils.c
 ******************/

/**
 * @brief Turns a string type to int
 * @param str String to be turned
 * @return 1 if it cannot be turned. Otherwise, 0
 */
int		ft_atoi(const char *str);

/**
 * @brief Prints a message on file descriptor
 * @param s string
 * @param fd file descriptor
 */
void	ft_putstr_fd(char *s, int fd);

#endif
