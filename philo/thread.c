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
	t_philo		*first;
	t_philo		*philo;

	first = (t_philo *) NULL;
	philo = data->philo;
	while (philo != (t_philo *) NULL && philo != first)
	{
		if (!first)
			first = philo;
		if (pthread_join(philo->thread, NULL) != 0)
			return (0);
		philo = philo->next;
	}
	return (1);
}

int			create_threads(t_data *data)
{
	t_philo		*first;
	t_philo		*philo;

	first = (t_philo *) NULL;
	philo = data->philo;
	while (philo != (t_philo *) NULL && philo != first)
	{
		if (!first)
			first = philo;
		if (pthread_create(&(philo->thread), NULL, \
			philosopher_actions, (void *) philo) != 0)
		{
			while (philo != first)
			{
				pthread_join(philo->thread, NULL);
				philo = philo->prev;
			}
			pthread_join(philo->thread, NULL);
			return (0);
		}
		usleep(100);
		philo = philo->next;
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
