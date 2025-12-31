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
	t_philo	*philo;

	philo = (t_philo *) arg;
	printf("CUSTOM FUNCTION: {%d}\n", philo->id);
	free(philo);
	return (NULL);
}

int	create_threads(t_data *data)
{
	(void) data;
	return (TRUE);
}

int	initialize_philosophers(t_data *data)
{
	unsigned int	index;

	if (!data || !data->param)
		return (FALSE);
	data->philo = (t_philo *) malloc(sizeof(t_philo) * data->param->nb_philos);
	if (!data->philo)
		return (FALSE);
	index = 0;
	while (index < data->param->nb_philos)
	{
		data->philo[index].id = (index + 1);
		// if (!pthread_create(&(data->philo[index].thread), NULL,\
		// 	philosopher_actions, NULL))
		// {
		// 	printf("pthread_create: %lu\n", data->philo[index].thread);
		// 	return (FALSE);
		// }
		// if (!pthread_join(data->philo[index].thread, NULL))
		// {
		// 	printf("pthread_join\n");
		// 	return (FALSE);
		// }
		index += 1;
	}
	return (TRUE);
}

void	clear_data(t_data *data)
{
	if (data->philo)
	{
		free(data->philo);
	}
	if (data->param)
	{
		free(data->param);
	}
}

int	set_data(t_data *data, int argc, char **argv)
{
	data->param = (struct s_param *) NULL;
	data->philo = (struct s_philo *) NULL;
	if (!initialize_parameters(data, argc, argv))
		return (clear_data(data), FALSE);
	if (!initialize_philosophers(data))
		return (clear_data(data), FALSE);
	return (TRUE);
}

int	main(int argc, char *argv[])
{
	t_data	data;

	if (!validate_parameters(argc, argv) || \
		!set_data(&data, argc, argv) || \
		!create_threads(&data))
		return (EXIT_FAILURE);
	clear_data(&data);
	return (EXIT_SUCCESS);

	// pthread_t	thread1;
	// printf("Before Thread\n");
	// pthread_create(&thread1, NULL, philosopher_actions, NULL);
	// pthread_join(thread1, NULL);
	// printf("After Thread\n");
	// exit(0);
}
