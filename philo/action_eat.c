/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   action_eat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grcharle </var/spool/mail/grcharle>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/14 06:52:37 by grcharle          #+#    #+#             */
/*   Updated: 2026/01/14 06:52:51 by grcharle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	action_eat(t_philo *philo)
{
	(void) philo;
	// pthread_mutex_t	*right_fork;
	// right_fork = (pthread_mutex_t *) NULL;
	// if (philo->next)
	// 	right_fork = &philo->next->fork;
	// pthread_mutex_lock(&philo->fork);
	// philo->status = FORK_UP;
	// report_message(philo);
	// if (!right_fork)
	// 	return (
	// 		usleep(philo->param->time_to_die * 1000), 
	// 		pthread_mutex_unlock(&philo->fork), 0);
	// pthread_mutex_lock(right_fork);
	// report_message(philo);
	// pthread_mutex_lock(&philo->param->mutex_eating);
	// philo->status = EATING;
	// report_message(philo);
	// philo->eat_counter += 1;
	// usleep(philo->param->time_to_eat * 1000);	
	// philo->timestamp_last_meal = get_timestamp_ms();
	// pthread_mutex_unlock(&philo->param->mutex_eating);
	// pthread_mutex_unlock(right_fork);
	// pthread_mutex_unlock(&philo->fork);
	// return (1);
}
