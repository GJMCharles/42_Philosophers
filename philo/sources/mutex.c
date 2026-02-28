/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mutex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grcharle <grcharle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/09 17:16:45 by grcharle          #+#    #+#             */
/*   Updated: 2026/02/09 18:41:38 by grcharle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

/**
 * void	destroy_pthreads_philos(t_data *data);
 */
void	destroy_pthreads_philos(t_data *data)
{
	t_ui		index;
	t_params	*params;

	index = 0;
	params = data->params;
	while (index < params->nb_philos)
	{
		(void) pthread_mutex_destroy(&params->forks[index]);
		index += 1;
	}
}

/**
 * void	assign_fork_to_philosophers(t_data *data);
 */
void	assign_fork_to_philosophers(t_data *data)
{
	t_params	*params;
	t_philo		*philos;
	t_ui		index;
	t_ui		index_plus;

	params = data->params;
	philos = data->philos;
	index = 0;
	while (index < params->nb_philos)
	{
		index_plus = (index + 1) % params->nb_philos;
		if ((index % 2) == 0)
		{
			philos[index].left_fork = &params->forks[index];
			philos[index].right_fork = &params->forks[index_plus];
		}
		else
		{
			philos[index].left_fork = &params->forks[index_plus];
			philos[index].right_fork = &params->forks[index];
		}
		index += 1;
	}
}

/**
 * bool	init_mutex_philosophers(t_data *data);
 */
bool	init_mutex_philosophers(t_data *data)
{
	t_params	*params;
	t_ui		index;

	params = data->params;
	params->forks = (pthread_mutex_t *)
		ft_calloc(sizeof(pthread_mutex_t), params->nb_philos);
	if (!params->forks)
		return (destroy_pthreads_parameters(data, 0), false);
	index = 0;
	while (index < params->nb_philos)
	{
		if (pthread_mutex_init(&params->forks[index], NULL))
		{
			destroy_pthreads_parameters(data, 0);
			while (index)
			{
				(void) pthread_mutex_destroy(&params->forks[index - 1]);
				index -= 1;
			}
			return (free(params->forks), false);
		}
		index += 1;
	}
	assign_fork_to_philosophers(data);
	return (true);
}

/**
 * void	destroy_pthreads_parameters(t_data *data, int pos);
 */
void	destroy_pthreads_parameters(t_data *data, int pos)
{
	t_params	*params;

	params = data->params;
	if (pos == 0)
		pos = 99;
	if (pos >= 1)
		(void) pthread_mutex_destroy(&params->mutex_start);
	if (pos >= 2)
		(void) pthread_mutex_destroy(&params->mutex_pick);
	if (pos >= 3)
		(void) pthread_mutex_destroy(&params->mutex_wait);
	if (pos >= 4)
		(void) pthread_mutex_destroy(&params->mutex_abort);
	if (pos >= 5)
		(void) pthread_mutex_destroy(&params->mutex_print);
}

/**
 * bool	init_mutex_parameters(t_data *data);
 */
bool	init_mutex_parameters(t_data *data)
{
	t_params	*params;

	params = data->params;
	if (pthread_mutex_init(&params->mutex_start, (pthread_mutexattr_t *) NULL))
		return (destroy_pthreads_parameters(data, 1), false);
	if (pthread_mutex_init(&params->mutex_pick, (pthread_mutexattr_t *) NULL))
		return (destroy_pthreads_parameters(data, 2), false);
	if (pthread_mutex_init(&params->mutex_wait, (pthread_mutexattr_t *) NULL))
		return (destroy_pthreads_parameters(data, 3), false);
	if (pthread_mutex_init(&params->mutex_abort, (pthread_mutexattr_t *) NULL))
		return (destroy_pthreads_parameters(data, 4), false);
	if (pthread_mutex_init(&params->mutex_print, (pthread_mutexattr_t *) NULL))
		return (destroy_pthreads_parameters(data, 5), false);
	return (true);
}
