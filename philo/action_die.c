/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   action_die.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grcharle <grcharle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/15 05:40:28 by grcharle          #+#    #+#             */
/*   Updated: 2026/01/15 05:45:16 by grcharle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

// int	least_eaten_number(t_philo *philo)
// {
// 	t_philo			*first;
// 	t_philo			*current;
// 	unsigned int	nb;

// 	first = philo;
// 	current = philo;
// 	nb = current->eating_counter;
// 	current = current->next;
// 	while (current && current->next != (t_philo *) NULL && current != first)
// 	{
// 		if (nb > current->eating_counter)
// 			nb = current->eating_counter;
// 		current = current->next;
// 	}
// 	return (nb);
// }

// int	death_callback(t_philo *philo)
// {
// 	if (philo->param->abort_simulation)
// 		return (1);
// 	if (philo->param->eating_limits > 0)
// 	{
// 		if (least_eaten_number(philo) == philo->param->eating_limits)
// 		{
// 			philo->param->abort_simulation = 1;
// 			return (1);
// 		}
// 	}
// 	if ((get_timestamp_ms() - philo->last_eaten) >= philo->param->time_to_die)
// 	{
// 		philo->status = DEAD;
// 		philo->param->abort_simulation = 1;
// 		print_status(philo);
// 		return (1);
// 	}
// 	return (0);
// }

// int	can_abort_simulation(t_philo *philo)
// {
// 	return (exec_mutex(&(philo->param->mutex_dead), philo, death_callback));
// }
