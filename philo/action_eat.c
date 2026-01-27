/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   action_eat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grcharle <grcharle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/14 06:52:37 by grcharle          #+#    #+#             */
/*   Updated: 2026/01/14 06:52:51 by grcharle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	start_eating(t_philo *philo)
{
	pthread_mutex_lock(&(philo->param->mutex_eating));
	philo->status = EATING;
	display_current_state(philo);
	//usleep(philo->param->time_to_eat * 1000);
	pthread_mutex_unlock(&(philo->param->mutex_eating));
}

int action_eat(t_philo *philo)
{
	pthread_mutex_lock(&(philo->fork));
	if (philo->param->abort_simulation)
		return (pthread_mutex_unlock(&(philo->fork)), FALSE);
	philo->status = FORK;
	display_current_state(philo);
	if (!philo->next)
	{
		usleep(philo->param->time_to_die * 1000);
		philo->status = DEAD;
		philo->param->abort_simulation = TRUE;
		pthread_mutex_unlock(&(philo->fork));
		return (FALSE);
	}
	pthread_mutex_lock(&(philo->next->fork));
	if (philo->param->abort_simulation)
		return (pthread_mutex_unlock(&(philo->next->fork)), FALSE);
	display_current_state(philo);
	start_eating(philo);
	pthread_mutex_unlock(&(philo->next->fork));
	pthread_mutex_unlock(&(philo->fork));
	return (TRUE);
}
