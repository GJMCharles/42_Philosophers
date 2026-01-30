/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   action_think.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grcharle <grcharle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/14 06:53:21 by grcharle          #+#    #+#             */
/*   Updated: 2026/01/14 06:53:42 by grcharle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	action_think(t_philo *philo, t_param *param)
{
	pthread_mutex_lock(&param->mutex_thinking);
	param->abort_simulator = should_abort_simulator(philo, param);
	if (param->abort_simulator == TRUE)
		return (pthread_mutex_unlock(&param->mutex_thinking), FALSE);
	philo->status = THINKING;
	display_current_status(philo);
	return (pthread_mutex_unlock(&param->mutex_thinking), TRUE);
}
