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

typedef enum e_status
{
	IDLE,
	THINKING,
	EATING,
	SLEEPING,
	DEAD
}	t_action_code;

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
	t_action_code		status;
	pthread_t			thread;
	pthread_mutex_t		fork;
	struct s_param		*param;
	struct s_philo		*prev;
	struct s_philo		*next;
}	t_philo;

typedef struct s_data
{
	pthread_mutex_t		mutex_start;
	struct s_param		*param;
	struct s_philo		*philo;
}	t_data;

void		display_philosophers(t_philo *philo);
void		clear_philosophers(t_philo **list);
void		append_philosopher(t_philo *node, t_philo **list);
t_philo		*new_philosopher(unsigned int index);
t_philo		*initialise_philosophers(t_param *param);
void		free_all(t_data **data);
t_param		*initialise_parameters(int argc, char *argv[]);
int			initialise_data(int argc, char *argv[], t_data **data);
void		display_error(char *message);
int			verify_arguments(int argc, char *argv[]);

#endif // PHILO_H
