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

void start_eating(t_philo *philo)
{
	pthread_mutex_lock(&(philo->param->mutex_eating));
	philo->status = EATING;
	display_current_status(philo);
	forced_waiting(philo->param, philo->param->time_to_eat);
	pthread_mutex_unlock(&(philo->param->mutex_eating));
 }

int action_eat(t_philo *philo)
{
	pthread_mutex_lock(&(philo->fork));
	if (philo->param->abort_simulator == TRUE)
		return (pthread_mutex_unlock(&(philo->fork)), FALSE);
	philo->status = FORK;
	display_current_status(philo);
	if (philo->next == (t_philo *) NULL)
	{
		philo->status = DEAD;
		philo->param->abort_simulator = TRUE;
		forced_waiting(philo->param, philo->param->time_to_die);
		return (pthread_mutex_unlock(&(philo->fork)), FALSE);
	}
	pthread_mutex_lock(&(philo->next->fork));
	if (philo->param->abort_simulator == TRUE)
		return (pthread_mutex_unlock(&(philo->next->fork)), FALSE);
	display_current_status(philo);
	start_eating(philo);
	pthread_mutex_unlock(&(philo->next->fork));
	pthread_mutex_unlock(&(philo->fork));
	return (TRUE);
}
