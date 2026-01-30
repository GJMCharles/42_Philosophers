/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   action_think.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grcharle <grcharle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/14 06:53:21 by grcharle          #+#    #+#             */
/*   Updated: 2026/01/14 06:53:42 by grcharle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	thinking_process(t_philo *philo, t_param *param)
{
	(void) param;
	philo->status = THINKING;
	display_message(philo, (char *) NULL);
	return (TRUE);
}

int	action_think(t_philo *philo, t_param *param)
{
	int	status;

	status = exec_pthread_mutex(\
		param->mutex_thinking, philo, param, thinking_process);
	return (status);
}
