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

void	free_data(t_data **data)
{
	t_data	*temp;

	if (!(*data))
		return ;
	temp = *data;
	if (temp->philo != (t_philo *) NULL)
	{
		free(temp->philo);
		temp->philo = (t_philo *) NULL;
	}
	if (temp->param != (t_param *) NULL)
	{
		if (temp->param->array_eat_count != NULL)
			free(temp->param->array_eat_count);
		if (temp->param->forks != (pthread_mutex_t *) NULL)
			free(temp->param->forks);
		free(temp->param);
		temp->param = (t_param *) NULL;
	}
	free(temp);
	temp = (t_data *) NULL;
}

t_philo	*init_philosophers(t_param *param)
{
	t_philo			*philo;
	unsigned int	index;

	philo = (t_philo *) ft_calloc(sizeof(t_philo), param->nb_philos + 1);
	if (!philo)
		return ((t_philo *) NULL);
	index = 0;
	while (index < param->nb_philos)
	{
		philo[index].id = index;
		philo[index].is_dead = FALSE;
		philo[index].last_eaten = 0;
		philo[index].param = param;
		philo[index].thread = (pthread_t) 0;
		philo[index].left_fork = (pthread_mutex_t *) 0;
		philo[index].right_fork = (pthread_mutex_t *) 0;
		index += 1;
	}
	return (philo);
}

void	init_array_integer(unsigned int **arr, unsigned int max)
{
	unsigned int	*ptr;
	unsigned int	index;

	ptr = *arr;
	index = 0;
	while (index < max)
	{
		ptr[index] = 0;
		index += 1;
	}
}

t_param	*init_parameters(int argc, char *argv[])
{
	t_param			*param;

	param = (t_param *) ft_calloc(sizeof(t_param), 1);
	if (!param)
		return ((t_param *) NULL);
	param->forks = (pthread_mutex_t *) ft_calloc(\
		sizeof(pthread_mutex_t), (unsigned long int)(ft_atoi(argv[1]) + 1));
	if (!param->forks)
		return (free(param), (t_param *) NULL);
	param->nb_philos = (unsigned int)ft_atoi(argv[1]);
	param->array_eat_count = (unsigned int *) ft_calloc(\
		sizeof(unsigned int), param->nb_philos);
	if (!param->array_eat_count)
		return (free(param->forks), free(param), (t_param *) NULL);
	init_array_integer(&param->array_eat_count, param->nb_philos);
	param->time_to_die = (unsigned int)ft_atoi(argv[2]);
	param->time_to_eat = (unsigned int)ft_atoi(argv[3]);
	param->time_to_sleep = (unsigned int)ft_atoi(argv[4]);
	param->eating_limits = -1;
	if (argc == 6)
		param->eating_limits = ft_atoi(argv[5]);
	param->start_timestamp = 0;
	param->minimum_eaten = 0;
	param->abort_simulation = FALSE;
	return (param);
}

t_data	*build_data(int argc, char *argv[])
{
	t_data			*new_data;

	new_data = (t_data *) ft_calloc(sizeof(t_data), 1);
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
