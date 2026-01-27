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
	long int			start_timestamp;
	unsigned char		abort_simulation;
	pthread_mutex_t		mutex_start;
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

char				*get_status_status(t_status code);
void				display_current_state(t_philo *philo);
int					exec_mutex(void *m, t_philo *philo, int (*fn)(t_philo *));
void				action_die(t_philo *philo);
int					action_think(t_philo *philo);
int					action_sleep(t_philo *philo);
int					action_eat(t_philo *philo);
void				sync_simulators(t_param **param, unsigned int *is_init);
void				*simulator(void *arg);
unsigned long int	get_timestamp_ms(void);
void				start_simulators(t_data **data);
int					destroy_mutex(pthread_mutex_t *mutex);
int					init_mutex(pthread_mutex_t *mutex);
void				end_pthreads(t_data **data);
void				start_pthreads(t_data **data);
void				append_philosopher(t_philo *node, t_philo **list);
void				clear_philosophers(t_philo **list);
t_philo				*new_philosopher(void);
t_philo				*init_philosophers(t_param *param);
t_param				*init_parameters(int argc, char *argv[]);
void				free_data(t_data **data);
t_data				*build_data(int argc, char *argv[]);
int					verify_arguments(int argc, char *argv[]);

#endif // PHILO_H
