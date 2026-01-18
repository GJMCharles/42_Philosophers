/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simulation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grcharle <grcharle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/14 06:37:38 by grcharle          #+#    #+#             */
/*   Updated: 2026/01/15 08:59:37 by grcharle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

unsigned long int	get_timestamp_ms(void)
{
	struct timeval		time;

	gettimeofday(&time, NULL);
	return ((time.tv_sec * 1000) + (time.tv_usec / 1000));
}

char	*get_text_from_status(t_status code)
{
	if (code == FORK_UP)
		return ((char *) "has taken a fork");
	else if (code == EATING)
		return ((char *) "is eating");
	else if (code == SLEEPING)
		return ((char *) "is sleeping");
	else if (code == THINKING)
		return ((char *) "is thinking");
	else if (code == DEAD)
		return ((char *) "died");
	return ((char *) NULL);
}

void	*simulation(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	while (1)
	{
		if (philo->param->death_encountered == 1 || philo->has_died == 1)
			break ;
		if (philo->param->eating_limits > 0)
		{
			if (philo->param->eating_limits == philo->param->total_min_eaten)
				break ;
		}
		break ;
	}
	return ((void *) NULL);
}

void	start_simulation(t_data **data)
{
	t_data	*temp;
	t_philo	*first;
	t_philo	*philo;

	temp = *data;
	first = temp->philo;
	philo = temp->philo;
	while (philo != (t_philo *) NULL)
	{
		pthread_create(&philo->thread, NULL, &simulation, (void *) philo);
		philo = philo->next;
		if (philo == first)
			break ;
	}
	philo = temp->philo;
	temp->param->timestamp_start = get_timestamp_ms();
	while (philo != (t_philo *) NULL)
	{
		pthread_join(philo->thread, (void **) NULL);
		philo = philo->next;
		if (philo == first)
			break ;
	}
}
