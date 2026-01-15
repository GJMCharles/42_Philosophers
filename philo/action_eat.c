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

int	action_eat(t_philo *philo)
{
	pthread_mutex_t	*left_fork;
	pthread_mutex_t	*right_fork;

	left_fork = &philo->fork;
	right_fork = (pthread_mutex_t *) NULL;
	if (philo->next)
		right_fork = &philo->next->fork;
	philo->status = FORK_UP;
	pthread_mutex_lock(left_fork);
	report_message(philo);
	if (!right_fork)
		return (pthread_mutex_unlock(left_fork), 0);
	pthread_mutex_lock(right_fork);
	report_message(philo);
	pthread_mutex_lock(&philo->param->mutex_eating);
	philo->status = EATING;
	usleep(philo->param->time_to_eat * 1000);
	philo->eat_counter += 1;
	report_message(philo);
	philo->time_last_meal = get_timestamp_ms();
	pthread_mutex_unlock(&philo->param->mutex_eating);
	pthread_mutex_unlock(right_fork);
	pthread_mutex_unlock(left_fork);
	return (1);
}
