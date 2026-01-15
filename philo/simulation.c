/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simulation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grcharle </var/spool/mail/grcharle>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/14 06:37:38 by grcharle          #+#    #+#             */
/*   Updated: 2026/01/15 08:59:37 by grcharle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	exec_pthread(pthread_mutex_t *m, void (*func)(void))
{
	pthread_mutex_lock(m);
	func();
	pthread_mutex_unlock(m);
}

char	*get_text_from_status(t_status code)
{
	if (code == FORK_UP)
		return ("has taken a fork");
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

// void	report_message(t_philo *philo)
// {
// 	unsigned long int	current_time;

// 	pthread_mutex_lock(&philo->param->mutex_print);
// 	pthread_mutex_lock(&philo->param->mutex_timestamp);
// 	current_time = get_timestamp_ms();
// 	pthread_mutex_unlock(&philo->param->mutex_timestamp);
// 	printf("%lu %u %s\n",
// 		current_time - philo->param->timestamp_start,
// 		philo->id,
// 		get_text_from_status(philo->status));
// 	pthread_mutex_unlock(&philo->param->mutex_print);
// }

void	*simulation(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	while (1)
	{
		if (philo->param->death_encountered == 0)
			action_eat(philo);
		// if (philo->param->death_encountered == 0)
		// 	action_sleep(philo);
		// if (philo->param->death_encountered == 0)
		// 	action_think(philo);
		if (philo->param->death_encountered == 1 || philo->has_died == 1)
			break ;
		if (philo->param->eating_limits > 0)
		{
			if (philo->param->eating_limits == philo->param->total_min_eaten)
				break ;
		}
		break ;
	}
	if (philo->has_died == 1)
		action_die(philo);
	return ((void *) NULL);
}

void	start_simulation(t_data **data)
{
	t_data	*temp;
	t_philo	*philo_first;
	t_philo	*philo;

	temp = *data;
	philo_first = temp->philo;
	philo = temp->philo;
	while (philo != (t_philo *) NULL)
	{
		pthread_create(&philo->thread, NULL, &simulation, (void *) philo);
		philo = philo->next;
		if (philo == philo_first)
			break ;
	}
	philo = temp->philo;
	temp->param->timestamp_start = get_timestamp_ms();
	while (philo != (t_philo *) NULL)
	{
		pthread_join(philo->thread, (void **) NULL);
		philo = philo->next;
		if (philo == philo_first)
			break ;
	}
}
