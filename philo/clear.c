/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clear.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grcharle <grcharle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/30 06:03:56 by grcharle          #+#    #+#             */
/*   Updated: 2025/12/30 06:03:59 by grcharle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	flush_data(t_data *data)
{
	if (data->param)
	{
		free(data->param);
	}
	clear_philo_list(&(data->philo));
}
