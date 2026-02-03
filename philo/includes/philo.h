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

//typedef enum e_status
//{
//	IDLE,
//	FORK,
//	EATING,
//	SLEEPING,
//	THINKING,
//	DEAD
//}	t_status;

typedef struct s_param
{
	unsigned int		nb_philos;
	unsigned int		time_to_die;
	unsigned int		time_to_eat;
	unsigned int		time_to_sleep;
	int					eating_limits;
	unsigned int		minimum_eaten;
	unsigned long int	start_timestamp;
	unsigned char		abort_simulation;
	pthread_mutex_t		mutex_start;
	pthread_mutex_t		mutex_wait;
	pthread_mutex_t		mutex_timestamp;
	pthread_mutex_t		mutex_print;
	pthread_mutex_t		mutex_dead;
}	t_param;

typedef struct s_philo
{
	unsigned int		id;
	unsigned char		is_dead;
	unsigned long int	last_eaten;
	unsigned int		eating_counter;
	struct s_param		*param;
	struct s_philo		*prev;
	struct s_philo		*next;
	pthread_t			thread;
	pthread_mutex_t		fork;
}	t_philo;

typedef struct s_data
{
	struct s_param		*param;
	struct s_philo		*philo;
}	t_data;

#endif // PHILO_H
