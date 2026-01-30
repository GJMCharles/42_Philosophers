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

int	everyone_satiated(t_philo *philo, t_param *param)
{
	unsigned int	lower_limit;
	t_philo			*temp;

	if (!philo->next)
		return (FALSE);
	lower_limit = philo->eating_counter;
	temp = philo;
	while (1)
	{
		if (lower_limit > temp->eating_counter)
			lower_limit = temp->eating_counter;
		temp = temp->next;
		if (philo->id == temp->id)
			break ;
	}
	if (param->eating_limits == (int) lower_limit)
		return (TRUE);
	return (FALSE);
}

int	should_abort_simulator(t_philo *philo, t_param *param)
{
	if (param->abort_simulator == TRUE)
		return (TRUE);
	if (param->eating_limits > 0 && everyone_satiated(philo, param))
	{
		param->abort_simulator = TRUE;
		return (TRUE);
	}
	if (philo->last_eaten == 0)
	{
		if ((get_timestamp_ms() - param->start_timestamp) > param->time_to_die)
		{
			philo->status = DEAD;
			return (TRUE);
		}
	}
	else
	{
		if ((get_timestamp_ms() - philo->last_eaten) > param->time_to_die)
		{
			philo->status = DEAD;
			return (TRUE);
		}
	}
	return (FALSE);
}

void set_timestamp(t_param *param)
{
	pthread_mutex_lock(&param->mutex_start);
	if (param->start_timestamp == 0)
		param->start_timestamp = get_timestamp_ms();
	pthread_mutex_unlock(&(param->mutex_start));
}

void *simulator(void *arg)
{
	t_philo *philo;
	t_param *param;

	philo = (t_philo *)arg;
	param = philo->param;
	set_timestamp(param);
	while (1)
	{
		if (action_eat(philo, param) == FALSE)
			break;
		if (action_sleep(philo, param) == FALSE)
			break;
		if (action_think(philo, param) == FALSE)
			break;
	}
	if (philo->status == DEAD)
		action_die(philo, param);
	return ((void *)NULL);
}

void start_simulators(t_data **data)
{
	t_philo *current;
	t_philo *first;

	current = (*data)->philo;
	first = current;
	while (current != (t_philo *)NULL)
	{
		pthread_create(&(current->thread), NULL, &simulator, (void *)current);
		current = current->next;
		if (current == first)
			break;
	}
	while (current != (t_philo *)NULL)
	{
		pthread_join(current->thread, (void *)NULL);
		current = current->next;
		if (current == first)
			break;
	}
}
