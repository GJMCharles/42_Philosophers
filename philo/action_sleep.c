/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   action_sleep.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grcharle </var/spool/mail/grcharle>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/14 06:53:05 by grcharle          #+#    #+#             */
/*   Updated: 2026/01/14 06:53:15 by grcharle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	action_sleep(t_philo *philo)
{
	pthread_mutex_lock(&philo->param->mutex_sleeping);
	philo->status = SLEEPING;
	// report_message(philo);
	usleep(philo->param->time_to_sleep * 1000);
	pthread_mutex_unlock(&philo->param->mutex_sleeping);
}
