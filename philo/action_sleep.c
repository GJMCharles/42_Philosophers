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

int	sleeping_process(t_philo *philo, t_param *param)
{
	(void) param;
	philo->status = SLEEPING;
	display_message(philo, (char *) NULL);
	return (TRUE);
}

int	action_sleep(t_philo *philo, t_param *param)
{
	int	status;

	status = exec_pthread_mutex(\
		param->mutex_sleeping, philo, param, sleeping_process);
	forced_waiting(param, param->time_to_sleep);
	return (status);
}
