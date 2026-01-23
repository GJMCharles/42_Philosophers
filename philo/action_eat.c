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

// int		fn_mutex(pthread_mutex_t *mutex, void (*fn)(void *))
// {
// 	pthread_mutex_lock(mutex);
// 	(*fn);
// 	pthread_mutex_unlock(mutex);
// 	return (1);
// }

// void	post_eating(t_philo *philo)
// {
// 	philo->last_eaten = get_timestamp_ms();
// 	philo->eating_counter += 1;
// }

// void	pick_fork(t_philo *philo)
// {
// 	if (!philo)
// 		return ;
// 	print_status(philo);
// }

void	post_meal(t_philo *philo)
{
	philo->last_eaten = get_timestamp_ms();
	philo->eating_counter += 1;
}

void	action_eat(t_philo *philo)
{
	pthread_mutex_t	left_fork;
	pthread_mutex_t	right_fork;

	left_fork = philo->fork;
	pthread_mutex_lock(&left_fork);
	philo->status = PICK_FORK;
	print_status(philo);
	if (!philo->next)
	{
		forced_waiting(philo->param->time_to_die);
		pthread_mutex_unlock(&left_fork);
		return ;
	}
	right_fork = philo->next->fork;
	pthread_mutex_lock(&right_fork);
	print_status(philo);
	philo->status = EATING;
	print_status(philo);
	forced_waiting(philo->param->time_to_eat);
	exec_mutex(&philo->param->mutex_eating, philo, post_meal);
	pthread_mutex_unlock(&right_fork);
	pthread_mutex_unlock(&left_fork);
}
