/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   action_eat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grcharle <grcharle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/14 06:52:37 by grcharle          #+#    #+#             */
/*   Updated: 2026/01/14 06:52:51 by grcharle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

// int	start_eating(t_philo *philo, t_param *param)
// {
// 	pthread_mutex_lock(&param->mutex_eating);
// 	param->abort_simulator = should_abort_simulator(philo, param);
// 	if (param->abort_simulator == TRUE)
// 	{
// 		pthread_mutex_unlock(&param->mutex_eating);
// 		return (FALSE);
// 	}
// 	philo->status = EATING;
// 	philo->eating_counter += 1;
// 	display_message(philo);
// 	forced_waiting(param, param->time_to_eat);
// 	philo->last_eaten = get_timestamp_ms();
// 	pthread_mutex_unlock(&param->mutex_eating);
// 	return (TRUE);
// }

// int	pick_right_fork(t_philo *philo, t_param *param)
// {
// 	display_message(philo);
// 	return (start_eating(philo, param));
// }

// int	pick_left_fork(t_philo *philo, t_param *param)
// {
// 	philo->status = FORK;
// 	display_message(philo);
// 	if (philo->next == (t_philo *) NULL)
// 	{
// 		philo->status = DEAD;
// 		forced_waiting(param, param->time_to_die);
// 		return (FALSE);
// 	}
// 	return (exec_pthread_mutex(philo->next->fork, philo, param, pick_right_fork));
// }
//////////////////
// int	start_eating(t_philo *philo, t_param *param)
// {
// 	(void) param;
// 	philo->status = EATING;
// 	display_message(philo, (char *) NULL);
// 	philo->eating_counter += 1;
// 	return (TRUE);
// }

// int	pick_right_fork(t_philo *philo, t_param *param)
// {
// 	int	status;

// 	philo->status = FORK;
// 	display_message(philo, (char *) NULL);
// 	status = exec_pthread_mutex(param->mutex_eating, philo, param, start_eating);
// 	forced_waiting(param, param->time_to_eat);
// 	philo->last_eaten = get_timestamp_ms();
// 	return (status);
// }

// int	pick_left_fork(t_philo *philo, t_param *param)
// {
// 	philo->status = FORK;
// 	display_message(philo, (char *) NULL);
// 	if (philo->next == (t_philo *) NULL)
// 	{
// 		philo->status = DEAD;
// 		param->abort_simulator = TRUE;
// 		forced_waiting(param, param->time_to_die);
// 		return (FALSE);
// 	}
// 	return (exec_pthread_mutex(philo->next->fork, philo, param, pick_right_fork));
// }

int	eating_process(t_philo *philo, t_param *param)
{
	(void) param;
	philo->status = EATING;
	display_message(philo, (char *) NULL);
	philo->last_eaten = get_timestamp_ms();
	philo->eating_counter += 1;
	return (TRUE);
}

int	pick_right_fork(t_philo *philo, t_param *param)
{
	int	status;

	display_message(philo, (char *) NULL);
	status = exec_pthread_mutex(philo->fork, philo, param, eating_process);
	return (status);
}

int	pick_left_fork(t_philo *philo, t_param *param)
{
	int	status;

	philo->status = FORK;
	display_message(philo, (char *) NULL);
	if (!(philo->next))
	{
		philo->status = DEAD;
		param->abort_simulator = TRUE;
		return (FALSE);
	}
	status = exec_pthread_mutex(philo->next->fork, philo, param, pick_right_fork);
	return (status);
}

int	action_eat(t_philo *philo, t_param *param)
{
	int	status;

	status = exec_pthread_mutex(philo->fork, philo, param, pick_left_fork);
	if (status)
		forced_waiting(param, param->time_to_eat);
	return (status);
}
