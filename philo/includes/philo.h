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

# ifndef TRUE
#  define TRUE 1
# endif

# ifndef FALSE
#  define FALSE 0
# endif

# ifndef ERROR_01
#  define ERROR_01 "X"
# endif

# ifndef ERROR_02
#  define ERROR_02 "X"
# endif

# ifndef ERROR_03
#  define ERROR_03 "X"
# endif

# ifndef ERROR_04
#  define ERROR_04 "X"
# endif

# ifndef ERROR_05
#  define ERROR_05 "X"
# endif

typedef enum e_action_code
{
	IDLE,
	FORK,
	EATING,
	SLEEPING,
	THINKING,
	DEAD
}	t_action_code;

typedef struct s_param
{
	unsigned int		nb_philos;
	unsigned int		time_to_die;
	unsigned int		time_to_eat;
	unsigned int		time_to_sleep;
	int					eating_limits;
	unsigned int		*array_eat_count;
	unsigned long int	start_timestamp;
	unsigned int		minimum_eaten;
	unsigned char		abort_simulation;
	pthread_mutex_t		*forks;
	pthread_mutex_t		mutex_start;
	pthread_mutex_t		mutex_eating;
	pthread_mutex_t		mutex_sleeping;
	pthread_mutex_t		mutex_thinking;
	pthread_mutex_t		mutex_timestamp;
	pthread_mutex_t		mutex_print;
	pthread_mutex_t		mutex_dead;
}	t_param;

typedef struct s_philo
{
	unsigned int		id;
	unsigned char		is_dead;
	unsigned long int	last_eaten;
	struct s_param		*param;
	pthread_t			thread;
	pthread_mutex_t		*left_fork;
	pthread_mutex_t		*right_fork;
}	t_philo;

typedef struct s_data
{
	struct s_param		*param;
	struct s_philo		*philo;
}	t_data;


/**
 * validation.c
 */
int					are_philosophers_satisfied(t_param *param);
int					is_philosopher_alive(t_philo *philo, t_param *param);
int					validate_arguments(int argc, char *argv[]);

/**
 * actions.c
 */
void				action_die(t_philo *philo, t_param *param);
int					action_think(t_philo *philo, t_param *param);
int					action_sleep(t_philo *philo, t_param *param);
void				action_solo(t_philo *philo, t_param *param);
int					action_eat(t_philo *philo, t_param *param);

/**
 * simulation.c
 */
char				*get_action_text(t_action_code code);
void				display_log(t_action_code code, t_philo *philo);
void				display_log(t_action_code code, t_philo *philo);
void				*simulation(void *arg);
void				start_simulation(t_data **data);

/**
 * threads.c
 */
void				destroy_forks_pthreads(t_data **data, unsigned int index);
void				destroy_param_pthreads(t_data **data, unsigned int code);
int					init_pthreads(t_data **data);

/**
 * data.c
 */
void				free_data(t_data **data);
t_philo				*init_philosophers(t_param *param);
t_param				*init_parameters(int argc, char *argv[]);
t_data				*build_data(int argc, char *argv[]);

/**
 * utils.c
 */
unsigned long int	get_current_timestamp(void);
int					ft_usleep(unsigned long int milliseconds);
void				*ft_calloc(size_t nmemb, size_t size);
int					ft_isdigit(int c);
int					ft_atoi(const char *nptr);

/**
 * ,main.c
 */
void				display_error(const char *message);

#endif // PHILO_H
