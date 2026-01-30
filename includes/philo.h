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

# include "libft.h"
# include <pthread.h>
# include <sys/time.h>
# include <stdio.h>

# ifndef TRUE
#  define TRUE 1
# endif

# ifndef FALSE
#  define FALSE 0
# endif

typedef enum e_status
{
	IDLE,
	FORK,
	EATING,
	SLEEPING,
	THINKING,
	DEAD
}	t_status;

typedef struct s_param
{
	unsigned int		nb_philos;
	unsigned int		time_to_die;
	unsigned int		time_to_eat;
	unsigned int		time_to_sleep;
	int					eating_limits;
	unsigned int		test_count;
	unsigned long int	start_timestamp;
	unsigned char		abort_simulator;
	pthread_mutex_t		mutex_start;
	pthread_mutex_t		mutex_wait;
	pthread_mutex_t		mutex_timestamp;
	pthread_mutex_t		mutex_print;
	pthread_mutex_t		mutex_eating;
	pthread_mutex_t		mutex_sleeping;
	pthread_mutex_t		mutex_thinking;
	pthread_mutex_t		mutex_dead;
}	t_param;

typedef struct s_philo
{
	unsigned int		id;
	t_status			status;
	pthread_t			thread;
	unsigned long int	last_eaten;
	unsigned int		eating_counter;
	pthread_mutex_t		fork;
	struct s_param		*param;
	struct s_philo		*next;
}	t_philo;

typedef struct s_data
{
	struct s_param		*param;
	struct s_philo		*philo;
}	t_data;

int						exec_mutex(pthread_mutex_t mutex, \
							t_philo *philo, t_param *param, \
							int (*f)(t_philo *, t_param *));
int						everyone_satiated(t_philo *philo, t_param *param);
int						should_abort_simulator(t_philo *philo, t_param *param);
char					*get_status_text(t_status code);
void					display_current_status(t_philo *philo);
void					action_die(t_philo *philo, t_param *param);
int						action_think(t_philo *philo, t_param *param);
int						action_sleep(t_philo *philo, t_param *param);
int						start_eating(t_philo *philo, t_param *param);
void					forced_waiting(t_param *param, unsigned int delay);
int						pick_right_fork(t_philo *philo, t_param *param);
int						pick_left_fork(t_philo *philo, t_param *param);
int						action_eat(t_philo *philo, t_param *param);
void					set_timestamp(t_param *param);
void					*simulator(void *arg);
unsigned long int		get_timestamp_ms(void);
void					start_simulators(t_data **data);
void					end_pthreads(t_data **data);
void					start_pthreads(t_data **data);
void					append_philosopher(t_philo *node, t_philo **list);
void					clear_philosophers(t_philo **list);
t_philo					*new_philosopher(void);
t_philo					*init_philosophers(t_param *param);
t_param					*init_parameters(int argc, char *argv[]);
void					free_data(t_data **data);
t_data					*build_data(int argc, char *argv[]);
int						verify_arguments(int argc, char *argv[]);

#endif // PHILO_H
