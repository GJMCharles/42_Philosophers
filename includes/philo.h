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
# include <stdlib.h>
# include <stdio.h>
# include "libft.h"

# ifndef TRUE
#  define TRUE 1
# endif

# ifndef FALSE
#  define FALSE 0
# endif

typedef enum e_status {
	IDLE,
	THINKING,
	EATING,
	SLEEPING,
	DEAD
} ActionCode;

typedef struct s_param
{
	unsigned int		nb_philos;
	unsigned int		time_to_die;
	unsigned int		time_to_eat;
	unsigned int		time_to_sleep;
	int					eating_limits;
}	t_param;

typedef struct s_philo
{
	unsigned int		id;
	int					eat_counter;
	ActionCode			status;
	pthread_t			thread;
	pthread_mutex_t		fork;
	// unsigned long int	time_start;
	struct s_param		*param;
	struct s_philo		*prev;
	struct s_philo		*next;
}	t_philo;

typedef struct s_data
{
	struct s_param		*param;
	struct s_philo		*philo;
	// pthread_mutex_t		start_mutex;
	// pthread_mutex_t		start_mutex;
	// unsigned long int	starting_time;
	// unsigned short int	death_encountered;
	// unsigned short int	huger_fulfilled;
}	t_data;

void		*philosopher_actions(void *arg);
long int	get_elapsed_time(void);
int			join_threads(t_data *data);
int			create_threads(t_data *data);
int			manage_threads(t_data *data);
void		display_philosophers(t_data *data);

// void		start_mutex(t_data *data);
// int			destroy_mutex(t_data *data);
// int			initialise_mutex_fork(t_philo **philo);
// int			initialise_mutex(t_data *data);

void		add_philosopher(t_philo *new_philo, t_philo **list);
void		clear_philosophers(t_philo **list);
t_philo		*new_philosopher(unsigned int index);

void		free_all(t_data *data);
t_philo		*initialise_philosophers(t_param *param);
t_param		*initialise_parameters(int argc, char *argv[]);
int			verify_data(int argc, char *argv[]);
int			initialise_data(t_data *data, int argc, char *argv[]);

#endif // PHILO_H
