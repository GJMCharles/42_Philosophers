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

int	take_forks(pthread_mutex_t *left, pthread_mutex_t *right)
{
	if (left != (pthread_mutex_t *) NULL)
		pthread_mutex_lock(left);
	if (right != (pthread_mutex_t *) NULL)
		pthread_mutex_lock(right);
	return (1);
}

int	return_forks(pthread_mutex_t *left, pthread_mutex_t *right)
{
	if (left != (pthread_mutex_t *) NULL)
		pthread_mutex_unlock(left);
	if (right != (pthread_mutex_t *) NULL)
		pthread_mutex_unlock(right);
	return (1);
}

void	action_eat(t_philo *philo)
{
	pthread_mutex_t	*left_fork;
	pthread_mutex_t	*right_fork;

	left_fork = &philo->fork;
	if (philo->next)
		right_fork = &philo->next->fork;
	else
		right_fork = (pthread_mutex_t *) NULL;
	take_forks(left_fork, right_fork);
	
	usleep(philo->param->time_to_eat * 1000);
	return_forks(left_fork, right_fork);
}

/*
get_timestamp_ms() - philo->param->start_time
*/
