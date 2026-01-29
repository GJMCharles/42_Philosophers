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
	if (philo->param->abort_simulator)
		return (pthread_mutex_unlock(&(philo->param->mutex_sleeping)), FALSE);
	usleep(philo->param->time_to_sleep * 1000);
	philo->status = SLEEPING;
	display_current_status(philo);
	return (pthread_mutex_unlock(&(philo->param->mutex_sleeping)), TRUE);
}
