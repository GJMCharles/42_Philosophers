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

// void	single_philosopher_found(t_philo *philo, pthread_mutex_t *m)
// {
// 	pthread_mutex_lock(m);
// 	display_message(FORK, philo, (char *) NULL);
// 	philo->is_dead = TRUE;
// 	pthread_mutex_unlock(m);
// }

// int	can_pick_fork(t_philo *philo)
// {
// 	unsigned char	is_left_picked;
// 	unsigned char	is_right_picked;

// 	is_left_picked = philo->fork_picked;
// 	is_right_picked = philo->next->fork_picked;

// 	if (is_left_picked == TRUE && is_right_picked == FALSE)
// 		return (TRUE);
// 	return (FALSE);
// }

// void	waiting_mutex(pthread_mutex_t *mf, t_philo *philo, t_param *pa)
// {
// 	while (philo->next->fork_picked == TRUE)
// 	{
// 		philo->fork_picked = 0;
// 		pthread_mutex_unlock(mf);
// 		pthread_mutex_lock(&pa->mutex_wait);		
// 		usleep(100);
// 		pthread_mutex_unlock(&pa->mutex_wait);
// 		pthread_mutex_lock(mf);
// 		philo->fork_picked = 1;
// 	}
// }

// void	test_me(t_philo *philo)
// {
// 	unsigned char	is_left_picked;
// 	unsigned char	is_right_picked;

// 	is_left_picked = philo->fork_picked;
// 	is_right_picked = philo->next->fork_picked;
// 	printf("{%u} {%u}\n", is_left_picked, is_right_picked);
// }

// int	action_eat(t_philo *philo, t_param *param)
// {
// 	unsigned int	index_left;
// 	unsigned int	index_right;

// 	index_left = philo->id;
// 	index_right = (philo->id + 1) % param->nb_philos;
// 	if (param->nb_philos == 1)
// 	{
// 		single_philosopher_found(philo, &param->forks[index_left]);
// 		return (forced_waiting(param, param->time_to_die), FALSE);
// 	}
	
// 	pthread_mutex_lock(&param->forks[index_left]);
// 	philo->fork_picked = 1;
// 	test_me(philo);
// 	display_message(FORK, philo, (char *) NULL);
// 	waiting_mutex(&param->mutex_wait, philo, param);
	
// 	pthread_mutex_lock(&param->forks[index_right]);
// 	philo->next->fork_picked = 1;
// 	test_me(philo);
// 	display_message(FORK, philo, (char *) NULL);

// 	display_message(EATING, philo, (char *) NULL);
	
// 	philo->last_eaten = get_timestamp_ms();
// 	//philo->eating_counter += 1;
// 	forced_waiting(param, param->time_to_eat);
// 	philo->next->fork_picked = 0;
// 	pthread_mutex_unlock(&param->forks[index_right]);
// 	//philo->fork_picked = 0;
// 	pthread_mutex_unlock(&param->forks[index_left]);
// 	return (TRUE);
// }

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
