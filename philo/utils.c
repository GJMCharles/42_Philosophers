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
	t_param		*param;
	t_philo		*philo;

	if (!data)
		return ;
	param = data->param;
	if (param)
		free(param);
	philo = data->philo;
	if (philo)
		clear_philosophers(&philo);
}
