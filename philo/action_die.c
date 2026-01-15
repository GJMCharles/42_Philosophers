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

void	action_die(t_philo *philo)
{
	pthread_mutex_lock(&philo->param->mutex_dead);
	philo->status = DEAD;
	philo->param->death_encountered = 1;
	usleep(10 * 1000);
	// report_message(philo);
	pthread_mutex_unlock(&philo->param->mutex_dead);
}
