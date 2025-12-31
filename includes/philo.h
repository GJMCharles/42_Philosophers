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
	unsigned int	id;
	pthread_t		start_mutex;
	pthread_t		meal_thomas;
	pthread_t		death_mutex;
	struct s_philo	*prev;
	struct s_philo	*next;
}	t_philo;

typedef struct s_param
{
	unsigned int	nb_philos;
	unsigned int	time_to_die;
	unsigned int	time_to_eat;
	unsigned int	time_to_sleep;
	unsigned int	count_eating_limits;
	unsigned int	death_encountered;
	unsigned int	total_satisfaction;
}	t_param;

// void	*philosopher_actions(void *arg);
// void	clear_data(t_data *data);
// int		initialize_philosophers(t_data *data);
// int		initialize_parameters(t_data *data, int argc, char **argv);

void	add_back_philo_list(t_philo **list, t_philo *back_node);
void	clear_philo_list(t_philo **list);
void	flush_data(t_data *data);
int		initialize_philosophers(t_data *data);
int		initialize_parameters(int argc, char **argv, t_data *data);
int		set_data(int argc, char **argv, t_data *data);
int		validate_parameters(int argc, char **argv);

#endif // PHILO_H
