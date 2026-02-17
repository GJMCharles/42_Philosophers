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
	if (cannot_move(philo))
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
	if (cannot_move(philo))
		return (false);
	display_log(philo->id, SLEEPING, params);
	if (execute_wait(params->time_to_sleep, philo))
		return (false);
	return (true);
}

void	solo(t_ph *philo)
{
	t_pm	*params;

	params = philo->params;
	philo->is_dead = true;
	params->can_abort_simulation = true;
	(void) execute_wait(params->time_to_die, philo);
}

/**
 * 
 */
bool	action_eating(t_ph *philo)
{
	t_pm	*params;

	params = philo->params;
	if (cannot_move(philo))
		return (false);
	pthread_mutex_lock(philo->left_fork);
	display_log(philo->id, TAKING_FORK, params);
	if (params->total == 1)
		return (solo(philo), pthread_mutex_unlock(philo->left_fork), false);
	if (cannot_move(philo))
		return (pthread_mutex_unlock(philo->left_fork), false);
	pthread_mutex_lock(philo->right_fork);
	display_log(philo->id, TAKING_FORK, params);
	display_log(philo->id, EATING, params);
	if(execute_wait(params->time_to_eat, philo))
		return (false);
	philo->last_eaten = get_timestamp();
	philo->eat_counter += 1;
	pthread_mutex_unlock(philo->right_fork);
	pthread_mutex_unlock(philo->left_fork);
	return (true);
}
