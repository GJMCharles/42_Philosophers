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

char	*get_code_status_text(t_cd code)
{
	if (code == TAKING_FORK)
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

void	display_error(const char *message)
{
	char	nl;

	nl = '\n';
	ft_putstr_fd("Error :", STDERR_FILENO);
	ft_putstr_fd(message, STDERR_FILENO);
	write(STDERR_FILENO, &nl, 1);
}

void	display_log(t_ui id, t_cd code, t_pm *params)
{
	(void) pthread_mutex_lock(&params->mutex_print);
	printf(
		"%lu %u %s\n",
		(get_current_timestamp() - params->time_of_start),
		(id + 1),
		get_code_status_text(code));
	(void) pthread_mutex_unlock(&params->mutex_print);
}
