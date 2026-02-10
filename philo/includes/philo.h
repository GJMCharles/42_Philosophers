/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grcharle <grcharle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/12 00:20:15 by grcharle          #+#    #+#             */
/*   Updated: 2025/12/12 00:20:17 by grcharle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <limits.h>
# include <pthread.h>
# include <sys/time.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <string.h>
# include <stdbool.h>

# ifndef ERROR_01
#  define ERROR_01 ""
# endif

# ifndef ERROR_02
#  define ERROR_02 ""
# endif

# ifndef ERROR_03
#  define ERROR_03 ""
# endif

typedef enum e_action_status
{
	TAKING_FORK,
	EATING,
	SLEEPING,
	THINKING,
	DEAD
}	t_action_status;

typedef unsigned long int	uli;
typedef unsigned int		ui;
typedef unsigned char		uc;
typedef unsigned short int	usi;

typedef struct				s_pm
{
	ui						total;
	ui						time_to_die;
	ui						time_to_eat;
	ui						time_to_sleep;
	int						eating_limit;
	uli						time_of_death;
	bool					can_abort_simulation;
	pthread_mutex_t			*forks;
	pthread_mutex_t			mutex_start;
	pthread_mutex_t			mutex_time;
	pthread_mutex_t			mutex_print;
	pthread_mutex_t			mutex_eat;
	pthread_mutex_t			mutex_sleep;
	pthread_mutex_t			mutex_think;
	pthread_mutex_t			mutex_die;
}	t_pm;

typedef struct				s_ph
{
	ui						id;
	bool					is_dead;
	struct s_pm				*params;
	pthread_t				thread;
	pthread_mutex_t			*left_fork;
	pthread_mutex_t			*right_fork;
}	t_ph;

typedef struct				s_data
{
	struct s_pm				*params;
	struct s_ph				*philos;
}	t_data;

/**
 * simulation.c
 */
void						*simulation(void *arg);
void						start_simulation(t_data *data);

/**
 * utils.c
 */
void						ft_putstr_fd(const char *s, int fd);
int							ft_isdigit(int c);
long int					ft_atol(const char *nptr);
void						*ft_calloc(long int nmemb, long int size);

/**
 * mutex.c
 */
void						destroy_pthreads_philos(t_data *data);
void						assign_fork_to_philosophers(t_data *data);
bool						init_mutex_philosophers(t_data *data);
void						destroy_pthreads_parameters(t_data *data, int pos);
bool						init_mutex_parameters(t_data *data);

/**
 * verify.c
 */
bool						verify_parameters(int argc, char *argv[]);

/**
 * data.c
 */
void						clear_data(t_data *data);
t_ph						*init_data_philosophers(t_pm *params);
t_pm						*init_data_parameters(int argc, char *argv[]);
bool						init_data(int argc, char *argv[], t_data *data);

/**
 * main.c
 */
void						display_message(const char *message, int fd);
int							main(int argc, char *argv[]);

#endif // PHILO_H
