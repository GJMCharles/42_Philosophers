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
	unsigned int	handle_count;
	pthread_mutex_t	*left_fork;
	pthread_mutex_t	*right_fork;

	left_fork = &philo->fork;

	pthread_mutex_lock(left_fork);
	handle_count = 0;
	right_fork = (pthread_mutex_t *) NULL;

	if (philo->next != (t_philo *) NULL)
		right_fork = &philo->next->fork;		
	handle_count += 1;
	if (right_fork != (pthread_mutex_t *) NULL)
	{
		pthread_mutex_lock(right_fork);
		handle_count += 1;
		pthread_mutex_unlock(right_fork);
	}
	usleep(philo->param->time_to_eat);
	pthread_mutex_unlock(left_fork);
}

/*
get_timestamp_ms() - philo->param->start_time
*/
