/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   forks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grcharle <grcharle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/28 06:15:11 by grcharle          #+#    #+#             */
/*   Updated: 2026/02/28 06:15:30 by grcharle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

bool	search_left_fork(t_philo *philo)
{
	t_params	*p;
	t_ui		d;
	bool		t;

	p = philo->params;
	d = (philo->id + 1) % p->nb_philos;
	t = (philo->id % 2) == 0;
	while (1)
	{
		if (should_abort(philo))
			return (false);
		(void) pthread_mutex_lock(&p->mutex_pick);
		if ((t && p->fork_box[philo->id] == 1) || (!t && p->fork_box[d] == 1))
		{
			if (t)
				p->fork_box[philo->id] = 0;
			else
				p->fork_box[d] = 0;
			(void) pthread_mutex_unlock(&p->mutex_pick);
			break ;
		}
		(void) pthread_mutex_unlock(&p->mutex_pick);
		usleep(100);
	}
	return (true);
}

bool	search_right_fork(t_philo *philo)
{
	t_params	*p;
	t_ui		d;
	bool		t;

	p = philo->params;
	d = (philo->id + 1) % p->nb_philos;
	t = (philo->id % 2) == 0;
	while (1)
	{
		if (should_abort(philo))
			return (false);
		(void) pthread_mutex_lock(&p->mutex_pick);
		if ((t && p->fork_box[d] == 1) || (!t && p->fork_box[philo->id] == 1))
		{
			if (t)
				p->fork_box[d] = 0;
			else
				p->fork_box[philo->id] = 0;
			(void) pthread_mutex_unlock(&p->mutex_pick);
			break ;
		}
		(void) pthread_mutex_unlock(&p->mutex_pick);
		usleep(100);
	}
	return (true);
}

void	return_left_fork(t_philo *philo)
{
	t_params	*params;
	t_ui		id_plus;
	int			is_valid;

	params = philo->params;
	id_plus = (philo->id + 1) % params->nb_philos;
	is_valid = (philo->id % 2) == 0;

	pthread_mutex_lock(&params->mutex_pick);
	if (is_valid && params->fork_box[philo->id] == 0)
		params->fork_box[philo->id] = 1;
	else if (!is_valid && params->fork_box[id_plus] == 0)
		params->fork_box[id_plus] = 1;
	pthread_mutex_unlock(&params->mutex_pick);
}

void	return_right_fork(t_philo *philo)
{
	t_params	*params;
	t_ui		id_plus;
	int			is_valid;

	params = philo->params;
	id_plus = (philo->id + 1) % params->nb_philos;
	is_valid = (philo->id % 2) == 0;

	pthread_mutex_lock(&params->mutex_pick);
	if (is_valid && params->fork_box[id_plus] == 0)
		params->fork_box[id_plus] = 1;
	else if (!is_valid && params->fork_box[philo->id] == 0)
		params->fork_box[philo->id] = 1;
	pthread_mutex_unlock(&params->mutex_pick);
}
