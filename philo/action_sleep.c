/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   action_sleep.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grcharle <grcharle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/14 06:53:05 by grcharle          #+#    #+#             */
/*   Updated: 2026/01/14 06:53:15 by grcharle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	action_sleep(t_philo *philo, t_param *param)
{
	philo->state = SLEEPING;
	display_message(philo, (char *) NULL);
	forced_waiting(param, param->time_to_sleep);
	return (TRUE);
}
