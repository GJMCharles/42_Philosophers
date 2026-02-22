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

	time.tv_sec = 0;
	time.tv_usec = 0;
	gettimeofday(&time, NULL);
	return ((time.tv_sec * 1000) + (time.tv_usec / 1000));
}

t_uli	get_delay_from_last_meal(t_ph *philo)
{
	return (get_timestamp() - philo->last_eaten);
}

/**
 * 
 */
bool	waiting(t_uli milliseconds, t_ph *philo)
{
	t_uli	start;
	t_pm	*params;

	params = philo->params;
	start = get_timestamp();
	while ((get_timestamp() - start) <= milliseconds)
	{
		(void) pthread_mutex_lock(&params->mutex_time);
		if (should_abort(philo))
		{
			(void) pthread_mutex_unlock(&params->mutex_time);
			return (false);
		}
		(void) pthread_mutex_unlock(&params->mutex_time);
		usleep(100);
	}
	return (true);
}

/**
 * 
 */
void	start_timestamp(t_pm *params, t_ph *philo)
{
	(void) pthread_mutex_lock(&params->mutex_start);
	if (params->time_of_start == 0)
		params->time_of_start = get_timestamp();
	philo->last_eaten = params->time_of_start;
	(void) pthread_mutex_unlock(&params->mutex_start);
}