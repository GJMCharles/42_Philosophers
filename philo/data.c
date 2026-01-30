/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grcharle <grcharle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/13 20:33:34 by grcharle          #+#    #+#             */
/*   Updated: 2026/01/24 13:23:01 by grcharle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

t_philo *init_philosophers(t_param *param)
{
	unsigned int index;
	t_philo *philo_list;
	t_philo *node;

	index = 0;
	philo_list = (t_philo *) NULL;
	while (index++ < param->nb_philos)
	{
		node = new_philosopher();
		if (!node)
			return (clear_philosophers(&philo_list), (t_philo *) NULL);
		node->id = index;
		node->status = IDLE;
		node->thread = (pthread_t) NULL;
		node->last_eaten = 0;
		node->eating_counter = 0;
		node->param = param;
		node->next = (t_philo *) NULL;
		append_philosopher(node, &philo_list);
	}
	return (philo_list);
}

t_param *init_parameters(int argc, char *argv[])
{
	t_param *param;

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
	param->test_count = 0;
	param->start_timestamp = 0;
	param->abort_simulator = FALSE;
	return (param);
}

t_data *build_data(int argc, char *argv[])
{
	t_data *new_data;

	new_data = (t_data *)malloc(sizeof(t_data));
	if (!new_data)
		return ((t_data *) NULL);
	new_data->param = init_parameters(argc, argv);
	if (!new_data->param)
		return (free_data(&new_data), (t_data *) NULL);
	new_data->philo = init_philosophers(new_data->param);
	if (!new_data->philo)
		return (free_data(&new_data), (t_data *) NULL);
	return (new_data);
}
