/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   abort.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grcharle <grcharle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/21 16:22:13 by grcharle          #+#    #+#             */
/*   Updated: 2026/02/21 16:22:38 by grcharle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

/**
 * bool	get_abort_simulation(t_params *params);
 */
bool	get_abort_simulation(t_params *params)
{
	bool	value;

	pthread_mutex_lock(&params->mutex_abort);
	value = params->can_abort_simulation;
	pthread_mutex_unlock(&params->mutex_abort);
	return (value);
}

/**
 * void	set_abort_simulation(t_params *params, bool value);
 */
void	set_abort_simulation(t_params *params, bool value)
{
	pthread_mutex_lock(&params->mutex_abort);
	params->can_abort_simulation = value;
	pthread_mutex_unlock(&params->mutex_abort);
}
