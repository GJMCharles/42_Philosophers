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

// number_of_philosophers
// time_to_die
// time_to_eat
// time_to_sleep
// number_of_times_each_philosopher_must_eat

int	verify_arguments(int nb_args, char *args[])
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

int	main(int argc, char *argv[])
{
	t_data	philo;

	if (argc < 5 || argc > 6)
		return (1);
	if (!verify_arguments(argc, argv))
		return (1);
	philo.nb_philos = argv[1];
	philo.t_die = argv[2];
	philo.t_eat = argv[3];
	philo.t_sleep = argv[4];
	if (argc == 6)
		philo.nb_t_eat = argv[5];
	initiate_thread(&philo);
	exit_thread(&philo);
	return (0);
}
