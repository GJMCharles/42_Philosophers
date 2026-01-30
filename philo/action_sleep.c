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

int	action_sleep(t_philo *philo, t_param *param)
{
	pthread_mutex_lock(&param->mutex_sleeping);
	param->abort_simulator = should_abort_simulator(philo, param);
	if (param->abort_simulator == TRUE)
		return (pthread_mutex_unlock(&param->mutex_sleeping), FALSE);
	philo->status = SLEEPING;
	display_message(philo, (char *) NULL);
	pthread_mutex_unlock(&param->mutex_sleeping);
	forced_waiting(param, param->time_to_sleep);
	return (TRUE);
}
