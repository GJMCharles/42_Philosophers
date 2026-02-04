/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grcharle <grcharle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/04 03:45:49 by grcharle          #+#    #+#             */
/*   Updated: 2026/02/04 03:45:51 by grcharle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	are_philosophers_satisfied(t_param *param)
{
	unsigned int	index;
	unsigned int	*arr;
	unsigned int	min;

	if (param->eating_limits == -1)
		return (FALSE);
	index = 0;
	arr = param->array_eat_count;
	min = arr[0];
	while (index < param->nb_philos)
	{
		if (min > arr[index])
			min = arr[index];
		index += 1;
	}
	if (min != (unsigned int) param->eating_limits)
		return (FALSE);
	param->abort_simulation = TRUE;
	return (TRUE);
}

int	is_philosopher_alive(t_philo *philo, t_param *param)
{
	unsigned long int	duration;

	pthread_mutex_lock(&param->mutex_timestamp);
	duration = get_current_timestamp() - philo->last_eaten;
	if (duration >= param->time_to_die)
	{
		philo->is_dead = TRUE;
		param->abort_simulation = TRUE;
		return (pthread_mutex_unlock(&param->mutex_timestamp), FALSE);
	}
	return (pthread_mutex_unlock(&param->mutex_timestamp), TRUE);
}

int	validate_arguments(int argc, char *argv[])
{
	int	index;
	int	j;
	int	value;

	if (argc < 5 || argc > 6)
		return (FALSE);
	index = 1;
	while (index < argc)
	{
		value = ft_atoi(argv[index]);
		if (!value || value < 0)
			return (FALSE);
		j = 0;
		while (argv[index][j] != '\0')
		{
			if (!ft_isdigit(argv[index][j]))
				return (FALSE);
			j += 1;
		}
		index += 1;
	}
	return (TRUE);
}
