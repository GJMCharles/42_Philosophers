/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   action_die.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grcharle <grcharle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/15 05:40:28 by grcharle          #+#    #+#             */
/*   Updated: 2026/01/15 05:45:16 by grcharle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	action_die(t_philo *philo, t_param *param)
{
	pthread_mutex_lock(&param->mutex_dead);
	forced_waiting(param, 10);
	display_message(philo, (char *) NULL);
	pthread_mutex_unlock(&param->mutex_dead);
}
