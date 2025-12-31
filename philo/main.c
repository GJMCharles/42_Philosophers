/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grcharle <grcharle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/30 01:30:04 by grcharle          #+#    #+#             */
/*   Updated: 2025/12/30 01:30:21 by grcharle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	display_philos(t_data *data)
{
	t_philo			*temp;
	unsigned int	index;

	index = 0;
	temp = data->philo;
	while (temp && index < 10)
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

	if (!validate_parameters(argc, argv) || \
		!set_data(argc, argv, &data))
		return (EXIT_FAILURE);
	display_philos(&data);
	flush_data(&data);
	return (EXIT_SUCCESS);
}
