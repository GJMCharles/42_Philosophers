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

// int	exec_mutex(void *mutex, t_philo *p, int (*fn)(t_philo *))
// {
// 	pthread_mutex_t	*m;
// 	int				status;

// 	m = (pthread_mutex_t *) mutex;
// 	pthread_mutex_lock(m);
// 	status = (*fn)(p);
// 	pthread_mutex_unlock(m);
// 	return (status);
// }

void	init_pthread_mutex(t_data **data)
{
	t_param	*temp;
	t_philo	*philo_first;
	t_philo	*philo_list;

	temp = (*data)->param;
	pthread_mutex_init(&temp->mutex_start, NULL);
	pthread_mutex_init(&temp->mutex_timestamp, NULL);
	pthread_mutex_init(&temp->mutex_print, NULL);
	pthread_mutex_init(&temp->mutex_eating, NULL);
	pthread_mutex_init(&temp->mutex_sleeping, NULL);
	pthread_mutex_init(&temp->mutex_thinking, NULL);
	pthread_mutex_init(&temp->mutex_dead, NULL);
	philo_first = (*data)->philo;
	philo_list = (*data)->philo;
	while (philo_list != (t_philo *) NULL)
	{
		pthread_mutex_init(&philo_list->fork, NULL);
		philo_list = philo_list->next;
		if (philo_list == philo_first)
			break ;
	}
}

void	destroy_pthread_mutex(t_data **data)
{
	t_param	*temp;
	t_philo	*philo_first;
	t_philo	*philo_list;

	temp = (*data)->param;
	pthread_mutex_destroy(&temp->mutex_start);
	pthread_mutex_destroy(&temp->mutex_timestamp);
	pthread_mutex_destroy(&temp->mutex_print);
	pthread_mutex_destroy(&temp->mutex_eating);
	pthread_mutex_destroy(&temp->mutex_sleeping);
	pthread_mutex_destroy(&temp->mutex_thinking);
	pthread_mutex_destroy(&temp->mutex_dead);
	philo_first = (*data)->philo;
	philo_list = (*data)->philo;
	while (philo_list != (t_philo *) NULL)
	{
		pthread_mutex_destroy(&philo_list->fork);
		philo_list = philo_list->next;
		if (philo_list == philo_first)
			break ;
	}
}