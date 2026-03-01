/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   forks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grcharle <grcharle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/28 06:15:11 by grcharle          #+#    #+#             */
/*   Updated: 2026/02/28 06:15:30 by grcharle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

/**
 * bool	pick_left_fork(t_philo *ph);
 */
bool	pick_left_fork(t_philo *ph)
{
	t_params	*params;
	t_ui		id_plus;

	params = ph->params;
	id_plus = (ph->id + 1) % params->nb_philos;
	while (1)
	{
		(void) pthread_mutex_lock(&params->mutex_pick);
		if (should_abort(ph))
			return (pthread_mutex_unlock(&params->mutex_pick), false);
		if ((ph->id % 2) == 0 && params->fork_box[ph->id] == 1)
		{
			params->fork_box[ph->id] = 0;
			return (pthread_mutex_unlock(&params->mutex_pick), true);
		}
		else if ((ph->id % 2) != 0 && params->fork_box[id_plus] == 1)
		{
			params->fork_box[id_plus] = 0;
			return (pthread_mutex_unlock(&params->mutex_pick), true);
		}
		(void) pthread_mutex_unlock(&params->mutex_pick);
		usleep(100);
	}
	return (true);
}

/**
 * bool	pick_right_fork(t_philo *ph);
 */
bool	pick_right_fork(t_philo *ph)
{
	t_params	*params;
	t_ui		id_plus;

	params = ph->params;
	id_plus = (ph->id + 1) % params->nb_philos;
	while (1)
	{
		(void) pthread_mutex_lock(&params->mutex_pick);
		if (should_abort(ph))
			return (pthread_mutex_unlock(&params->mutex_pick), false);
		if ((ph->id % 2) == 0 && params->fork_box[id_plus] == 1)
		{
			params->fork_box[id_plus] = 0;
			return (pthread_mutex_unlock(&params->mutex_pick), true);
		}
		else if ((ph->id % 2) != 0 && params->fork_box[ph->id] == 1)
		{
			params->fork_box[ph->id] = 0;
			return (pthread_mutex_unlock(&params->mutex_pick), true);
		}
		(void) pthread_mutex_unlock(&params->mutex_pick);
		usleep(100);
	}
	return (true);
}

/**
 * void	return_left_fork(t_philo *philo);
 */
void	return_left_fork(t_philo *philo)
{
	t_params	*params;
	t_ui		id_plus;

	params = philo->params;
	id_plus = (philo->id + 1) % params->nb_philos;
	pthread_mutex_lock(&params->mutex_pick);
	if ((philo->id % 2) == 0)
		params->fork_box[philo->id] = 1;
	else if ((philo->id % 2) != 0)
		params->fork_box[id_plus] = 1;
	pthread_mutex_unlock(&params->mutex_pick);
}

/**
 * void	return_right_fork(t_philo *philo);
 */
void	return_right_fork(t_philo *philo)
{
	t_params	*params;
	t_ui		id_plus;

	params = philo->params;
	id_plus = (philo->id + 1) % params->nb_philos;
	pthread_mutex_lock(&params->mutex_pick);
	if ((philo->id % 2) == 0)
		params->fork_box[id_plus] = 1;
	else if ((philo->id % 2) != 0)
		params->fork_box[philo->id] = 1;
	pthread_mutex_unlock(&params->mutex_pick);
}
