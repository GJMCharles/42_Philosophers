/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   action.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grcharle </var/spool/mail/grcharle>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/14 06:37:38 by grcharle          #+#    #+#             */
/*   Updated: 2026/01/14 06:37:55 by grcharle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

char	*get_status_text(t_status code)
{
	if (code == FORK_UP)
		return ("has taken a fork");
	if (code == FORK_DOWN)
		return ("has returned a fork");
	else if (code == EATING)
		return ("is eating");
	else if (code == SLEEPING)
		return ("is sleeping");
	else if (code == THINKING)
		return ("is thinking");
	else if (code == DEAD)
		return ("died");
	return ((char *) NULL);
}

void	report_message(t_philo *philo)
{
	unsigned long int	current_time;

	pthread_mutex_lock(&philo->param->mutex_printer);
	pthread_mutex_lock(&philo->param->mutex_timer);
	current_time = get_timestamp_ms();
	pthread_mutex_unlock(&philo->param->mutex_timer);
	printf("%lu %u %s\n",
		current_time - philo->param->start_time,
		philo->id,
		get_status_text(philo->status));
	pthread_mutex_unlock(&philo->param->mutex_printer);
}

void	*activities(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	while (1)
	{
		if (philo->param->death_encountered == 1)
			break ;
		if (philo->param->eating_limits != -1)
		{
			if (philo->param->eating_limits == philo->eat_counter)
				break ;
		}
		if (action_eat(philo) == 0)
			return (action_die(philo), (void *) NULL);
		action_sleep(philo);
		action_think(philo);
	}
	return ((void *) NULL);
}

void	philosophers_activities(t_data **data)
{
	t_data	*temp;
	t_philo	*philo_first;
	t_philo	*philo;

	temp = *data;
	philo_first = temp->philo;
	philo = temp->philo;
	while (philo != (t_philo *) NULL)
	{
		pthread_create(&philo->thread, NULL, &activities, (void *) philo);
		philo = philo->next;
		if (philo == philo_first)
			break ;
	}
	philo = temp->philo;
	temp->param->start_time = get_timestamp_ms();
	while (philo != (t_philo *) NULL)
	{
		pthread_join(philo->thread, (void **) NULL);
		philo = philo->next;
		if (philo == philo_first)
			break ;
	}
}
