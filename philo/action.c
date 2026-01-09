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

void		*philosopher_actions(void *arg)
{
	t_philo		*philo;

	philo = (t_philo *) arg;
	printf("{{%u}}\n", philo->id);
	while (1)
	{
		break ;
	}
	pthread_detach(philo->thread);
	return (0);
}
