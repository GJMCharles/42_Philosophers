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

// void	display_message(const char *message, int type)
// {
// 	if (type == 0)
// 	{
// 		//ft_putstr(message, STDOUT_FILENO);
// 		write(STDOUT_FILENO, "\n", 2);
// 	}
// 	else if (type == 1)
// 	{
// 		write(STDERR_FILENO, "Error :", 8);
// 		//ft_putstr(message, STDERR_FILENO);
// 		write(STDERR_FILENO, "\n", 2);
// 	}
// }

int	main(int argc, char *argv[])
{
	(void) argc;
	(void) argv;
	t_data	data;

// 	if (!init_data(argc, argv, &data))
// 		return (clear_data(&data), EXIT_FAILURE);
// 	if (!init_pthreads(&data))
// 		return (clear_data(&data), EXIT_FAILURE);
// 	start_simulation(&data);
	clear_data(&data);
	return (EXIT_SUCCESS);
}
