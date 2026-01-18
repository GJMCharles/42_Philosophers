/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grcharle <grcharle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/13 20:33:34 by grcharle          #+#    #+#             */
/*   Updated: 2026/01/13 20:34:46 by grcharle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	free_data(t_data **data)
{
	t_data	*temp;

	if (!(*data))
		return ;
	temp = *data;
	if (temp->philo != (t_philo *) NULL)
		clear_philosophers(&(temp->philo));
	if (temp->param != (t_param *) NULL)
	{
		free(temp->param);
		temp->param = (t_param *) NULL;
	}
	free(temp);
	temp = (t_data *) NULL;
}

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
	param->total_min_eaten = 0;
	param->timestamp_start = 0;
	param->death_encountered = 0;
	return (param);
}

int	verify_arguments(int argc, char *argv[])
{
	int	argi;
	int	i;
	int	value;

	if (argc < 5 || argc > 6)
		return (0);
	argi = 1;
	while (argi < argc)
	{
		value = ft_atoi(argv[argi]);
		if (!value || value < 0)
			return (0);
		i = 0;
		while (argv[argi][i] != '\0')
		{
			if (!ft_isdigit(argv[argi][i]))
				return (0);
			i += 1;
		}
		argi += 1;
	}
	return (1);
}

t_data	*get_data(int argc, char *argv[])
{
	t_data	*new_data;

	if (!verify_arguments(argc, argv))
		return ((t_data *) NULL);
	new_data = (t_data *)malloc(sizeof(t_data));
	if (!new_data)
		return ((t_data *) NULL);
	new_data->param = init_parameters(argc, argv);
	if (!new_data->param)
	{
		free_data(&new_data);
		return ((t_data *) NULL);
	}
	new_data->philo = init_philosophers(new_data->param);
	if (!new_data->philo)
	{
		free_data(&new_data);
		return ((t_data *) NULL);
	}
	return (new_data);
}
