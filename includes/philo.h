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

# include <pthread.h>
# include <sys/time.h>
# include <stdio.h>
# include "libft.h"

# ifndef TRUE
#  define TRUE 1
# endif

# ifndef FALSE
#  define FALSE 0
# endif

typedef enum e_state
{
	IDLE,
	FORK,
	EATING,
	SLEEPING,
	THINKING,
	DEAD
}	t_state;

typedef struct s_param
{
	unsigned int		nb_philos;
	unsigned int		time_to_die;
	unsigned int		time_to_eat;
	unsigned int		time_to_sleep;
	int					eating_limits;
	unsigned int		minimum_eaten;
	unsigned long int	start_timestamp;
	unsigned char		abort_simulator;
	pthread_mutex_t		*forks;
	pthread_mutex_t		mutex_start;
	pthread_mutex_t		mutex_wait;
	pthread_mutex_t		mutex_print;
	pthread_mutex_t		mutex_dead;
	/**	
	//pthread_mutex_t		mutex_wait;
	//pthread_mutex_t		mutex_print;
	//
	*/
}	t_param;

typedef struct s_philo
{
	unsigned int		id;
	t_state				state;
	pthread_t			thread;
	unsigned long int	last_eaten;
	unsigned int		eating_counter;
	struct s_param		*param;
	struct s_philo		*next;
}	t_philo;

typedef struct s_data
{
	struct s_param		*param;
	struct s_philo		*philo;
}	t_data;

void					forced_waiting(t_param *param, unsigned int delay);
void					display_message(t_philo *philo, char *message);
int						exec_pthread_mutex(
							pthread_mutex_t *mutex, 
							t_philo *philo, 
							t_param *param, 
							int (*f)(t_philo *, t_param *));

void					action_die(t_philo *philo, t_param *param);
int						action_eat(t_philo *philo, t_param *param);
int						action_sleep(t_philo *philo, t_param *param);
int						action_think(t_philo *philo, t_param *param);

unsigned long int		get_timestamp_ms(void);
void					set_timestamp(t_philo *philo, t_param *param);
void					start_simulator(t_data **data);
void					destroy_pthreads_mutex(t_data **data);
void					init_pthreads_mutex(t_data **data);
void					clear_philosophers(t_philo **list);
void					append_philosopher(t_philo *node, t_philo **list);
t_philo					*new_philosopher(void);
t_philo					*init_philosophers(t_param *param);
t_param					*init_parameters(int argc, char *argv[]);
void					free_data(t_data **data);
t_data					*build_data(int argc, char *argv[]);
int						verify_arguments(int argc, char *argv[]);

#endif // PHILO_H
