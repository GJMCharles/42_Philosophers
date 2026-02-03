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

/**
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
	{
		pthread_mutex_lock(&param->mutex_print);
		ft_putstr_fd("All philosophers have eaten ", STDOUT_FILENO);
		ft_putnbr_fd(lower_limit, STDOUT_FILENO);
		ft_putendl_fd(" times", STDOUT_FILENO);
		pthread_mutex_unlock(&param->mutex_print);
		return (TRUE);
	}
	return (FALSE);
}

int	should_abort_simulator(t_philo *philo, t_param *param)
{
	unsigned long int	duration;

	if (param->abort_simulator == TRUE)
		return (TRUE);
	if (param->eating_limits > 0 && everyone_satiated(philo, param))
		return (TRUE);
	duration = (get_timestamp_ms() - philo->last_eaten);
	if (duration >= param->time_to_die)
	{

		return (TRUE);
	}
	return (FALSE);
}
*/

void	set_timestamp(t_philo *philo, t_param *param)
{
	unsigned long int	timestamp;

	pthread_mutex_lock(&param->mutex_start);
	if (param->start_timestamp == 0)
	{
		timestamp = get_timestamp_ms();
		param->start_timestamp = timestamp;
	}
	else
		timestamp = param->start_timestamp;		
	philo->last_eaten = timestamp;
	pthread_mutex_unlock(&(param->mutex_start));
}

void	*simulator(void *arg)
{
	t_philo	*philo;
	t_param	*param;
	unsigned int	i;

	philo = (t_philo *)arg;
	param = philo->param;
	i = 1;
	set_timestamp(philo, param);
	while (i--)
	{
		if (param->abort_simulator || !action_eat(philo, param))
			break ;
		if (param->abort_simulator || !action_sleep(philo, param))
			break ;
		if (param->abort_simulator || !action_think(philo, param))
			break ;
	}
	if (philo->is_dead == TRUE)
		action_die(philo, param);
	return ((void *) NULL);
}

void	start_simulator(t_data **data)
{
	t_philo	*current;
	t_philo	*first;

	current = (*data)->philo;
	first = current;
	while (current != (t_philo *) NULL)
	{
		pthread_create(&(current->thread), NULL, &simulator, (void *)current);
		if (current->next == (t_philo *) NULL)
			pthread_join(current->thread, (void **) NULL);
		current = current->next;
		if (current == first)
			break ;
	}
	while (current != (t_philo *) NULL)
	{
		pthread_join(current->thread, (void **) NULL);
		current = current->next;
		if (current == first)
			break ;
	}
}
