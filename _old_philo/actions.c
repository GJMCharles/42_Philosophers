/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grcharle <grcharle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/12 00:17:47 by grcharle          #+#    #+#             */
/*   Updated: 2025/12/12 00:17:52 by grcharle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include <stdio.h>

static void	*philosopher_actions(void *arg)
{
	t_philos		*philo;
	unsigned int	index;

	philo = (t_philos *) arg;
	index = 0;
	while (1)
	{
		index += 1;
		// printf("%u ~ %u\n", index, philo->params->nbr_philos);
		pthread_join(philo->thread, NULL);
		if (index == philo->params->nbr_philos)
			break ;
	}
	pthread_join(philo->thread, NULL);
	return (NULL);
}

unsigned long int	get_elapsed_time(void)
{
	struct timeval	current_time;

	gettimeofday(&current_time, NULL);
	return (current_time.tv_sec * 1000 + current_time.tv_usec / 1000);
}

int			initialise_thread(t_data *data)
{
	unsigned int		index;
	t_params			*params;
	t_philos			*philos;
	unsigned long int	start_time;

	index = 0;
	params = data->params;
	philos = data->philos;
	start_time = get_elapsed_time();
	while (index < params->nbr_philos)
	{
		philos[index].time_start = start_time;
		philos[index].timestamp = start_time;
		if (!pthread_create(
			&(philos[index].thread), NULL,
			&philosopher_actions, &(philos[index]))
		)
			return (0);
		index += 1;
	}
	return (1);
}