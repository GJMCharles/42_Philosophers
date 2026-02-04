/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threads.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grcharle <grcharle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/14 06:09:09 by grcharle          #+#    #+#             */
/*   Updated: 2026/02/03 19:21:43 by grcharle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

// int	exec_pthread_mutex(pthread_mutex_t *mutex, t_philo *philo, t_param *param, int (*f)(t_philo *, t_param *))
// {
// 	int	status;
// 	pthread_mutex_lock(mutex);
// 	//param->abort_simulator = should_abort_simulator(philo, param);
// 	//if (param->abort_simulator == TRUE)
// 	//	return (pthread_mutex_unlock(&mutex), FALSE);
// 	status = (*f)(philo, param);
// 	return (pthread_mutex_unlock(mutex), status);
// }

void	destroy_forks_pthreads(t_data **data, unsigned int index)
{
	t_param	*param;

	param = (*data)->param;
	if (index == 0)
		index = (param->nb_philos - 1);
	while (index)
	{
		(void) pthread_mutex_destroy(&param->forks[index]);
		index -= 1;
	}
}

void	destroy_param_pthreads(t_data **data, unsigned int code)
{
	t_param		*param;

	param = (*data)->param;
	if (code == 0)
		code = 7;
	if (code >= 7)
		(void) pthread_mutex_destroy(&param->mutex_dead);
	if (code >= 6)
		(void) pthread_mutex_destroy(&param->mutex_print);
	if (code >= 5)
		(void) pthread_mutex_destroy(&param->mutex_timestamp);
	if (code >= 4)
		(void) pthread_mutex_destroy(&param->mutex_eating);
	if (code >= 3)
		(void) pthread_mutex_destroy(&param->mutex_sleeping);
	if (code >= 2)
		(void) pthread_mutex_destroy(&param->mutex_thinking);
	if (code >= 1)
		(void) pthread_mutex_destroy(&param->mutex_start);
}

int	init_pthreads(t_data **data)
{
	t_param			*param;
	unsigned int	index;

	param = (*data)->param;
	if (pthread_mutex_init(&param->mutex_start, NULL) != 0)
		return (destroy_param_pthreads(data, 1), FALSE);
	if (pthread_mutex_init(&param->mutex_thinking, NULL) != 0)
		return (destroy_param_pthreads(data, 2), FALSE);
	if (pthread_mutex_init(&param->mutex_sleeping, NULL) != 0)
		return (destroy_param_pthreads(data, 3), FALSE);
	if (pthread_mutex_init(&param->mutex_eating, NULL) != 0)
		return (destroy_param_pthreads(data, 4), FALSE);
	if (pthread_mutex_init(&param->mutex_timestamp, NULL) != 0)
		return (destroy_param_pthreads(data, 5), FALSE);
	if (pthread_mutex_init(&param->mutex_print, NULL) != 0)
		return (destroy_param_pthreads(data, 6), FALSE);
	if (pthread_mutex_init(&param->mutex_dead, NULL) != 0)
		return (destroy_param_pthreads(data, 7), FALSE);
	index = 0;
	while (index < param->nb_philos)
	{
		if (pthread_mutex_init(&param->forks[index], NULL) != 0)
			return (destroy_forks_pthreads(data, index), FALSE);
		index += 1;
	}
	return (TRUE);
}
