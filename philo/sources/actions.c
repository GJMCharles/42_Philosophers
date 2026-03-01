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
 * void	action_dying(t_philo *philo);
*/
void	action_dying(t_philo *philo)
{
	t_params	*params;

	params = philo->params;
	pthread_mutex_lock(&params->mutex_dead);
	if (params->first_death_encountered == true)
	{
		pthread_mutex_unlock(&params->mutex_dead);
		return ;
	}
	display_log(philo->id, DEAD, params);
	if (params->first_death_encountered == false)
		params->first_death_encountered = true;
	pthread_mutex_unlock(&params->mutex_dead);
}

/**
 * bool	action_thinking(t_philo *philo);
 */
bool	action_thinking(t_philo *philo)
{
	t_params	*params;

	params = philo->params;
	if (should_abort(philo))
		return (false);
	display_log(philo->id, THINKING, params);
	return (true);
}

/**
 * bool	action_sleeping(t_philo *philo);
*/
bool	action_sleeping(t_philo *philo)
{
	t_params	*params;

	params = philo->params;
	if (should_abort(philo))
		return (false);
	display_log(philo->id, SLEEPING, params);
	if (!waiting(params->time_to_sleep, philo))
		return (false);
	return (true);
}

/**
 * void	start_eating(bool *status, t_philo *philo, t_params *params);
 */
void	start_eating(bool *status, t_philo *philo, t_params *params)
{
	philo->last_eaten = get_timestamp();
	if (!waiting(params->time_to_eat, philo))
	{
		*status = false;
	}
	if (*status == true)
	{
		philo->last_eaten = get_timestamp();
		philo->eat_count += 1;
	}
}

/**
 * bool	action_eating(t_philo *philo);
 */
bool	action_eating(t_philo *philo)
{
	t_params	*params;
	bool		status;

	status = true;
	params = philo->params;
	if (!pick_left_fork(philo))
		return (false);
	(void) pthread_mutex_lock(philo->left_fork);
	display_log(philo->id, TAKING_FORK, params);
	if (!pick_right_fork(philo))
		return (pthread_mutex_unlock(philo->left_fork), false);
	(void) pthread_mutex_lock(philo->right_fork);
	display_log(philo->id, TAKING_FORK, params);
	display_log(philo->id, EATING, params);
	start_eating(&status, philo, params);
	if (params->eating_limit > 0 && philo->eat_count == params->eating_limit)
		status = false;
	return_right_fork(philo);
	(void) pthread_mutex_unlock(philo->right_fork);
	return_left_fork(philo);
	(void) pthread_mutex_unlock(philo->left_fork);
	return (status);
}
