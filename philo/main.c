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

int	main(int argc, char *argv[])
{
	t_data	data;

	if (!initialise_data(&data, argc, argv))
		return (free_all(&data), EXIT_FAILURE);
	// if (!manage_threads(&data))
	// 	return (free_all(&data), EXIT_FAILURE);
	// if (!initialise_thread(&data))
	// 	return (free_all(&data), EXIT_FAILURE);
	// if (!execute_thread(&data))
	// 	return (free_all(&data), EXIT_FAILURE);
	// display_philosophers(&data);
	return (free_all(&data), EXIT_SUCCESS);
}
