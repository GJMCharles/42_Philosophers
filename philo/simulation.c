/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simulation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grcharle <grcharle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/14 06:37:38 by grcharle          #+#    #+#             */
/*   Updated: 2026/01/15 08:59:37 by grcharle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void set_timestamp(t_param *param)
{
	pthread_mutex_lock(&(param->mutex_start));
	if (param->start_timestamp == 0)
		param->start_timestamp = get_timestamp_ms();
	pthread_mutex_unlock(&(param->mutex_start));
}

void *simulator(void *arg)
{
	t_philo *philo;
	t_param *param;

	philo = (t_philo *)arg;
	param = philo->param;
	set_timestamp(param);
	while (1)
	{
		if (param->abort_simulator == TRUE || action_eat(philo) == FALSE)
			break;
		// if (param->abort_simulator == TRUE || action_sleep(philo) == FALSE)
		//	break;
		// if (param->abort_simulator == TRUE || action_think(philo) == FALSE)
		//	break;
		break;
	}
	if (philo->status == DEAD)
		action_die(philo);
	return ((void *)NULL);
}

void start_simulators(t_data **data)
{
	t_philo *current;
	t_philo *first;

	current = (*data)->philo;
	first = current;
	while (current != (t_philo *)NULL)
	{
		pthread_create(&(current->thread), NULL, &simulator, (void *)current);
		pthread_join(current->thread, (void *)NULL);
		current = current->next;
		if (current == first)
			break;
	}
}
