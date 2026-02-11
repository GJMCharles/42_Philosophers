/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simulation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grcharle <grcharle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/10 14:01:21 by grcharle          #+#    #+#             */
/*   Updated: 2026/02/10 14:02:21 by grcharle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	start_timestamp(t_pm *params, t_ph *philos)
{
	(void) pthread_mutex_lock(&params->mutex_start);
	if (params->time_of_start == 0)
		params->time_of_start = get_current_timestamp();
	philos->last_eaten = params->time_of_start;
	(void) pthread_mutex_unlock(&params->mutex_start);
}

void	*simulation(void *arg)
{
	t_ph	*philos;
	t_pm	*params;

	philos = (t_ph *) arg;
	params = philos->params;
	start_timestamp(params, philos);
	while (1)
	{
		if (action_eating(philos) == false)
			break ;
		if (action_sleeping(philos) == false)
			break ;
		if (action_thinking(philos) == false)
			break ;
		break ;
	}
	if (philos->is_dead == true)
		action_dying(philos);
	return (NULL);
}

void	start_simulation(t_data *data)
{
	t_ph	*ph;
	t_pm	*params;
	ui		index;

	ph = data->philos;
	params = data->params;
	index = 0;
	while (index++ < params->total)
	{
		if (((index - 1) % 2) != 0)
			pthread_create(
				&ph[index - 1].thread, NULL, simulation, &ph[index - 1]);
	}
	index = 0;
	while (index++ < params->total)
	{
		if (((index - 1) % 2) == 0)
			pthread_create(
				&ph[index - 1].thread, NULL, simulation, &ph[index - 1]);
	}
	index = 0;
	while (index++ < params->total)
		pthread_join(ph[index - 1].thread, (void **) NULL);
}
