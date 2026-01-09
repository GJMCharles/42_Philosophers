/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grcharle <grcharle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/08 08:57:32 by grcharle          #+#    #+#             */
/*   Updated: 2026/01/08 08:57:34 by grcharle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int			join_threads(t_data *data)
{
	t_philo			*philo;
	unsigned int	index;
	unsigned int	limit;

	philo = data->philo;
	index = 0;
	limit = data->param->nb_philos;
	while (index < limit)
	{
		pthread_join(philo->thread, NULL);
		philo = philo->next;
		index += 1;
	}
	return (1);
}

int			create_threads(t_data *data)
{
	t_philo			*philo;
	unsigned int	index;
	unsigned int	limit;

	philo = data->philo;
	index = 0;
	limit = data->param->nb_philos;
	while (index < limit)
	{
		if (pthread_create(&(philo->thread), NULL, \
			philosopher_actions, (void *) philo) != 0)
		{
			philo = philo->prev;
			while (--index)
			{
				pthread_join(philo->thread, NULL);
				philo = philo->prev;
			}
			return (0);
		}
		usleep(100);
		philo = philo->next;
		index += 1;
	}
	return (1);
}

int			manage_threads(t_data *data)
{
	if (!create_threads(data))
		return (0);
	if (!join_threads(data))
		return (0);
	return (1);
}
