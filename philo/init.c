/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grcharle </var/spool/mail/grcharle>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/13 20:33:34 by grcharle          #+#    #+#             */
/*   Updated: 2026/01/13 20:34:46 by grcharle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

t_philo	*init_philosophers(t_param *param)
{
	unsigned int	i;
	t_philo			*philo_list;
	t_philo			*philo_node;

	i = 0;
	philo_list = (t_philo *) NULL;
	while (i < param->nb_philos)
	{
		philo_node = new_philosopher(i + 1);
		if (!philo_node)
			return ((t_philo *) NULL);
		philo_node->param = param;
		append_philosopher(philo_node, &philo_list);
		i += 1;
	}
	return (philo_list);
}

t_param	*init_parameters(int argc, char *argv[])
{
	t_param			*param;

	param = (t_param *)malloc(sizeof(t_param));
	if (!param)
		return ((t_param *) NULL);
	param->nb_philos = (unsigned int)ft_atoi(argv[1]);
	param->time_to_die = (unsigned int)ft_atoi(argv[2]);
	param->time_to_eat = (unsigned int)ft_atoi(argv[3]);
	param->time_to_sleep = (unsigned int)ft_atoi(argv[4]);
	if (argc == 6)
		param->eating_limits = ft_atoi(argv[5]);
	else
		param->eating_limits = -1;
	param->death_encountered = 0;
	param->start_time = 0;
	return (param);
}

int	init_data(int argc, char *argv[], t_data **data)
{
	t_data			*new_data;

	new_data = (t_data *)malloc(sizeof(t_data));
	if (!new_data)
	{
		data = (t_data **) NULL;
		return (0);
	}
	new_data->param = init_parameters(argc, argv);
	if (!new_data->param)
		return (free_all(&new_data), 0);
	new_data->philo = init_philosophers(new_data->param);
	if (!new_data->philo)
		return (free_all(&new_data), 0);
	*data = new_data;
	return (1);
}
