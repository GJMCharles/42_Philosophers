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
#  define ERROR_01 "Invalid arguments [values must be SUPERIOR than 0]"
# endif

# ifndef ERROR_02
#  define ERROR_02 "Denied allocation [memory RAM not accessable]"
# endif

# ifndef ERROR_03
#  define ERROR_03 "gettimeofday is invalid"
# endif

typedef enum e_philo_status
{
	TAKING_FORK,
	EATING,
	SLEEPING,
	THINKING,
	DEAD
}	t_philo_status;

typedef unsigned long int	uli;
typedef unsigned char		uc;

typedef struct				s_params
{

}	t_params;

typedef struct				s_philos
{
}	t_philos;

typedef struct				s_data
{
	struct s_params			*params;
	struct s_philos			*philo;
}	t_data;

void						start_simulation(t_data *data);
void						clear_data(t_data *data);

/**
 * utils.c
 */
void						*ft_calloc(size_t nmemb, size_t size);

/**
 * init.c
 */
int							init_pthreads(t_data *data);
int							init_data(int argc, char *argv[], t_data *data);

/**
 * main.c
 */
void						display_message(const char *message, int type);
int							main(int argc, char *argv[]);

#endif // PHILO_H
