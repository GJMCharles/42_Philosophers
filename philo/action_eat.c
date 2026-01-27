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
