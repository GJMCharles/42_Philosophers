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

bool	action_dying(t_ph *philos)
{
	t_pm	*params;

	params = philos->params;
	display_log(philos->id, DEAD, params);
	return (true);
}

bool	action_thinking(t_ph *philos)
{
	t_pm	*params;

	params = philos->params;
	display_log(philos->id, THINKING, params);
	return (true);
}

bool	action_sleeping(t_ph *philos)
{
	t_pm	*params;

	params = philos->params;
	display_log(philos->id, SLEEPING, params);
	execute_wait(params->time_to_sleep);
	return (true);
}

bool	action_eating(t_ph *philos)
{
	t_pm	*params;

	params = philos->params;
	pthread_mutex_lock(philos->left_fork);
	display_log(philos->id, TAKING_FORK, params);
	pthread_mutex_lock(philos->right_fork);
	display_log(philos->id, TAKING_FORK, params);
	display_log(philos->id, EATING, params);
	execute_wait(params->time_to_eat);
	philos->last_eaten = get_current_timestamp();
	philos->eat_counter += 1;
	pthread_mutex_unlock(philos->right_fork);
	pthread_mutex_unlock(philos->left_fork);
	return (true);
}
