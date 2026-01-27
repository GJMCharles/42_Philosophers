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

int	start_eating(t_philo *philo)
{
	if (philo->param->abort_simulation)
		return (FALSE);
	philo->status = EATING;
	display_current_state(philo);
	usleep(philo->param->time_to_eat * 1000);
	return (TRUE);
}

int	pick_right_fork(t_philo *philo)
{
	if (philo->param->abort_simulation)
		return (FALSE);
	philo->status = FORK;
	display_current_state(philo);
	exec_mutex(&(philo->param->mutex_eating), philo, start_eating);
	return (TRUE);
}

int	pick_left_fork(t_philo *philo)
{
	if (philo->param->abort_simulation)
		return (FALSE);
	philo->status = FORK;
	display_current_state(philo);
	if (!philo->next)
	{
		usleep(philo->param->time_to_die * 1000);
		philo->status = DEAD;
		philo->param->abort_simulation = TRUE;
		return (FALSE);
	}
	return (exec_mutex(&(philo->next->fork), philo, pick_right_fork));
}

int action_eat(t_philo *philo)
{
	if (philo->param->abort_simulation)
		return (FALSE);
	return exec_mutex(&(philo->fork), philo, pick_left_fork);
}

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

// int	eat_callback(t_philo *philo)
// {
// 	philo->last_eaten = get_timestamp_ms();
// 	philo->eating_counter += 1;
// 	return (1);
// }

// void	action_eat(t_philo *philo)
// {
// 	pthread_mutex_t	left_fork;
// 	pthread_mutex_t	right_fork;

// 	left_fork = philo->fork;
// 	pthread_mutex_lock(&left_fork);
// 	philo->status = PICK_FORK;
// 	print_status(philo);
// 	if (!philo->next)
// 	{
// 		forced_waiting(philo->param->time_to_die);
// 		pthread_mutex_unlock(&left_fork);
// 		return ;
// 	}
// 	right_fork = philo->next->fork;
// 	pthread_mutex_lock(&right_fork);
// 	print_status(philo);
// 	philo->status = EATING;
// 	print_status(philo);
// 	forced_waiting(philo->param->time_to_eat);
// 	exec_mutex(&philo->param->mutex_eating, philo, eat_callback);
// 	pthread_mutex_unlock(&right_fork);
// 	pthread_mutex_unlock(&left_fork);
// }
