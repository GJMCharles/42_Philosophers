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

int	action_eat(t_philo *philo, t_param *param)
{
	unsigned int	index_left;
	unsigned int	index_right;

	index_left = philo->id;
	index_right = (philo->id + 1) % param->nb_philos;
	if (param->nb_philos == 1)
	{
		pthread_mutex_lock(&param->forks[index_left]);
		philo->state = FORK;
		display_message(philo, (char *) NULL);
		philo->state = DEAD;
		forced_waiting(param, param->time_to_die);
		return (pthread_mutex_unlock(&param->forks[index_left]), FALSE);
	}
	philo->state = FORK;
	pthread_mutex_lock(&param->forks[index_left]);
	pthread_mutex_lock(&param->forks[index_right]);
	display_message(philo, (char *) NULL);
	display_message(philo, (char *) NULL);
	philo->state = EATING;
	display_message(philo, (char *) NULL);
	forced_waiting(param, param->time_to_eat);
	philo->last_eaten = get_timestamp_ms();
	philo->eating_counter += 1;
	pthread_mutex_unlock(&param->forks[index_right]);
	pthread_mutex_unlock(&param->forks[index_left]);
	return (TRUE);
}
