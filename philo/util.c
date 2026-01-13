/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grcharle </var/spool/mail/grcharle>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/13 20:46:10 by grcharle          #+#    #+#             */
/*   Updated: 2026/01/13 20:47:18 by grcharle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	free_all(t_data **data)
{
	t_data	*temp;

	if (!(*data))
		return ;
	temp = *data;
	if (!!temp->philo && temp->philo != (t_philo *) NULL)
	{
		// free(temp->philo);
		// temp->philo = (t_philo *) NULL;
		// clear_philosophers(&temp->philo);
	}
	if (!!temp->param && temp->param != (t_param *) NULL)
	{
		free(temp->param);
		temp->param = (t_param *) NULL;
	}
	free(temp);
	temp = (t_data *) NULL;
}

void	display_error(char *message)
{
	ft_putendl_fd(message, STDERR_FILENO);
}
