/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mutex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grcharle <grcharle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/09 06:04:36 by grcharle          #+#    #+#             */
/*   Updated: 2026/01/09 06:04:46 by grcharle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

// void	start_mutex(t_data *data)
// {
// 	long int	timestamp;

// 	pthread_mutex_lock(&(data->start_mutex));
// 	timestamp = get_elapsed_time();
// 	if (timestamp == -1)
// 	{
// 		pthread_mutex_unlock(&(data->start_mutex));
// 		return ;
// 	}
// 	data->starting_time = (unsigned long int) timestamp;	
// }

// int		initialise_mutex(t_data *data)
// {
// 	t_philo			*philo;
// 	unsigned int	index;
// 	unsigned int	limit;

// 	philo = data->philo;
// 	index = 0;
// 	limit = data->param->nb_philos;
// 	while (index < limit)
// 	{
// 		if (pthread_mutex_init(&(philo->fork), NULL) != 0)
// 		{
// 			philo = philo->prev;
// 			while (--index)
// 			{
// 				pthread_mutex_destroy(&(philo->fork));
// 				philo = philo->prev;
// 			}
// 			return (0);
// 		}
// 		philo = philo->next;
// 		index += 1;
// 	}
// 	return (1);
// }

