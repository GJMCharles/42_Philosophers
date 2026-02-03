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
	unsigned long int	current;

	current = get_timestamp_ms();
	while ((get_timestamp_ms() - current) < (unsigned long int) delay)
	{
		pthread_mutex_lock(&param->mutex_timestamp);
		usleep(100);
		pthread_mutex_unlock(&param->mutex_timestamp);
	}
}

char	*get_status_text(t_status code)
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

void	display_message(t_status code, t_philo *philo, char *message)
{
	t_param	*param;

	param = philo->param;
	pthread_mutex_lock(&param->mutex_print);
	if (message != (char *) NULL)
		ft_putendl_fd(message, STDOUT_FILENO);
	else
	{
		printf("%lu %u %s\n",
			get_timestamp_ms() - param->start_timestamp,
			(philo->id + 1),
			get_status_text(code)
		);
	}
	pthread_mutex_unlock(&param->mutex_print);
}

unsigned long int	get_timestamp_ms(void)
{
	struct timeval	time;

	gettimeofday(&time, NULL);
	return ((time.tv_sec * 1000) + (time.tv_usec / 1000));
}

int	verify_arguments(int argc, char *argv[])
{
	int	index;
	int	i;
	int	value;

	if (argc < 5 || argc > 6)
		return (FALSE);
	index = 1;
	while (index < argc)
	{
		value = ft_atoi(argv[index]);
		if (!value || value < 0)
			return (FALSE);
		i = 0;
		while (argv[index][i] != '\0')
		{
			if (!ft_isdigit(argv[index][i]))
				return (FALSE);
			i += 1;
		}
		index += 1;
	}
	return (TRUE);
}
