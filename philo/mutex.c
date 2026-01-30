/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mutex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grcharle <grcharle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/14 06:09:09 by grcharle          #+#    #+#             */
/*   Updated: 2026/01/14 06:09:57 by grcharle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	end_pthreads(t_data **data)
{
	t_param	*temp;
	t_philo	*philo_first;
	t_philo	*philo_list;

	temp = (*data)->param;
	(void)pthread_mutex_destroy(&temp->mutex_start);
	(void)pthread_mutex_destroy(&temp->mutex_wait);
	(void)pthread_mutex_destroy(&temp->mutex_timestamp);
	(void)pthread_mutex_destroy(&temp->mutex_print);
	(void)pthread_mutex_destroy(&temp->mutex_eating);
	(void)pthread_mutex_destroy(&temp->mutex_sleeping);
	(void)pthread_mutex_destroy(&temp->mutex_thinking);
	(void)pthread_mutex_destroy(&temp->mutex_dead);
	philo_first = (*data)->philo;
	philo_list = (*data)->philo;
	while (philo_list != (t_philo *) NULL)
	{
		(void)pthread_mutex_destroy(&philo_list->fork);
		philo_list = philo_list->next;
		if (philo_list == philo_first)
			break ;
	}
}

void	start_pthreads(t_data **data)
{
	t_param	*temp;
	t_philo	*philo_first;
	t_philo	*philo_list;

	temp = (*data)->param;
	(void)pthread_mutex_init(&temp->mutex_start, NULL);
	(void)pthread_mutex_init(&temp->mutex_wait, NULL);
	(void)pthread_mutex_init(&temp->mutex_timestamp, NULL);
	(void)pthread_mutex_init(&temp->mutex_print, NULL);
	(void)pthread_mutex_init(&temp->mutex_eating, NULL);
	(void)pthread_mutex_init(&temp->mutex_sleeping, NULL);
	(void)pthread_mutex_init(&temp->mutex_thinking, NULL);
	(void)pthread_mutex_init(&temp->mutex_dead, NULL);
	philo_first = (*data)->philo;
	philo_list = (*data)->philo;
	while (philo_list != (t_philo *) NULL)
	{
		(void)pthread_mutex_init(&philo_list->fork, NULL);
		philo_list = philo_list->next;
		if (philo_list == philo_first)
			break ;
	}
}
