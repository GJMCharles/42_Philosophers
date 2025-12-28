/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grcharle <grcharle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/12 00:18:04 by grcharle          #+#    #+#             */
/*   Updated: 2025/12/12 00:18:06 by grcharle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*philosopher_actions(void *arg)
{
	(void) arg;
	printf("CUSTOM FUNCTION");
	return (NULL);
}

int	create_threads(t_data *data)
{
	(void) data;
	// index = 0;
	// while (index < data->param->nb_philos)
	// {
	// 	data->philo[index].
	// 	index += 1;
	// }
	return (TRUE);
}

void	clear_node(t_philo **node)
{
	// t_philo *next;
	(void) *node;
	// if (*node != NULL)
	// 	free(*node);
}

int	initialize_philosophers(t_data *data)
{
	// unsigned int	index;
	// t_philo			*node;
	// t_philo			*prev;
	// t_philo			*first;

	if (!data || !data->param)
		return (FALSE);
	// index = 0;
	// prev = (t_philo *) NULL;
	// first = (t_philo *) NULL;
	// while(index < data->param->nb_philos)
	// {
	// 	node = (t_philo *) malloc(sizeof(t_philo));
	// 	if (!node)
	// 		return (clear_node(&node), FALSE);
	// 	node->next = first;
	// 	node->prev = prev;
	// 	if (index == 0)
	// 		first = node;
	// 	prev = node;
	// 	index += 1;
	// }
	// data->philo = (t_philo *) malloc(sizeof(t_philo) * data->param->nb_philos);
	// if (!data->philo)
	// 	return (FALSE);
	//
	return (TRUE);
}

int	initialize_parameters(t_data *data, int argc, char *argv[])
{
	data->param = (t_param *) malloc(sizeof(t_param));
	if (!data->param)
		return (FALSE);
	data->param->nb_philos = (unsigned int) ft_atoi(argv[1]);
	data->param->time_to_die = (unsigned int) ft_atoi(argv[2]);
	data->param->time_to_eat = (unsigned int) ft_atoi(argv[3]);
	data->param->time_to_sleep = (unsigned int) ft_atoi(argv[4]);
	data->param->time_to_eat_count = 0;
	if (argc == 6)
		data->param->time_to_eat_count = (unsigned int) ft_atoi(argv[5]);
	data->param->death_encountered = (unsigned int) FALSE;
	// ..
	return (TRUE);
}

void	clear_data(t_data *data)
{
	if (data->param)
		free(data->param);
	if (data->philo)
		free(data->philo);
}

int	set_data(t_data *data, int argc, char *argv[])
{
	data->param = (struct s_param *) NULL;
	data->philo = (struct s_philo *) NULL;
	if (!initialize_parameters(data, argc, argv))
		return (clear_data(data), 0);
	if (!initialize_philosophers(data))
		return (clear_data(data), 0);
	return (TRUE);
}

int	validate_parameters(int argc, char *argv[])
{
	int	i;
	int	j;
	int	value;

	if (argc < 5 || argc > 6)
		return (FALSE);
	i = 1;
	while (i < argc)
	{
		j = 0;
		if (argv[i][j] == '\0')
			return (0);
		while (argv[i][j] != '\0')
		{
			if (!ft_isdigit(argv[i][j]))
				return (0);
			j += 1;
		}
		value = ft_atoi(argv[i]);
		if (!value || value < 1)
			return (0);
		i += 1;
	}
	return (TRUE);
}

int	main(int argc, char *argv[])
{
	t_data	data;

	if (!validate_parameters(argc, argv))
		return (EXIT_FAILURE);
	if (!set_data(&data, argc, argv))
		return (EXIT_FAILURE);
	if (create_threads(&data))
		clear_data(&data);
	clear_data(&data);
	return (EXIT_SUCCESS);

	pthread_t	thread1;
	printf("Before Thread\n");
	pthread_create(&thread1, NULL, philosopher_actions, NULL);
	pthread_join(thread1, NULL);
	printf("After Thread\n");
	exit(0);
}
