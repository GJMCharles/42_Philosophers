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

void	everyone_should_be_satiated(t_ph *philo)
{
	t_pm	*params;

	params = philo->params;

	if (params->eating_limit > 0
		&& (philo->eat_counter == (t_ui) params->eating_limit))
	{
		params->reached_eating_limit += 1;
		if (params->reached_eating_limit == params->total)
			set_abort_simulation(params, true);
	}
}

bool	should_abort(t_ph *philo)
{
	t_pm	*params;

	params = philo->params;
	if (get_delay_from_last_meal(philo) >= (t_uli) params->time_to_die)
	{
		philo->is_dead = true;
		set_abort_simulation(params, true);
	}
	return (get_abort_simulation(params));
}

/**
 * 
 */
void	*simulation(void *arg)
{
	t_ph	*philo;
	t_pm	*params;

	philo = (t_ph *) arg;
	params = philo->params;
	start_timestamp(params, philo);
	while (1)
	{
		if (!action_eating(philo))
			break ;
		if (!action_sleeping(philo))
			break ;
		if (!action_thinking(philo))
			break ;
	}
	if (philo->is_dead == true)
		action_dying(philo);
	return (NULL);
}

/**
 * 
 */
void	start_simulation(t_data *data)
{
	t_ph	*ph;
	t_pm	*params;
	t_ui	index;

	ph = data->philos;
	params = data->params;
	index = 0;
	while (index++ < params->total)
	{
		if (((index - 1) % 2) == 0)
			pthread_create(
				&ph[index - 1].thread, NULL, simulation, &ph[index - 1]);
	}
	index = 0;
	while (index++ < params->total)
	{
		if (((index - 1) % 2) != 0)
			pthread_create(
				&ph[index - 1].thread, NULL, simulation, &ph[index - 1]);
	}
	index = 0;
	while (index++ < params->total)
		pthread_join(ph[index - 1].thread, (void **) NULL);
}
