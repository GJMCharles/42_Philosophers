/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   action.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grcharle <grcharle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/09 05:40:10 by grcharle          #+#    #+#             */
/*   Updated: 2026/01/09 05:40:20 by grcharle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void		eating_action(t_philo *philo)
{
	printf("[user %u] is EATING\n", philo->id);
}

void		sleeping_action(t_philo *philo)
{
	printf("[user %u] is SLEEPING\n", philo->id);
}

void		thinking_action(t_philo *philo)
{
	printf("[user %u] is THINKING\n", philo->id);
}

void		*philosopher_actions(void *arg)
{
	t_philo		*philo;

	philo = (t_philo *) arg;
	while (1)
	{
		eating_action(philo);
		sleeping_action(philo);
		thinking_action(philo);
		break ;
	}
	pthread_detach(philo->thread);
	return (0);
}
