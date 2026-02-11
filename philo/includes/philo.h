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

typedef enum e_cd
{
	TAKING_FORK,
	EATING,
	SLEEPING,
	THINKING,
	DEAD
}	t_cd;

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
	uli						time_of_start;
	uli						time_of_death;
	bool					can_abort_simulation;
	pthread_mutex_t			*forks;
	pthread_mutex_t			mutex_start;
	pthread_mutex_t			mutex_time;
	pthread_mutex_t			mutex_print;
}	t_pm;

typedef struct				s_ph
{
	ui						id;
	bool					is_dead;
	ui						eat_counter;
	uli						last_eaten;
	pthread_t				thread;
	pthread_mutex_t			*left_fork;
	pthread_mutex_t			*right_fork;
	struct s_pm				*params;
}	t_ph;

typedef struct				s_data
{
	struct s_pm				*params;
	struct s_ph				*philos;
}	t_data;

/**
 * log.c
 */
char						*get_code_status_text(t_cd code);
void						display_error(const char *message);
void						display_log(ui id, t_cd code, t_pm *params);

/**
 * actions.c
 */
bool						action_dying(t_ph *philos);
bool						action_thinking(t_ph *philos);
bool						action_sleeping(t_ph *philos);
bool						action_eating(t_ph *philos);

/**
 * time.c
 */
int							execute_wait(uli milliseconds);
uli							get_current_timestamp(void);

/**
 * simulation.c
 */
void						start_timestamp(t_pm *params, t_ph *philos);
void						*simulation(void *arg);
void						start_simulation(t_data *data);

/**
 * utils.c
 */
long int					ft_atol(const char *nptr);
void						ft_putnbr(long long int l, int fd);
void						ft_putstr_fd(const char *s, int fd);
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
ui							get_int_size(long long int n);
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
int							main(int argc, char *argv[]);

#endif // PHILO_H
