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

void	*simulation(void *arg)
{
	t_ph	*philos;
	t_pm	*params;

	philos = (t_ph *) arg;
	params = philos->params;
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
			pthread_create(&ph[index - 1].thread, NULL, simulation, &ph[index - 1]);
	}
	index = 0;
	while (index++ < params->total)
	{
		if (((index - 1) % 2) == 0)
			pthread_create(&ph[index - 1].thread, NULL, simulation, &ph[index - 1]);
	}
	index = 0;
	while (index++ < params->total)
		pthread_join(ph[index - 1].thread, (void **) NULL);
}
