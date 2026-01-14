/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mutex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grcharle </var/spool/mail/grcharle>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/14 06:09:09 by grcharle          #+#    #+#             */
/*   Updated: 2026/01/14 06:09:57 by grcharle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	init_thread_mutex(t_data **data)
{
	t_data	*temp;
	t_philo	*philo_first;
	t_philo	*philo_list;

	temp = *data;
	pthread_mutex_init(&temp->mutex_timer, NULL);
	pthread_mutex_init(&temp->mutex_printer, NULL);
	pthread_mutex_init(&temp->mutex_eating, NULL);
	pthread_mutex_init(&temp->mutex_sleeping, NULL);
	pthread_mutex_init(&temp->mutex_thinking, NULL);
	pthread_mutex_init(&temp->mutex_dead, NULL);
	philo_first = temp->philo;
	philo_list = temp->philo;
	while (philo_list != (t_philo *) NULL)
	{
		pthread_mutex_init(&philo_list->fork, NULL);
		philo_list = philo_list->next;
		if (philo_list == philo_first)
			break ;
	}
}

void	destroy_thread_mutex(t_data **data)
{
	t_data	*temp;
	t_philo	*philo_first;
	t_philo	*philo_list;

	temp = *data;
	pthread_mutex_destroy(&temp->mutex_timer);
	pthread_mutex_destroy(&temp->mutex_printer);
	pthread_mutex_destroy(&temp->mutex_eating);
	pthread_mutex_destroy(&temp->mutex_sleeping);
	pthread_mutex_destroy(&temp->mutex_thinking);
	pthread_mutex_destroy(&temp->mutex_dead);
	philo_first = temp->philo;
	philo_list = temp->philo;
	while (philo_list != (t_philo *) NULL)
	{
		pthread_mutex_destroy(&philo_list->fork);
		philo_list = philo_list->next;
		if (philo_list == philo_first)
			break ;
	}
}
