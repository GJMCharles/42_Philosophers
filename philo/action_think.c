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

int action_think(t_philo *philo)
{
	pthread_mutex_lock(&(philo->param->mutex_thinking));
	if (philo->param->abort_simulator)
		return (pthread_mutex_unlock(&(philo->param->mutex_thinking)), FALSE);
	philo->status = THINKING;
	display_current_status(philo);
	return (pthread_mutex_unlock(&(philo->param->mutex_thinking)), TRUE);
}
