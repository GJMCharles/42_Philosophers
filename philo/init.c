/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grcharle <grcharle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/08 08:40:33 by grcharle          #+#    #+#             */
/*   Updated: 2026/01/08 08:40:45 by grcharle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

t_philo		*initialise_philosophers(t_param *param)
{
	unsigned int	index;
	t_philo			*list;
	t_philo			*new_philo;

	index = 0;
	list = (t_philo *) NULL;
	while (index++ < param->nb_philos)
	{
		new_philo = new_philosopher(index);
		if (!new_philo)
			return (clear_philosophers(&list), (t_philo *) NULL);
		add_philosopher(new_philo, &list);
	}
	return (list);
}

t_param		*initialise_parameters(int argc, char *argv[])
{
	t_param	*params;

	params = (t_param *) malloc(sizeof(t_param));
	if (!params)
		return ((t_param *) NULL);
	params->nb_philos = (unsigned int) ft_atoi(argv[1]);
	params->time_to_die = (unsigned int) ft_atoi(argv[2]);
	params->time_to_eat = (unsigned int) ft_atoi(argv[3]);
	params->time_to_sleep = (unsigned int) ft_atoi(argv[4]);
	if (argc == 6)
		params->eating_limits = ft_atoi(argv[5]);
	else
		params->eating_limits = -1;
	return (params);
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

int	initiate_data(t_data *data, int argc, char *argv[])
{
	data->death_encountered = 0;
	data->huger_fulfilled = 0;
	data->param = (t_param *) NULL;
	data->philo = (t_philo *) NULL;
	if(!verify_data(argc, argv))
		return (0);
	data->param = initialise_parameters(argc, argv);
	if (!data->param)
		return (0);
	data->philo = initialise_philosophers(data->param);
	if (!data->philo)
		return (0);
	return (1);
}
