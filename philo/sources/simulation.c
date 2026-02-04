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

char	*get_action_text(t_action_code code)
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

void	display_log(t_action_code code, t_philo *philo)
{
	t_param	*param;

	param = philo->param;
	pthread_mutex_lock(&param->mutex_print);
	printf("%lu %u %s\n",
		(get_current_timestamp() - param->start_timestamp),
		(philo->id + 1),
		get_action_text(code));
	pthread_mutex_unlock(&param->mutex_print);
}

void	*simulation(void *arg)
{
	t_philo	*philo;
	t_param	*param;

	philo = (t_philo *) arg;
	param = philo->param;
	pthread_mutex_lock(&param->mutex_start);
	if (param->start_timestamp == 0)
		param->start_timestamp = get_current_timestamp();
	philo->last_eaten = param->start_timestamp;
	pthread_mutex_unlock(&param->mutex_start);
	if ((philo->id % 2) != 0)
		ft_usleep(param->time_to_eat);
	while (1)
	{
		if (param->abort_simulation || !action_eat(philo, param))
			break ;
		if (param->abort_simulation || !action_sleep(philo, param))
			break ;
		if (param->abort_simulation || !action_think(philo, param))
			break ;
	}
	if (philo->is_dead == TRUE)
		action_die(philo, param);
	return ((void *) NULL);
}

void	start_simulation(t_data **data)
{
	unsigned int	i;
	t_philo			*philo;
	t_param			*param;

	i = 0;
	philo = (*data)->philo;
	param = (*data)->param;
	while (i < param->nb_philos)
	{
		philo[i].left_fork = &param->forks[i];
		if (param->nb_philos > 1)
		{
			philo[i].right_fork = \
				&param->forks[(philo[i].id + 1) % param->nb_philos];
		}
		pthread_create(&(philo[i].thread), NULL, &simulation, &philo[i]);
		i += 1;
	}
	i = 0;
	while (i < param->nb_philos)
	{
		pthread_join(philo[i].thread, (void **) NULL);
		i += 1;
	}
}
