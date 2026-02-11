/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grcharle <grcharle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/10 16:02:13 by grcharle          #+#    #+#             */
/*   Updated: 2026/02/10 16:02:27 by grcharle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	execute_wait(uli milliseconds)
{
	uli	start;

	start = get_current_timestamp();
	while ((get_current_timestamp() - start) < milliseconds)
	{
		usleep(100);
	}
	return (0);
}

uli	get_current_timestamp(void)
{
	struct timeval	time;

	if (gettimeofday(&time, NULL) == -1)
		display_error("'gettimeofday' failed to load");
	return ((time.tv_sec * 1000) + (time.tv_usec / 1000));
}
