/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grcharle <grcharle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/10 16:31:39 by grcharle          #+#    #+#             */
/*   Updated: 2026/02/10 16:31:52 by grcharle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

/**
 * 
 */
bool	action_dying(t_ph *philo)
{
	t_pm	*params;

	params = philo->params;
	display_log(philo->id, DEAD, params);
	return (true);
}

/**
 * 
 */
bool	action_thinking(t_ph *philo)
{
	t_pm	*params;

	params = philo->params;
	if (should_abort(philo))
		return (false);
	display_log(philo->id, THINKING, params);
	return (true);
}

/**
 * 
 */
bool	action_sleeping(t_ph *philo)
{
	t_pm	*params;

	params = philo->params;
	if (should_abort(philo))
		return (false);
	display_log(philo->id, SLEEPING, params);
	if (!waiting(params->time_to_sleep, philo))
		return (false);
	return (true);
}

/**
 * 
 */
bool	action_eating(t_ph *philo)
{
	t_pm	*params;

	params = philo->params;
	if (should_abort(philo))
		return (false);
	(void) pthread_mutex_lock(philo->left_fork);
	display_log(philo->id, TAKING_FORK, params);
	if (params->total == 1)
		(void) waiting(params->time_to_die, philo);
	if (should_abort(philo))
		return (pthread_mutex_unlock(philo->left_fork), false);
	(void) pthread_mutex_lock(philo->right_fork);
	display_log(philo->id, TAKING_FORK, params);
	display_log(philo->id, EATING, params);
	philo->last_eaten = get_timestamp();
	philo->eat_counter += 1;
	everyone_should_be_satiated(philo);
	if(!waiting(params->time_to_eat, philo))
	{
		return (pthread_mutex_unlock(philo->right_fork),
			pthread_mutex_unlock(philo->left_fork), false);
	}
	philo->last_eaten = get_timestamp();
	return (pthread_mutex_unlock(philo->right_fork),
		pthread_mutex_unlock(philo->left_fork), true);
}
