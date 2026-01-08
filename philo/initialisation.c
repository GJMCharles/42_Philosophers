/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialisation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grcharle </var/spool/mail/grcharle>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/07 22:48:58 by grcharle          #+#    #+#             */
/*   Updated: 2026/01/08 05:25:53 by grcharle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

t_philos	*initiate_philosophers(t_params *params)
{
	t_philos		*philos;
	unsigned int	index;

	philos = (t_philos *) malloc(sizeof(t_philos) * params->nbr_philos);
	if (!philos)
		return ((t_philos *) NULL);
	index = 0;
	while (index < params->nbr_philos)
	{
		philos[index].id = index + 1;
		philos[index].eat_count = 0;
		philos[index].fork = 1;
		philos[index].status = IDLE;
		philos[index].thread = (pthread_t) 0;
		philos[index].params = params;
		index += 1;
	}
	return (philos);
}

t_params	*initiate_parameters(int argc, char *argv[])
{
	t_params	*params;

	params = (t_params *) malloc(sizeof(t_params));
	if (!params)
		return ((t_params *) NULL);
	params->nbr_philos = (unsigned int) ft_atoi(argv[1]);
	params->time_die = (unsigned int) ft_atoi(argv[2]);
	params->time_eat = (unsigned int) ft_atoi(argv[3]);
	params->time_sleep = (unsigned int) ft_atoi(argv[4]);
	if (argc == 6)
		params->limit_nbr_eat = ft_atoi(argv[5]);
	else
		params->limit_nbr_eat = -1;
	return (params);
}

int	initialise_data(t_data *data, int argc, char *argv[])
{
	data->dead_encountered = 0;
	data->huger_fulfilled = 0;
	data->params = (t_params *) NULL;
	data->philos = (t_philos *) NULL;
	if(!verify_data(argc, argv))
		return (0);
	data->params = initiate_parameters(argc, argv);
	if (!data->params)
		return (0);
	data->philos = initiate_philosophers(data->params);
	if (!data->philos)
		return (0);
	return (1);
}

int		verify_data(int argc, char *argv[])
{
	int index;
	int	value;
	int	j;

	if (argc < 5 || argc > 6)
		return (0);
	index = 1;
	while (index < argc)
	{
		j = 0;
		while (argv[index][j])
		{
			if (!ft_isdigit(argv[index][j]))
				return (0);
			j += 1;
		}
		value = ft_atoi(argv[index]);
		if (!value || value < 0)
			return (0);
		index += 1;
	}
	return (1);
}
