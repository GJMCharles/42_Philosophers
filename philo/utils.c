/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grcharle </var/spool/mail/grcharle>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/30 13:42:39 by grcharle          #+#    #+#             */
/*   Updated: 2026/01/08 05:26:46 by grcharle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	free_all(t_data *data)
{
	t_params		*params;
	t_philos		*philos;
	unsigned int	index;

	if (!data)
		return ;
	params = data->params;
	philos = data->philos;
	index = 0;
	while (index < params->nbr_philos)
	{
		// if (!pthread_join(philos[index].thread, NULL))
		// {
		// 	//
		// }
		index += 1;
	}
	if (params)
		free(params);
	if (philos)
		free(philos);
}
