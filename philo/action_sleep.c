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

void	sleep_callback(t_philo *philo)
{
	philo->status = SLEEPING;
	print_status(philo);
	forced_waiting(philo->param->time_to_sleep);
}

void	action_sleep(t_philo *philo)
{
	exec_mutex(&(philo->param->mutex_sleeping), philo, sleep_callback);
}
