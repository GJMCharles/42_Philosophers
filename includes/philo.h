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
# include <stdlib.h>
# include <stdio.h>

# define TRUE 1
# define FALSE 0

typedef struct s_data
{
	struct s_param	*param;
	struct s_philo	*philo;
}	t_data;

typedef struct s_philo
{
	unsigned int		id;
	unsigned short int	is_dead;
	pthread_t			thread;
}	t_philo;

typedef struct s_param
{
	unsigned int	nb_philos;
	unsigned int	time_to_die;
	unsigned int	time_to_eat;
	unsigned int	time_to_sleep;
	unsigned int	time_to_eat_count;
	unsigned int	death_encountered;
}	t_param;

void	*philosopher_actions(void *arg);
void	clear_data(t_data *data);
int		initialize_philosophers(t_data *data);
int		initialize_parameters(t_data *data, int argc, char **argv);
int		set_data(t_data *data, int argc, char **argv);
int		validate_parameters(int argc, char **argv);

#endif // PHILO_H
