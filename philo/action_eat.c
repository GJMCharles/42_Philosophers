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

int	everyone_is_fed(t_philo *philo)
{
	if (philo->param->eating_limits == -1)
		return (FALSE);
	return (FALSE);
}

int	has_starved_to_death(t_philo *philo)
{
	//unsigned long int ttd;

	if (philo->param->abort_simulator == TRUE)
		return (TRUE);
	//ttd = (unsigned long int) philo->param->time_to_die;
	//if (philo->last_eaten == 0 
	//	&& (get_timestamp_ms() - philo->param->start_timestamp) > ttd)
	//{
	//	philo->status = DEAD;
	//	return (TRUE);
	//}
	//if (philo->last_eaten != 0 
	//	&& (get_timestamp_ms() - philo->last_eaten) > ttd)
	//{
	//	philo->status = DEAD;
	//	return (TRUE);
	//}
	return (FALSE);
}

void start_eating(t_philo *philo)
{
	pthread_mutex_lock(&(philo->param->mutex_eating));
	philo->status = EATING;
	display_current_status(philo);
	forced_waiting(philo->param, philo->param->time_to_eat);
	philo->last_eaten = get_timestamp_ms();
	philo->eating_counter += 1;
	pthread_mutex_unlock(&(philo->param->mutex_eating));
 }

int action_eat(t_philo *philo)
{
	pthread_mutex_lock(&(philo->fork));
	//philo->param->abort_simulator = has_starved_to_death(philo);
	if (philo->param->abort_simulator == TRUE)
		return (pthread_mutex_unlock(&(philo->fork)), FALSE);
	philo->status = FORK;
	display_current_status(philo);
	if (philo->next == (t_philo *) NULL)
	{
		philo->status = DEAD;
		philo->param->abort_simulator = TRUE;
		forced_waiting(philo->param, philo->param->time_to_die);
		return (pthread_mutex_unlock(&(philo->fork)), FALSE);
	}
	pthread_mutex_lock(&(philo->next->fork));
	//philo->param->abort_simulator = has_starved_to_death(philo);
	if (philo->param->abort_simulator == TRUE)
		return (pthread_mutex_unlock(&(philo->next->fork)), FALSE);
	display_current_status(philo);
	start_eating(philo);
	philo->param->abort_simulator = everyone_is_fed(philo);
	pthread_mutex_unlock(&(philo->next->fork));
	pthread_mutex_unlock(&(philo->fork));
	return (TRUE);
}
