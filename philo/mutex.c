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

int		initialise_mutex(t_data *data)
{
	if (pthread_mutex_init(&(data->start_mutex), NULL) != 0)
		return (0);
	return (1);
}

int		destroy_mutex(t_data *data)
{
	(void) pthread_mutex_destroy(&(data->start_mutex));
	return (1);
}
