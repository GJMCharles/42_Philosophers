/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grcharle </var/spool/mail/grcharle>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/17 23:53:58 by grcharle          #+#    #+#             */
/*   Updated: 2025/11/17 23:53:59 by grcharle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <pthread.h>
# include <sys/time.h>
# include "libft.h"

#ifndef TRUE
# define TRUE 1
#endif

#ifndef FALSE
# define FALSE 0
#endif

typedef enum e_status {
	IDLE,
	THINKING,
	EATING,
	SLEEPING,
	DEAD
} StatusCodes;

typedef struct s_params
{
	unsigned int		nbr_philos;
	unsigned int		time_die;
	unsigned int		time_eat;
	unsigned int		time_sleep;
	int					limit_nbr_eat;
}	t_params;

typedef struct s_philos
{
	unsigned int		id;
	unsigned int		eat_count;
	unsigned short int	fork;
	StatusCodes			status;
	pthread_t			thread;
	struct s_params		*params;
	unsigned long int	time_start;
	unsigned long int	timestamp;
}	t_philos;

typedef struct s_data
{
	unsigned short int	dead_encountered;
	unsigned short int	huger_fulfilled;
	struct s_params		*params;
	struct s_philos		*philos;
}	t_data;

int			initialise_thread(t_data *data);
t_philos	*initiate_philosophers(t_params *params);
t_params	*initiate_parameters(int argc, char *argv[]);
void		free_all(t_data *data);
int			verify_data(int argc, char *argv[]);
int			initialise_data(t_data *data, int argc, char *argv[]);

#endif // PHILO_H
