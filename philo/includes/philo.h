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

typedef struct				s_params
{
	ui						nb_philos;
	ui						time_to_die;
	ui						time_to_eat;
	ui						time_to_sleep;
	int						eating_limit;
	uli						time_of_death;
	bool					abort_simulation;
	pthread_mutex_t			mutex_start;
	pthread_mutex_t			mutex_timestamp;
	pthread_mutex_t			mutex_print;
	pthread_mutex_t			mutex_action_eating;
	pthread_mutex_t			mutex_action_sleeping;
	pthread_mutex_t			mutex_action_thinking;
	pthread_mutex_t			mutex_action_dying;
}	t_params;

typedef struct				s_philos
{
	ui						id;
	pthread_t				thread;
	pthread_mutex_t			left_fork;
	pthread_mutex_t			right_fork;
	bool					is_dead;
}	t_philos;

typedef struct				s_data
{
	struct s_params			*params;
	struct s_philos			*philo;
}	t_data;

// void						start_simulation(t_data *data);
void						clear_data(t_data *data);

/**
 * utils.c
 */
// int							ft_isdigit(int c);
// long int					ft_atol(const char *nptr);
// void						ft_putstr(const char *str, int fd);
// void						*ft_calloc(long int nmemb, long int size);

/**
 * init.c
 */
// void						clear_data(t_data *data);
// int							init_philos(t_data **data);
// int							init_params(t_data **data, int argc, char *argv[]);
// int							init_data(int argc, char *argv[], t_data *data);

/**
 * main.c
 */
// void						display_message(const char *message, int fd);
/*  */
int							main(int argc, char *argv[]);

#endif // PHILO_H
