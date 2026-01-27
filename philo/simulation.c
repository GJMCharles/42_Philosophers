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

void	syncronised_loader(t_param **param, unsigned int *is_init)
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
		if (*is_init == 0)
		{
			*is_init = 1;
			(*param)->test_count += 1;
		}
		pthread_mutex_unlock(&(*param)->mutex_start);
	}
}

void	*simulation(void *arg)
{
	t_philo			*philo;
	t_param			*param;
	unsigned int	is_init;
	// unsigned long int	timestamp;

	philo = (t_philo *)arg;
	param = philo->param;
	is_init = 0;
	// timestamp = get_timestamp_ms();
	// is_init = 0;
	syncronised_loader(&param, &is_init);
	// philo->status = SLEEPING;
	// print_status(philo);
	printf("TEST {%u} {%lu}\n", philo->id, (get_timestamp_ms() - param->start_timestamp));
	// while (1)
	// {
	// 	action_eat(philo);
	// 	if (can_abort_simulation(philo))
	// 		break ;
	// 	action_sleep(philo);
	// 	if (can_abort_simulation(philo))
	// 		break ;
	// 	action_think(philo);
	// 	if (can_abort_simulation(philo))
	// 		break ;
	// }
	return ((void *) NULL);
}

void	start_simulation(t_data **data)
{
	// t_param	*param;
	t_philo	*current;
	t_philo	*first;

	// param = (*data)->param;
	current = (*data)->philo;
	first = current;
	while (current != (t_philo *) NULL)
	{
		// pthread_mutex_lock(&(param->mutex_start));

		// pthread_mutex_unlock(&(param->mutex_start));
		pthread_create(&current->thread, NULL, &simulation, (void *) current);
		current = current->next;
		if (current == first)
			break ;
	}
	while (current != (t_philo *) NULL)
	{
		pthread_join(current->thread, (void *) NULL);
		current = current->next;
		if (current == first)
			break ;
	}
}
