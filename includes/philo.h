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
	PICK_FORK,
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

// int					exec_mutex(void *mutex, t_philo *p, int (*fn)(t_philo *));
// void				action_think(t_philo *philo);
// void				action_sleep(t_philo *philo);
// void				action_eat(t_philo *philo);

// int					death_callback(t_philo *philo);
// int					think_callback(t_philo *philo);
// int					sleep_callback(t_philo *philo);
// int					eat_callback(t_philo *philo);

// void				print_status(t_philo *philo);
// int					can_abort_simulation(t_philo *philo);
// unsigned long int	get_timestamp_ms(void);
// void				forced_waiting(unsigned int duration);
// char				*get_text_from_status(t_status code);
// void				waiting_loader(t_param *param, unsigned int *is_init);
// void				*simulation(void *arg);
// void				start_simulation(t_data **data);

// void				destroy_pthread_mutex(t_data **data);
// void				init_pthread_mutex(t_data **data);

// void				clear_philosophers(t_philo **list);
// void				append_philosopher(t_philo *node, t_philo **list);
// t_philo				*new_philosopher(unsigned int index);

// void				free_data(t_data **data);
// t_philo				*init_philosophers(t_param *param);
// t_param				*init_parameters(int argc, char *argv[]);
// int					verify_arguments(int argc, char *argv[]);
// t_data				*build_data(int argc, char *argv[]);

char	*get_text_from_status(t_status code);
unsigned long int	get_timestamp_ms(void);
void	print_status(t_philo *philo);
void	*simulation(void *arg);
void	start_simulation(t_data **data);
void	destroy_pthread_mutex(t_data **data);
void	init_pthread_mutex(t_data **data);
void	clear_philosophers(t_philo **list);
void	append_philosopher(t_philo *node, t_philo **list);
t_philo	*new_philosopher(unsigned int index);
t_philo	*init_philosophers(t_param *param);
t_param	*init_parameters(int argc, char *argv[]);
void	free_data(t_data **data);
t_data	*build_data(int argc, char *argv[]);
int	verify_arguments(int argc, char *argv[]);

#endif // PHILO_H
