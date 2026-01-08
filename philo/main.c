/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grcharle <grcharle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/08 08:37:55 by grcharle          #+#    #+#             */
/*   Updated: 2026/01/08 08:38:24 by grcharle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	display_philos(t_data *data)
{
	t_philo			*temp;
	unsigned int	index;

	index = 0;
	temp = data->philo;
	while (temp && index < 7)
	{
		printf("ID [%u]: || ", temp->id);
		if (temp->next)
			printf("(next ID) [%u]: || ", temp->next->id);
		else
			printf("(next ID) [X]: || ");
		if (temp->prev)
			printf("(prev ID) [%u]:\n", temp->prev->id);
		else
			printf("(prev ID) [X]:\n");
		temp = temp->next;
		index += 1;
	}
}

int	main(int argc, char *argv[])
{
	t_data	data;

	if (!initiate_data(&data, argc, argv))
		return (free_all(&data), EXIT_FAILURE);
	display_philos(&data);
	// if (!initialise_thread(&data))
	// 	return (free_all(&data), EXIT_FAILURE);
	return (free_all(&data), EXIT_SUCCESS);
}
