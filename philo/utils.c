/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grcharle <grcharle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/08 08:53:02 by grcharle          #+#    #+#             */
/*   Updated: 2026/01/08 08:53:23 by grcharle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	free_all(t_data *data)
{
	t_param			*param;
	t_philo			*philo;
	t_philo			*next;
	unsigned int	index;

	if (!data)
		return ;
	param = data->param;
	philo = data->philo;
	index = 0;
	while (param && index < param->nb_philos)
	{
		next = philo->next;
		free(philo);
		philo = (t_philo *) NULL;
		philo = next;
		index += 1;
	}
	if (param)
		free(param);
}
