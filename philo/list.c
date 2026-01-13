/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_list.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grcharle <grcharle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/08 09:08:51 by grcharle          #+#    #+#             */
/*   Updated: 2026/01/08 09:09:00 by grcharle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	display_philosophers(t_philo *data)
{
	unsigned int	index;

	index = 0;
	while (data && index < 15)
	{
		printf("ID [%u]: || ", data->id);
		if (data->prev)
			printf("(prev ID) [%u]: || ", data->prev->id);
		else
			printf("(prev ID) [X]: || ");
		if (data->next)
			printf("(next ID) [%u]: \n", data->next->id);
		else
			printf("(next ID) [X]: \n");
		data = data->next;
		index += 1;
	}
}
