/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grcharle </var/spool/mail/grcharle>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/11 12:06:06 by grcharle          #+#    #+#             */
/*   Updated: 2025/11/11 12:06:50 by grcharle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

/**
int	verify_data(int nb_args, char *args[])
{
	(void) *args;
	if (nb_args == 6)
	{
		//
	}
	return (1);
}

void	initiate_thread(t_data *data)
{
	//
}

void	exit_thread(t_data *data)
{
	//
}

int	assign_data_list(t_data *philo, char *argv[])
{
	(void) philo;
	(void) *argv;
	return (0);
}
 */

int	verify_data(int argc, char *argv[])
{
	int	index;

	index = 0;
	while (++index < argc)
	{
		printf(argv[index]);
	}
	return (0);
}

int	main(int argc, char *argv[])
{
	// t_data	philo;

	if (argc < 5 || argc > 6)
		return (1);
	if (!verify_data(argc, argv))
		return (1);
	// if (assign_data_list(&philo, argv))
	// 	return (1);
	// philo.nb_philos = argv[1];
	// philo.t_die = argv[2];
	// philo.t_eat = argv[3];
	// philo.t_sleep = argv[4];
	// if (argc == 6)
	// 	philo.nb_t_eat = argv[5];
	// initiate_thread(&philo);
	// exit_thread(&philo);
	return (0);
}
