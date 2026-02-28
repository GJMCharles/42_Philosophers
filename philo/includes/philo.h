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

# ifndef ERROR_AG
#  define ERROR_AG "Invalid arguments"
# endif

# ifndef ERROR_AM
#  define ERROR_AM "Failed to allocate memory"
# endif

typedef enum e_status
{
	TAKING_FORK,
	EATING,
	SLEEPING,
	THINKING,
	DEAD
}	t_status;

typedef unsigned char		t_uc;
typedef unsigned int		t_ui;
typedef unsigned long int	t_uli;

typedef struct s_params
{
	t_ui					nb_philos;
	t_ui					time_to_die;
	t_ui					time_to_eat;
	t_ui					time_to_sleep;
	int						eating_limit;
	t_uli					time_of_start;
	bool					can_abort_simulation;
	t_ui					*fork_box;
	pthread_mutex_t			*forks;
	pthread_mutex_t			mutex_start;
	pthread_mutex_t			mutex_pick;
	pthread_mutex_t			mutex_wait;
	pthread_mutex_t			mutex_abort;
	pthread_mutex_t			mutex_print;
}	t_params;

typedef struct s_philo
{
	t_ui					id;
	bool					is_dead;
	int						eat_count;
	t_uli					last_eaten;
	pthread_t				thread;
	pthread_mutex_t			*left_fork;
	pthread_mutex_t			*right_fork;
	struct s_params			*params;
}	t_philo;

typedef struct s_data
{
	struct s_params				*params;
	struct s_philo				*philos;
}	t_data;

/**
 * forks.c
 */
bool						search_left_fork(t_philo *philo);
bool						search_right_fork(t_philo *philo);
void						return_left_fork(t_philo *philo);
void						return_right_fork(t_philo *philo);

/**
 * abort.c
 */
bool						get_abort_simulation(t_params *params);
void						set_abort_simulation(t_params *params, bool value);

/**
 * log.c
 */
char						*get_code_status_text(t_status code);
void						display_error(const char *message);
void						display_log(t_ui id, t_status code, t_params *params);

/**
 * actions.c
 */
void						action_dying(t_philo *philo);
bool						action_thinking(t_philo *philo);
bool						action_sleeping(t_philo *philo);
void						start_eating(bool *status,
								t_philo *philo, t_params *params);
bool						action_eating(t_philo *philo);

/**
 * time.c
 */
t_uli						get_timestamp(void);
t_uli						get_delay_from_last_meal(t_philo *philo);
bool						waiting(t_uli milliseconds, t_philo *philo);
void						start_timestamp(t_params *params, t_philo *philo);

/**
 * simulation.c
 */
//void						everyone_should_be_satiated(t_philo *philo);
bool						should_abort(t_philo *philo);
void						*simulation(void *arg);
void						start_simulation(t_data *data);

/**
 * utils.c
 */
long int					ft_atol(const char *nptr);
void						ft_putnbr_fd(long long int l, int fd);
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
t_ui						get_int_size(long long int n);
bool						verify_parameters(int argc, char *argv[]);

/**
 * data.c
 */
void						clear_data(t_data *data);
t_philo						*init_data_philosophers(t_params *params);
void						reset_fork_boxes(t_ui **fork_boxes, t_ui len);
t_params					*init_data_parameters(int argc, char *argv[]);
bool						init_data(int argc, char *argv[], t_data *data);

#endif // PHILO_H
