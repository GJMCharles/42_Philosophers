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

void	single_philosopher_found(t_philo *philo, pthread_mutex_t *m)
{
	pthread_mutex_lock(m);
	display_message(FORK, philo, (char *) NULL);
	philo->is_dead = TRUE;
	pthread_mutex_unlock(m);
}

int	can_pick_fork(t_philo *philo)
{
	unsigned char	is_left_picked;
	unsigned char	is_right_picked;

	is_left_picked = philo->fork_picked;
	is_right_picked = philo->next->fork_picked;

	if (is_left_picked == TRUE && is_right_picked == FALSE)
		return (TRUE);
	return (FALSE);
}

void	waiting_mutex(pthread_mutex_t *mf, t_philo *philo, t_param *pa)
{
	while (philo->next->fork_picked == TRUE)
	{
		philo->fork_picked = 0;
		pthread_mutex_unlock(mf);
		pthread_mutex_lock(&pa->mutex_wait);		
		usleep(100);
		pthread_mutex_unlock(&pa->mutex_wait);
		pthread_mutex_lock(mf);
		philo->fork_picked = 1;
	}
}

void	test_me(t_philo *philo)
{
	unsigned char	is_left_picked;
	unsigned char	is_right_picked;

	is_left_picked = philo->fork_picked;
	is_right_picked = philo->next->fork_picked;
	printf("{%u} {%u}\n", is_left_picked, is_right_picked);
}

int	action_eat(t_philo *philo, t_param *param)
{
	unsigned int	index_left;
	unsigned int	index_right;

	index_left = philo->id;
	index_right = (philo->id + 1) % param->nb_philos;
	if (param->nb_philos == 1)
	{
		single_philosopher_found(philo, &param->forks[index_left]);
		return (forced_waiting(param, param->time_to_die), FALSE);
	}
	
	pthread_mutex_lock(&param->forks[index_left]);
	philo->fork_picked = 1;
	test_me(philo);
	display_message(FORK, philo, (char *) NULL);
	waiting_mutex(&param->mutex_wait, philo, param);
	
	pthread_mutex_lock(&param->forks[index_right]);
	philo->next->fork_picked = 1;
	test_me(philo);
	display_message(FORK, philo, (char *) NULL);

	display_message(EATING, philo, (char *) NULL);
	
	philo->last_eaten = get_timestamp_ms();
	//philo->eating_counter += 1;
	forced_waiting(param, param->time_to_eat);
	philo->next->fork_picked = 0;
	pthread_mutex_unlock(&param->forks[index_right]);
	//philo->fork_picked = 0;
	pthread_mutex_unlock(&param->forks[index_left]);
	return (TRUE);
}
