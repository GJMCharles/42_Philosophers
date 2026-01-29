/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grcharle <grcharle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/23 05:49:05 by grcharle          #+#    #+#             */
/*   Updated: 2026/01/23 05:49:21 by grcharle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	forced_waiting(t_param *param, unsigned int delay)
{
	unsigned long int current;

	current = get_timestamp_ms();
	while ((get_timestamp_ms() - current) < delay)
	{
		pthread_mutex_lock(&(param->mutex_wait));
		usleep(100);
		pthread_mutex_unlock(&(param->mutex_wait));
	}
}

char *get_status_text(t_status code)
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
	return ((char *)NULL);
}

void display_current_status(t_philo *philo)
{
	pthread_mutex_lock(&(philo->param->mutex_print));
	printf(
		"%lu %u %s\n",
		(get_timestamp_ms() - philo->param->start_timestamp),
		philo->id,
		get_status_text(philo->status));
	pthread_mutex_unlock(&(philo->param->mutex_print));
}

unsigned long int get_timestamp_ms(void)
{
	struct timeval time;

	gettimeofday(&time, NULL);
	return ((time.tv_sec * 1000) + (time.tv_usec / 1000));
}

void free_data(t_data **data)
{
	t_data *temp;

	if (!(*data))
		return;
	temp = *data;
	if (temp->philo != (t_philo *)NULL)
		clear_philosophers(&(temp->philo));
	if (temp->param != (t_param *)NULL)
	{
		free(temp->param);
		temp->param = (t_param *)NULL;
	}
	free(temp);
	temp = (t_data *)NULL;
}
