/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   action.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grcharle </var/spool/mail/grcharle>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/14 06:37:38 by grcharle          #+#    #+#             */
/*   Updated: 2026/01/14 06:37:55 by grcharle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*activities(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	while (1)
	{
		action_eat(philo);
		action_think(philo);
		action_sleep(philo);
		break ;
	}
	return ((void *) NULL);
}

void	philosophers_activities(t_data **data)
{
	t_data	*temp;
	t_philo	*philo_first;
	t_philo	*philo;

	temp = *data;
	philo_first = temp->philo;
	philo = temp->philo;
	while (philo != (t_philo *) NULL)
	{
		pthread_create(&philo->thread, NULL, &activities, (void *) philo);
		philo = philo->next;
		if (philo == philo_first)
			break ;
	}
	philo = temp->philo;
	while (philo != (t_philo *) NULL)
	{
		pthread_join(philo->thread, (void **) NULL);
		philo = philo->next;
		if (philo == philo_first)
			break ;
	}
}
