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
 * 
 */
char	*get_code_status_text(t_cd code)
{
	if (code == TAKING_FORK)
		return ("has taken a fork");
	else if (code == EATING)
		return ("is eating");
	else if (code == SLEEPING)
		return ("is sleeping");
	else if (code == THINKING)
		return ("is thinking");
	else if (code == DEAD)
		return ("died");
	return ((char *) NULL);
}

/**
 * 
 */
void	display_error(const char *message)
{
	t_uc	nl;

	nl = '\n';
	ft_putstr_fd("Error :", STDERR_FILENO);
	ft_putstr_fd(message, STDERR_FILENO);
	(void) write(STDERR_FILENO, &nl, 1);
}

/**
 * 
 */
void	display_log(t_ui id, t_cd code, t_pm *params)
{
	t_uc	nl;
	t_uc	sp;

	nl = '\n';
	sp = ' ';
	(void) pthread_mutex_lock(&params->mutex_print);
	if (params->can_abort_simulation && code != DEAD)
	{
		(void) pthread_mutex_unlock(&params->mutex_print);
		return ;
	}
	ft_putnbr_fd(get_timestamp() - params->time_of_start, STDOUT_FILENO);
	(void) write(STDOUT_FILENO, &sp, 1);
	ft_putnbr_fd(id, STDOUT_FILENO);
	(void) write(STDOUT_FILENO, &sp, 1);
	ft_putstr_fd(get_code_status_text(code), STDOUT_FILENO);
	(void) write(STDOUT_FILENO, &nl, 1);
	(void) pthread_mutex_unlock(&params->mutex_print);
}
