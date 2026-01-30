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

void	start_eating(t_philo *philo, t_param *param)
{
	pthread_mutex_lock(&param->mutex_eating);
	param->abort_simulator = should_abort_simulator(philo, param);
	if (param->abort_simulator == TRUE)
	{
		pthread_mutex_unlock(&param->mutex_eating);
		return ;
	}
	philo->status = EATING;
	display_current_status(philo);
	forced_waiting(param, param->time_to_eat);
	philo->eating_counter += 1;
	philo->last_eaten = get_timestamp_ms();
	pthread_mutex_unlock(&param->mutex_eating);
}

int	action_eat(t_philo *philo, t_param *param)
{
	if (!philo->next)
	{
		pthread_mutex_lock(&philo->fork);
		philo->status = FORK;
		display_current_status(philo);
		philo->status = DEAD;
		param->abort_simulator = TRUE;
		forced_waiting(param, param->time_to_die);
		return (pthread_mutex_unlock(&philo->fork), FALSE);
	}
	pthread_mutex_lock(&philo->fork);
	param->abort_simulator = should_abort_simulator(philo, param);
	if (param->abort_simulator == TRUE)
		return (pthread_mutex_unlock(&philo->fork), FALSE);
	philo->status = FORK;
	display_current_status(philo);
	pthread_mutex_lock(&philo->next->fork);
	display_current_status(philo);
	start_eating(philo, param);
	pthread_mutex_unlock(&philo->next->fork);
	pthread_mutex_unlock(&philo->fork);
	return (TRUE);
}
