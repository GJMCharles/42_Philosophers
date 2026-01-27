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

int	destroy_mutex(pthread_mutex_t *mutex)
{
	return (pthread_mutex_destroy(mutex) == 0);
}

int	init_mutex(pthread_mutex_t *mutex)
{
	return (pthread_mutex_init(mutex, NULL) == 0);
}

void	end_pthreads(t_data **data)
{
	t_param	*temp;
	t_philo	*philo_first;
	t_philo	*philo_list;

	temp = (*data)->param;
	(void) destroy_mutex(&temp->mutex_start);
	(void) destroy_mutex(&temp->mutex_timestamp);
	(void) destroy_mutex(&temp->mutex_print);
	(void) destroy_mutex(&temp->mutex_eating);
	(void) destroy_mutex(&temp->mutex_sleeping);
	(void) destroy_mutex(&temp->mutex_thinking);
	(void) destroy_mutex(&temp->mutex_dead);
	philo_first = (*data)->philo;
	philo_list = (*data)->philo;
	while (philo_list != (t_philo *) NULL)
	{
		(void) destroy_mutex(&philo_list->fork);
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
	(void) init_mutex(&temp->mutex_start);
	(void) init_mutex(&temp->mutex_timestamp);
	(void) init_mutex(&temp->mutex_print);
	(void) init_mutex(&temp->mutex_eating);
	(void) init_mutex(&temp->mutex_sleeping);
	(void) init_mutex(&temp->mutex_thinking);
	(void) init_mutex(&temp->mutex_dead);
	philo_first = (*data)->philo;
	philo_list = (*data)->philo;
	while (philo_list != (t_philo *) NULL)
	{
		(void) init_mutex(&philo_list->fork);
		philo_list = philo_list->next;
		if (philo_list == philo_first)
			break ;
	}
}
