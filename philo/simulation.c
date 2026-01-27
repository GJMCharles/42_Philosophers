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

char	*get_status_text(t_status code)
{
	if (code == FORK)
		return ((char *)"has taken a fork");
	else if (code == EATING)
		return ((char *)"is eating");
	else if (code == SLEEPING)
			return ((char *)"is sleeping");
	else if (code == THINKING)
			return ((char *)"is thinking");
	else if (code == DEAD)
			return ((char *)"died");
	return ((char *) NULL);
}

void	display_current_state(t_philo *philo)
{
	pthread_mutex_lock(&(philo->param->mutex_print));
	printf(
		"%lu %u %s\n",
		(get_timestamp_ms() - philo->param->start_timestamp),
		philo->id,
		get_status_text(philo->status)
	);
	pthread_mutex_unlock(&(philo->param->mutex_print));
}

void	sync_simulators(t_param **param, unsigned int *sync_test)
{
	if (!(*param) || !param)
		return ;
	while (1)
	{
		pthread_mutex_lock(&(*param)->mutex_start);
		usleep(100);
		if ((*param)->test_count == (*param)->nb_philos)
		{
			(*param)->start_timestamp = get_timestamp_ms();
			pthread_mutex_unlock(&(*param)->mutex_start);
			break ;
		}
		if (*sync_test == 0)
		{
			*sync_test = 1;
			(*param)->test_count += 1;
		}
		pthread_mutex_unlock(&(*param)->mutex_start);
	}
}

void	*simulator(void *arg)
{
	t_philo			*philo;
	t_param			*param;
	unsigned int	sync_test;

	philo = (t_philo *)arg;
	param = philo->param;
	sync_test = 0;
	sync_simulators(&param, &sync_test);
	while (1)
	{
		if (param->abort_simulation || action_eat(philo) == FALSE)
			break;
		if (param->abort_simulation || action_sleep(philo) == FALSE)
			break;
		if (param->abort_simulation || action_think(philo) == FALSE)
			break;
		break ;
	}
	if (philo->status == DEAD)
		action_die(philo);
	return ((void *) NULL);
}

void	start_simulators(t_data **data)
{
	t_philo	*current;
	t_philo	*first;

	current = (*data)->philo;
	first = current;
	while (current != (t_philo *) NULL)
	{
		pthread_create(&current->thread, NULL, &simulator, (void *) current);
		pthread_join(current->thread, (void *) NULL);
		current = current->next;
		if (current == first)
			break ;
	}
}
