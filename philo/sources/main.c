/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grcharle <grcharle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/05 17:10:25 by grcharle          #+#    #+#             */
/*   Updated: 2026/02/05 17:10:38 by grcharle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	display_message(const char *message, int fd)
{
	char	nl;

	nl = '\n';
	if (fd == STDOUT_FILENO)
	{
		ft_putstr_fd(message, fd);
		write(fd, &nl, 1);
	}
	else if (fd == STDERR_FILENO)
	{
		ft_putstr_fd("Error :", fd);
		ft_putstr_fd(message, fd);
		write(fd, &nl, 1);
	}
}

int	main(int argc, char *argv[])
{
	t_data	data;

	data.params = (t_pm *) NULL;
	data.philos = (t_ph *) NULL;
	if (!init_data(argc, argv, &data))
		return (clear_data(&data), EXIT_FAILURE);
	if (!init_mutex_parameters(&data))
		return (clear_data(&data), EXIT_FAILURE);
	if (!init_mutex_philosophers(&data))
		return (clear_data(&data), EXIT_FAILURE);
	start_simulation(&data);
	destroy_pthreads_philos(&data);
	destroy_pthreads_parameters(&data, 0);
	clear_data(&data);
	return (EXIT_SUCCESS);
}
