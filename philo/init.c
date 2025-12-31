/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grcharle <grcharle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/30 05:49:23 by grcharle          #+#    #+#             */
/*   Updated: 2025/12/30 05:49:25 by grcharle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	fill_philosopher_node(t_philo **philo, t_philo *node, unsigned int i)
{
	t_philo			*first;
	t_philo			*prev;

	first = (t_philo *) NULL;
	prev = (t_philo *) NULL;
	add_back_philo_list(philo, node);
	node->id = (i + 1);
}

int	initialize_philosophers(t_data *data)
{
	unsigned int	index;
	unsigned int	max_philos;
	t_philo			*current_node;

	index = 0;
	max_philos = data->param->nb_philos;
	while (index < max_philos)
	{
		current_node = (t_philo *) malloc(sizeof(t_philo));
		if (!current_node)
			return (clear_philo_list(&data->philo), FALSE);
		fill_philosopher_node(&data->philo, current_node, index);
		
		// current_node->id = (index + 1);
		// current_node->next = (t_philo *) NULL;
		// current_node->prev = prev;
		
		// if ((index + 1) == max_philos && max_philos > 1)
		// {
		// 	current_node->next = first;
		// 	first->prev = current_node;
		// }
		// else if (index == 0 && max_philos > 1)
		// 	first = current_node;
		// prev = current_node;
		index += 1;
	}
	return (TRUE);
}

int	initialize_parameters(int argc, char **argv, t_data *data)
{
	data->param = (t_param *) malloc(sizeof(t_param));
	if (!data->param)
		return (FALSE);
	data->param->nb_philos = (unsigned int) ft_atoi(argv[1]);
	data->param->time_to_eat = (unsigned int) ft_atoi(argv[3]);
	data->param->time_to_sleep = (unsigned int) ft_atoi(argv[4]);
	data->param->time_to_die = (unsigned int) ft_atoi(argv[2]);
	data->param->count_eating_limits = -1;
	if (argc == 6)
		data->param->count_eating_limits = (unsigned int) ft_atoi(argv[5]);
	data->param->death_encountered = FALSE;
	return (TRUE);
}

int	set_data(int argc, char **argv, t_data *data)
{
	data->param = (t_param *) NULL;
	data->philo = (t_philo *) NULL;
	if (!initialize_parameters(argc, argv, data))
		return (FALSE);
	if (!initialize_philosophers(data))
		return (FALSE);
	return (TRUE);
}
