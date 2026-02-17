/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grcharle <grcharle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/10 16:02:13 by grcharle          #+#    #+#             */
/*   Updated: 2026/02/10 16:02:27 by grcharle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

/**
 * 
 */
t_uli	get_timestamp(void)
{
	struct timeval	time;

	if (gettimeofday(&time, NULL) == -1)
		display_error("'gettimeofday' failed to load");
	return ((time.tv_sec * 1000) + (time.tv_usec / 1000));
}

/**
 * 
 */
int	execute_wait(t_uli milliseconds, t_ph *philo)
{
	t_uli	start;
	t_pm	*params;

	params = philo->params;
	start = get_timestamp();
	while ((get_timestamp() - start) < milliseconds)
	{
		pthread_mutex_lock(&params->mutex_time);
		if (params->can_abort_simulation)
			return (pthread_mutex_unlock(&params->mutex_time), 1);
		if ((get_timestamp() - philo->last_eaten) >= params->time_to_die)
		{
			params->can_abort_simulation= true;
			return (pthread_mutex_unlock(&params->mutex_time), 1);
		}
		usleep(100);
		pthread_mutex_unlock(&params->mutex_time);
	}
	return (0);
}
