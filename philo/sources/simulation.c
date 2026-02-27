/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simulation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grcharle <grcharle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/10 14:01:21 by grcharle          #+#    #+#             */
/*   Updated: 2026/02/10 14:02:21 by grcharle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

//void	everyone_should_be_satiated(t_philo *philo)
//{
//	t_params	*params;

//	params = philo->params;

//	if (params->eating_limit > 0
//		&& (philo->eat_counter == (t_ui) params->eating_limit))
//	{
//		params->reached_eating_limit += 1;
//		if (params->reached_eating_limit == params->nb_philos)
//			set_abort_simulation(params, true);
//	}
//}

//bool	should_abort(t_philo *philo)
//{
//	t_params	*params;

//	params = philo->params;
//	if (get_delay_from_last_meal(philo) >= (t_uli) params->time_to_die)
//	{
//		philo->is_dead = true;
//		set_abort_simulation(params, true);
//	}
//	return (get_abort_simulation(params));
//}

/**
 * 
 */
void	*simulation(void *arg)
{
	t_philo		*philo;
	//t_params	*params;

	philo = (t_philo *) arg;
	(void) philo;
	// params = philo->params;
	//start_timestamp(params, philo);
	//while (1)
	//{
	//	if (!action_eating(philo))
	//		break ;
	//	if (!action_sleeping(philo))
	//		break ;
	//	if (!action_thinking(philo))
	//		break ;
	//}
	//if (philo->is_dead == true)
	//	action_dying(philo);
	return (NULL);
}

/**
 * 
 */
void	start_simulation(t_data *data)
{
	t_philo		*philo;
	t_params	*params;
	t_ui		i;

	philo = data->philos;
	params = data->params;
	i = 0;
	while (i < params->nb_philos)
	{
		if (((i) % 2) == 0)
			pthread_create(&philo[i].thread, NULL, simulation, &philo[i]);
		i += 1;
	}
	i = 0;
	while (i < params->nb_philos)
	{
		if (((i) % 2) != 0)
			pthread_create(&philo[i].thread, NULL, simulation, &philo[i]);
		i += 1;
	}
	i = 0;
	while (i++ < params->nb_philos)
	{
		pthread_join(philo[i - 1].thread, (void **) NULL);
	}
}
