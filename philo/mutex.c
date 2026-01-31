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

int	exec_pthread_mutex(pthread_mutex_t *mutex, t_philo *philo, t_param *param, int (*f)(t_philo *, t_param *))
{
	int	status;
	pthread_mutex_lock(mutex);
	//param->abort_simulator = should_abort_simulator(philo, param);
	//if (param->abort_simulator == TRUE)
	//	return (pthread_mutex_unlock(&mutex), FALSE);
	status = (*f)(philo, param);
	return (pthread_mutex_unlock(mutex), status);
}

void	destroy_pthreads_mutex(t_data **data)
{
	t_param			*param;
	unsigned int	index;

	param = (*data)->param;
	(void) pthread_mutex_destroy(&param->mutex_start);
	(void) pthread_mutex_destroy(&param->mutex_wait);
	(void) pthread_mutex_destroy(&param->mutex_print);
	(void) pthread_mutex_destroy(&param->mutex_dead);
	index = 0;
	while (index < param->nb_philos)
	{
		(void) pthread_mutex_destroy(&param->forks[index]);
		index += 1;
	}
}

void	init_pthreads_mutex(t_data **data)
{
t_param			*param;
	unsigned int	index;

	param = (*data)->param;
	(void) pthread_mutex_init(&param->mutex_start, NULL);
	(void) pthread_mutex_init(&param->mutex_wait, NULL);
	(void) pthread_mutex_init(&param->mutex_print, NULL);
	(void) pthread_mutex_init(&param->mutex_dead, NULL);
	index = 0;
	while (index < param->nb_philos)
	{
		(void) pthread_mutex_init(&param->forks[index], NULL);
		index += 1;
	}
}
