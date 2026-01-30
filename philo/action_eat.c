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

int	eating_process(t_philo *philo, t_param *param)
{
	(void) param;
	philo->status = EATING;
	display_message(philo, (char *) NULL);
	philo->eating_counter += 1;
	return (TRUE);
}

int	pick_right_fork(t_philo *philo, t_param *param)
{
	int	status;

	display_message(philo, (char *) NULL);
	status = exec_pthread_mutex(philo->fork, philo, param, eating_process);
	return (status);
}

int	pick_left_fork(t_philo *philo, t_param *param)
{
	int	status;

	philo->status = FORK;
	display_message(philo, (char *) NULL);
	if (!(philo->next))
	{
		philo->status = DEAD;
		param->abort_simulator = TRUE;
		return (FALSE);
	}
	status = exec_pthread_mutex(
			philo->next->fork, philo, param, pick_right_fork);
	return (status);
}

int	action_eat(t_philo *philo, t_param *param)
{
	int	status;

	status = exec_pthread_mutex(philo->fork, philo, param, pick_left_fork);
	if (status)
	{
		pthread_mutex_lock(&param->mutex_wait);
		forced_waiting(param, param->time_to_eat);
		philo->last_eaten = get_timestamp_ms();
		pthread_mutex_unlock(&param->mutex_wait);
	}
	return (status);
}
