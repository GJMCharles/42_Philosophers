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
*/

void	assign_data_list(t_data **philo, char **argv)
{
	t_data	*temp;

	temp = *philo;
	temp->nb_philos = ft_atoi(argv[1]);
	temp->t_die = ft_atoi(argv[2]);
	temp->t_eat = ft_atoi(argv[3]);
	temp->t_sleep = ft_atoi(argv[4]);
	if (argv[5] != NULL)
		temp->nb_t_eat = ft_atoi(argv[5]);
}

int	verify_data(int argc, char **argv)
{
	int	index;
	int	value;

	index = 0;
	while (++index < argc)
	{
		value = ft_atoi(argv[index]);
		if (!value || value < 0)
			return (0);
	}
	return (1);
}

int	main(int argc, char *argv[])
{
	t_data	*philo;

	if (argc < 5 || argc > 6)
		return (EXIT_FAILURE);
	if (!verify_data(argc, argv))
		return (EXIT_FAILURE);
	philo = (t_data *) malloc(sizeof(t_data));
	if (!philo)
		return (EXIT_FAILURE);
	assign_data_list(&philo, argv);
	free(philo);
	return (EXIT_SUCCESS);
}
