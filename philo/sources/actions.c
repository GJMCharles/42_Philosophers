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
bool	secure_fork_lock(t_ph *p, pthread_mutex_t *m, int s)
{
	t_pm	*params;

	(void) s;
	params = p->params;
	if (get_abort_simulation(params))
		return (false);
	pthread_mutex_lock(m);
	//pthread_mutex_unlock(m);
	return (true);
}

/**
 * 
 */
bool	action_eating(t_ph *philo)
{
	t_pm	*params;

	params = philo->params;
	if (!secure_fork_lock(philo, philo->left_fork, 0))
		return (false);
	display_log(philo->id, TAKING_FORK, params);
	if (params->total == 1)
		(void) waiting(params->time_to_die, philo);
	if (params->total == 1 || !secure_fork_lock(philo, philo->right_fork, 0))
		return (pthread_mutex_unlock(philo->left_fork), false);
	display_log(philo->id, TAKING_FORK, params);
	display_log(philo->id, EATING, params);
	philo->last_eaten = get_timestamp();
	philo->eat_counter += 1;
	everyone_should_be_satiated(philo);
	if(!waiting(params->time_to_eat, philo))
	{
		pthread_mutex_unlock(philo->right_fork);
		pthread_mutex_unlock(philo->left_fork);
		return (false);
	}
	philo->last_eaten = get_timestamp();
	pthread_mutex_unlock(philo->right_fork);
	pthread_mutex_unlock(philo->left_fork);
	return (true);
}
