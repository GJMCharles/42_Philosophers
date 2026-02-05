/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grcharle <grcharle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/13 20:30:09 by grcharle          #+#    #+#             */
/*   Updated: 2026/01/13 20:30:58 by grcharle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	display_error(const char *message)
{
	(void) printf("Error: %s\n", message);
}

int	main(int argc, char *argv[])
{
	t_data	*data;

	if (validate_arguments(argc, argv) == FALSE)
		return (display_error(ERROR_01), EXIT_FAILURE);
	data = build_data(argc, argv);
	if (!data)
		return (display_error(ERROR_02), EXIT_FAILURE);
	if (!init_pthreads(&data))
		return (free_data(&data), display_error(ERROR_02), EXIT_FAILURE);
	start_simulation(&data);
	destroy_forks_pthreads(&data, 0);
	destroy_param_pthreads(&data, 0);
	free_data(&data);
	return (EXIT_SUCCESS);
}
