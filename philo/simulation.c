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

char	*get_text_from_status(t_status code)
{
	if (code == PICK_FORK)
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

void	waiting_loader(t_param *param, unsigned int *is_init)
{
	while (1)
	{
		pthread_mutex_lock(&(param->mutex_start));
		if (!*is_init)
		{
			*is_init = 1;
			param->initiator_count += 1;
		}
		usleep(100);
		if (param->initiator_count == param->nb_philos)
		{
			param->start_timestamp = get_timestamp_ms();
			pthread_mutex_unlock(&(param->mutex_start));
			break ;
		}
		pthread_mutex_unlock(&(param->mutex_start));
	}
}

void	*simulation(void *arg)
{
	t_philo			*philo;
	unsigned int	is_init;

	philo = (t_philo *)arg;
	is_init = 0;
	waiting_loader(philo->param, &is_init);
	while (1)
	{
		action_eat(philo);
		if (can_abort_simulation(philo))
			break ;
		action_sleep(philo);
		if (can_abort_simulation(philo))
			break ;
		action_think(philo);
		if (can_abort_simulation(philo))
			break ;
	}
	return ((void *) NULL);
}

void	start_simulation(t_data **data)
{
	t_data	*temp;
	t_philo	*first;
	t_philo	*current;

	temp = *data;
	first = temp->philo;
	current = temp->philo;
	while (current != (t_philo *) NULL)
	{
		pthread_create(&current->thread, NULL, &simulation, (void *) current);
		current = current->next;
		if (current == first)
			break ;
	}
	current = temp->philo;
	while (current != (t_philo *) NULL)
	{
		pthread_join(current->thread, (void **) NULL);
		current = current->next;
		if (current == first)
			break ;
	}
}
