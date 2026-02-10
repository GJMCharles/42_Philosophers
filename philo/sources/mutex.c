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

void	destroy_pthreads_philos(t_data *data)
{
	ui		index;
	t_pm	*params;

	index = 0;
	params = data->params;
	while (index < params->total)
	{
		(void) pthread_mutex_destroy(&params->forks[index]);
		index += 1;
	}
	free(params->forks);
}

void	assign_fork_to_philosophers(t_data *data)
{
	ui		index;
	t_pm	*params;
	t_ph	*philos;

	index = 0;
	params = data->params;
	philos = data->philos;
	while (index < params->total)
	{
		if ((index % 2) == 0)
		{
			philos[index].left_fork = &params->forks[index];
			philos[index].right_fork =
				&params->forks[(index + 1) % params->total];
		}
		else
		{
			philos[index].left_fork =
				&params->forks[(index + 1) % params->total];
			philos[index].right_fork = &params->forks[index];
		}
		index += 1;
	}
}

bool	init_mutex_philosophers(t_data *data)
{
	t_pm			*params;
	ui				index;

	params = data->params;
	params->forks = (pthread_mutex_t *)
		ft_calloc(sizeof(pthread_mutex_t), params->total);
	if (!params->forks)
		return (false);
	index = 0;
	while (index < params->total)
	{
		if (pthread_mutex_init(&params->forks[index], NULL))
		{
			while (index--)
				(void) pthread_mutex_destroy(&params->forks[index]);
			return (free(params->forks), false);
		}
		index += 1;
	}
	assign_fork_to_philosophers(data);
	return (true);
}

void	destroy_pthreads_parameters(t_data *data, int pos)
{
	t_pm	*params;

	params = data->params;
	if (pos == 0)
		pos = 99;
	if (pos >= 1)
		(void) pthread_mutex_destroy(&params->mutex_start);
	if (pos >= 2)
		(void) pthread_mutex_destroy(&params->mutex_time);
	if (pos >= 3)
		(void) pthread_mutex_destroy(&params->mutex_print);
	if (pos >= 4)
		(void) pthread_mutex_destroy(&params->mutex_eat);
	if (pos >= 5)
		(void) pthread_mutex_destroy(&params->mutex_sleep);
	if (pos >= 6)
		(void) pthread_mutex_destroy(&params->mutex_think);
	if (pos >= 7)
		(void) pthread_mutex_destroy(&params->mutex_die);
}

bool	init_mutex_parameters(t_data *data)
{
	t_pm	*params;

	params = data->params;
	if (pthread_mutex_init(&params->mutex_start, (pthread_mutexattr_t *) NULL))
		return (destroy_pthreads_parameters(data, 1), false);
	if (pthread_mutex_init(&params->mutex_time, (pthread_mutexattr_t *) NULL))
		return (destroy_pthreads_parameters(data, 2), false);
	if (pthread_mutex_init(&params->mutex_print, (pthread_mutexattr_t *) NULL))
		return (destroy_pthreads_parameters(data, 3), false);
	if (pthread_mutex_init(&params->mutex_eat, (pthread_mutexattr_t *) NULL))
		return (destroy_pthreads_parameters(data, 4), false);
	if (pthread_mutex_init(&params->mutex_sleep, (pthread_mutexattr_t *) NULL))
		return (destroy_pthreads_parameters(data, 5), false);
	if (pthread_mutex_init(&params->mutex_think, (pthread_mutexattr_t *) NULL))
		return (destroy_pthreads_parameters(data, 6), false);
	if (pthread_mutex_init(&params->mutex_die, (pthread_mutexattr_t *) NULL))
		return (destroy_pthreads_parameters(data, 7), false);
	return (true);
}
