/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grcharle <grcharle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/14 06:52:37 by grcharle          #+#    #+#             */
/*   Updated: 2026/02/03 21:41:29 by grcharle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	action_die(t_philo *philo, t_param *param)
{
	pthread_mutex_lock(&param->mutex_dead);
	ft_usleep(10);
	display_log(DEAD, philo);
	pthread_mutex_unlock(&param->mutex_dead);
}

int	action_think(t_philo *philo, t_param *param)
{
	if (is_philosopher_alive(philo, param) == FALSE)
		return (FALSE);
	pthread_mutex_lock(&param->mutex_thinking);
	display_log(THINKING, philo);
	pthread_mutex_unlock(&param->mutex_thinking);
	return (TRUE);
}

int	action_sleep(t_philo *philo, t_param *param)
{
	if (is_philosopher_alive(philo, param) == FALSE)
		return (FALSE);
	if (are_philosophers_satisfied(param) == TRUE)
		return (FALSE);
	pthread_mutex_lock(&param->mutex_eating);
	display_log(SLEEPING, philo);
	pthread_mutex_unlock(&param->mutex_eating);
	ft_usleep(param->time_to_sleep);
	return (TRUE);
}

void	action_solo(t_philo *philo, t_param *param)
{
	philo->is_dead = TRUE;
	param->abort_simulation = TRUE;
	ft_usleep(param->time_to_die);
}

int	action_eat(t_philo *philo, t_param *param)
{
	if (is_philosopher_alive(philo, param) == FALSE)
		return (FALSE);
	pthread_mutex_lock(philo->left_fork);
	display_log(FORK, philo);
	if (param->nb_philos == 1)
	{
		action_solo(philo, param);
		return (pthread_mutex_unlock(philo->left_fork), FALSE);
	}
	if (is_philosopher_alive(philo, param) == FALSE)
		return (pthread_mutex_unlock(philo->left_fork), FALSE);
	pthread_mutex_lock(philo->right_fork);
	display_log(FORK, philo);
	pthread_mutex_lock(&param->mutex_eating);
	display_log(EATING, philo);
	param->array_eat_count[philo->id] += 1;
	philo->last_eaten = get_current_timestamp();
	pthread_mutex_unlock(&param->mutex_eating);
	ft_usleep(param->time_to_eat);
	pthread_mutex_unlock(philo->right_fork);
	pthread_mutex_unlock(philo->left_fork);
	return (TRUE);
}
