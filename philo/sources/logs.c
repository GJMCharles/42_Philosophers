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
char	*get_code_status_text(t_status code)
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
void	display_log(t_ui id, t_status code, t_params *params)
{
	(void) pthread_mutex_lock(&params->mutex_print);
	// if (get_abort_simulation(params) && code != DEAD)
	// {
	// 	(void) pthread_mutex_unlock(&params->mutex_print);
	// 	return ;
	// }
	ft_putnbr_fd(get_timestamp() - params->time_of_start, STDOUT_FILENO);
	(void) write(STDOUT_FILENO, " ", 1);
	ft_putnbr_fd(id + 1, STDOUT_FILENO);
	(void) write(STDOUT_FILENO, " ", 1);
	ft_putstr_fd(get_code_status_text(code), STDOUT_FILENO);
	(void) write(STDOUT_FILENO, "\n", 1);
	(void) pthread_mutex_unlock(&params->mutex_print);
}

/**
 * 
 */
void	display_error(const char *message)
{
	t_uc	nl;

	nl = '\n';
	ft_putstr_fd("Error: ", STDERR_FILENO);
	ft_putstr_fd(message, STDERR_FILENO);
	(void) write(STDERR_FILENO, &nl, 1);
}
