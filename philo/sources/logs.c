/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   logs.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grcharle <grcharle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/10 18:52:27 by grcharle          #+#    #+#             */
/*   Updated: 2026/02/10 20:59:22 by grcharle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

/**
* char	*get_code_status_text(t_status code);
*/
char	*get_code_status_text(t_status x)
{
	if (x == TAKING_FORK)
		return ("has taken a fork");
	else if (x == EATING)
		return ("is eating");
	else if (x == SLEEPING)
		return ("is sleeping");
	else if (x == THINKING)
		return ("is thinking");
	else if (x == DEAD)
		return ("died");
	return ((char *) NULL);
}

/**
* void	display_log(t_ui id, t_status code, t_params *params);
*/
void	display_log(t_ui id, t_status code, t_params *params)
{
	(void) pthread_mutex_lock(&params->mutex_print);
	if (get_abort_simulation(params) && code != DEAD)
	{
		(void) pthread_mutex_unlock(&params->mutex_print);
		return ;
	}
	printf("%lu %u %s\n",
		get_timestamp() - params->time_of_start,
		id + 1,
		get_code_status_text(code));
	(void) pthread_mutex_unlock(&params->mutex_print);
}

/**
 * void	display_error(const char *message);
 */
void	display_error(const char *message)
{
	ft_putstr_fd("Error: ", STDERR_FILENO);
	ft_putstr_fd(message, STDERR_FILENO);
	(void) write(STDERR_FILENO, "\n", 1);
}
