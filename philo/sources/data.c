/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grcharle <grcharle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/05 17:39:16 by grcharle          #+#    #+#             */
/*   Updated: 2026/02/09 11:18:25 by grcharle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

/**
 * 
 */
void	clear_data(t_data *data)
{
	if (data->params)
	{
		free(data->params);
		data->params = (t_pm *) NULL;
	}
	if (data->philos)
	{
		free(data->philos);
		data->philos = (t_ph *) NULL;
	}
}

/**
 * 
 */
t_ph	*init_data_philosophers(t_pm *params)
{
	t_ph	*philos;
	t_ui	index;

	philos = (t_ph *) ft_calloc(sizeof(t_ph), params->total + 1);
	if (!philos)
		return ((t_ph *) NULL);
	index = 0;
	while (index < params->total)
	{
		philos[index].id = index;
		philos[index].is_dead = false;
		philos[index].eat_counter = 0;
		philos[index].last_eaten = 0;
		philos[index].thread = 0;
		philos[index].left_fork = (pthread_mutex_t *) NULL;
		philos[index].right_fork = (pthread_mutex_t *) NULL;
		philos[index].params = params;
		index += 1;
	}
	return (philos);
}

/**
 * 
 */
t_pm	*init_data_parameters(int argc, char *argv[])
{
	t_pm	*params;

	params = (t_pm *) ft_calloc(sizeof(t_pm), 1);
	if (!params)
		return ((t_pm *) NULL);
	params->total = (t_ui) ft_atol(argv[1]);
	params->time_to_die = (t_ui) ft_atol(argv[2]);
	params->time_to_eat = (t_ui) ft_atol(argv[3]);
	params->time_to_sleep = (t_ui) ft_atol(argv[4]);
	params->eating_limit = -1;
	if (argc == 6)
		params->eating_limit = (int) ft_atol(argv[5]);
	params->time_of_start = 0;
	params->time_of_death = 0;
	params->can_abort_simulation = false;
	params->mutex_start = (pthread_mutex_t){0};
	params->mutex_time = (pthread_mutex_t){0};
	params->mutex_print = (pthread_mutex_t){0};
	return (params);
}

/**
 * 
 */
bool	init_data(int argc, char *argv[], t_data *data)
{
	if (!verify_parameters(argc, argv))
	{
		display_error(ERROR_01);
		return (false);
	}
	data->params = init_data_parameters(argc, argv);
	if (!data->params)
	{
		display_error(ERROR_01);
		return (clear_data(data), false);
	}
	data->philos = init_data_philosophers(data->params);
	if (!data->philos)
	{
		display_error(ERROR_01);
		return (clear_data(data), false);
	}
	return (true);
}
