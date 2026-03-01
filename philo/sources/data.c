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
 * void	clear_data(t_data *data);
 */
void	clear_data(t_data *data)
{
	if (data->params)
	{
		if (data->params->fork_box)
			free(data->params->fork_box);
		if (data->params->forks)
		{
			free(data->params->forks);
			data->params->forks = (pthread_mutex_t *) NULL;
		}
		free(data->params);
		data->params = (t_params *) NULL;
	}
	if (data->philos)
	{
		free(data->philos);
		data->philos = (t_philo *) NULL;
	}
}

/**
 * t_philo	*init_data_philosophers(t_params *params);
 */
t_philo	*init_data_philosophers(t_params *params)
{
	t_philo	*philos;
	t_ui	index;

	philos = (t_philo *) ft_calloc(sizeof(t_philo), params->nb_philos + 1);
	if (!philos)
		return ((t_philo *) NULL);
	index = 0;
	while (index < params->nb_philos)
	{
		philos[index].id = index;
		philos[index].is_dead = false;
		philos[index].eat_count = 0;
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
 * void	reset_fork_boxes(t_ui **fork_boxes, t_ui len);
 */
void	reset_fork_boxes(t_ui **fork_boxes, t_ui len)
{
	t_ui		index;
	t_ui		*boxes;

	index = 0;
	boxes = *fork_boxes;
	while (index < len)
	{
		boxes[index] = 1;
		index += 1;
	}
}

/**
 * t_params	*init_data_parameters(int argc, char *argv[]);
 */
t_params	*init_data_parameters(int argc, char *argv[])
{
	t_params	*params;

	params = (t_params *) ft_calloc(sizeof(t_params), 1);
	if (!params)
		return ((t_params *) NULL);
	params->nb_philos = (t_ui) ft_atol(argv[1]);
	params->fork_box = (t_ui *) ft_calloc(sizeof(t_ui), params->nb_philos);
	if (!params->fork_box)
		return (free(params), (t_params *) NULL);
	reset_fork_boxes(&params->fork_box, params->nb_philos);
	params->time_to_die = (t_ui) ft_atol(argv[2]);
	params->time_to_eat = (t_ui) ft_atol(argv[3]);
	params->time_to_sleep = (t_ui) ft_atol(argv[4]);
	params->eating_limit = -1;
	if (argc == 6)
		params->eating_limit = (int) ft_atol(argv[5]);
	params->time_of_start = 0;
	params->can_abort_simulation = false;
	params->first_death_encountered = false;
	params->forks = (pthread_mutex_t *) NULL;
	return (params);
}

/**
 * bool	init_data(int argc, char *argv[], t_data *data);
 */
bool	init_data(int argc, char *argv[], t_data *data)
{
	if (!verify_parameters(argc, argv))
		return (display_error(ERROR_AG), false);
	data->params = init_data_parameters(argc, argv);
	if (!data->params)
		return (display_error(ERROR_AM), clear_data(data), false);
	data->philos = init_data_philosophers(data->params);
	if (!data->philos)
		return (display_error(ERROR_AM), clear_data(data), false);
	return (true);
}
