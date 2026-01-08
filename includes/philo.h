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
} StatusCodes;

typedef struct s_param
{
	unsigned int	nb_philos;
	unsigned int	time_to_die;
	unsigned int	time_to_eat;
	unsigned int	time_to_sleep;
	int				eating_limit;
}	t_param;

typedef struct s_philo
{
	unsigned int	id;
	int				eat_counter;
	struct s_philo	*prev;
	struct s_philo	*next;
}	t_philo;

typedef struct s_data
{
	struct s_param		*param;
	struct s_philo		*philo;
	unsigned short int	dead_encountered;
	unsigned short int	huger_fulfilled;
}	t_data;

#endif // PHILO_H
