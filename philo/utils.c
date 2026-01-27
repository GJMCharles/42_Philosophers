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

// int		get_line()

// void	print_status(t_philo *philo)
// {
// 	exec_mutex(philo->param->mutex_print, get_line());
// }

// char	*get_text_from_status(t_status code)
// {
// 	if (code == PICK_FORK)
// 		return ((char *) "has taken a fork");
// 	else if (code == EATING)
// 		return ((char *) "is eating");
// 	else if (code == SLEEPING)
// 		return ((char *) "is sleeping");
// 	else if (code == THINKING)
// 		return ((char *) "is thinking");
// 	else if (code == DEAD)
// 		return ((char *) "died");
// 	return ((char *) NULL);
// }

// void	print_status(t_philo *philo)
// {
// 	pthread_mutex_lock(&philo->param->mutex_print);
// 	printf("%lu %u %s\n",
// 		(philo->param->start_timestamp - get_timestamp_ms()),
// 		philo->id,
// 		get_text_from_status(philo->status));
// 	pthread_mutex_unlock(&philo->param->mutex_print);
// }

// void	forced_waiting(unsigned int duration)
// {
// 	unsigned long int	current_time;

// 	current_time = get_timestamp_ms();
// 	while ((get_timestamp_ms() - current_time) < (unsigned long int) duration)
// 		usleep(100);
// }


unsigned long int	get_timestamp_ms(void)
{
	struct timeval		time;

	gettimeofday(&time, NULL);
	return ((time.tv_sec * 1000) + (time.tv_usec / 1000));
}

void	free_data(t_data **data)
{
	t_data	*temp;

	if (!(*data))
		return ;
	temp = *data;
	if (temp->philo != (t_philo *) NULL)
		clear_philosophers(&(temp->philo));
	if (temp->param != (t_param *) NULL)
	{
		free(temp->param);
		temp->param = (t_param *) NULL;
	}
	free(temp);
	temp = (t_data *) NULL;
}
