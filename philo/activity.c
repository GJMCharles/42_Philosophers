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

void	*philosopher_routine(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	while (1)
	{
		eat_action(philo);
		think_action(philo);
		sleep_action(philo);
		break ;
	}
	return ((void *) NULL);
}

void	init_philosophers_activities(t_data **data)
{
	t_data	*temp;
	t_philo	*philo_first;
	t_philo	*philo_list;

	temp = *data;
	philo_first = temp->philo;
	philo_list = temp->philo;
	while (philo_list != (t_philo *) NULL)
	{
		pthread_create(&philo_list->thread, NULL,
			&philosopher_routine, (void *) philo_list);
		philo_list = philo_list->next;
		if (philo_list == philo_first)
			break ;
	}
}
