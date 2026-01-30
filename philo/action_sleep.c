/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   action_sleep.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grcharle <grcharle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/14 06:53:05 by grcharle          #+#    #+#             */
/*   Updated: 2026/01/14 06:53:15 by grcharle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int action_sleep(t_philo *philo)
{
	pthread_mutex_lock(&(philo->param->mutex_sleeping));
	philo->param->abort_simulator = has_starved_to_death(philo);
	if (philo->param->abort_simulator == TRUE)
		return (pthread_mutex_unlock(&(philo->param->mutex_sleeping)), FALSE);
	philo->status = SLEEPING;
	display_current_status(philo);
	forced_waiting(philo->param, philo->param->time_to_sleep);
	return (pthread_mutex_unlock(&(philo->param->mutex_sleeping)), TRUE);
}
