/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grcharle <grcharle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/13 20:33:34 by grcharle          #+#    #+#             */
/*   Updated: 2026/01/23 23:55:00 by grcharle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

t_philo	*init_philosophers(t_param *param)
{
	t_philo			*philo;
	unsigned int	index;

	philo = (t_philo *)malloc(sizeof(t_philo) * param->nb_philos);
	if (!philo)
		return (t_philo *) NULL;
	index = 0;
	while (index < param->nb_philos)
	{
		philo[index].id = (index + 1);
		philo[index].status = IDLE;
		philo[index].thread = (pthread_t) NULL;
		philo[index].param = param;
		philo[index].last_eaten = 0;
		philo[index].eat_counter = 0;
		philo[index].has_died = 0;
		philo[index].fork = (pthread_mutex_t){};
		index += 1;
	}
	return (philo);
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
	param->setup_count = 0;
	param->stop_simulation = 0;
	param->start_timestamp = 0;
	return (param);
}

t_data	*build_data(int argc, char *argv[])
{
	t_data	*new_data;

	new_data = (t_data *)malloc(sizeof(t_data));
	if (!new_data)
		return ((t_data *) NULL);
	new_data->param = init_parameters(argc, argv);
	if (!new_data->param)
	{
		free_data(&new_data);
		return (new_data);
	}
	new_data->philo = init_philosophers(new_data->param);
	if (!new_data->philo)
		free_data(&new_data);
	return (new_data);
}
