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

int	set_parameters(t_data *data, int argc, char *argv[])
{
	data->param = (t_param *) malloc(sizeof(t_param));
	if (!data->param)
		return (FALSE);
	data->param->num_philos = ft_atoi(argv[1]);
	data->param->time_to_die = (unsigned int) ft_atoi(argv[2]);
	data->param->time_to_eat = (unsigned int) ft_atoi(argv[3]);
	data->param->time_to_sleep = (unsigned int) ft_atoi(argv[4]);
	data->param->time_to_eat_count = 0;
	if (argc == 6)
		data->param->time_to_eat_count = (unsigned int) ft_atoi(argv[5]);
	data->param->death_encountered = FALSE;
	return (TRUE);
}

int	set_philosophers(t_data *data)
{
	if (!data || !data->param)
		return (FALSE);
	data->philo = (t_philo *) malloc(sizeof(t_philo) * data->param->num_philos);
	if (!data->philo)
		return (FALSE);
	//
	return (TRUE);
}

void	clear_data(t_data *data)
{
	if (data->param)
		free(data->param);
	if (data->philo)
		free(data->philo);
}

int	initiate_data(t_data *data, int argc, char *argv[])
{
	data->param = (struct s_param *) NULL;
	data->philo = (struct s_philo *) NULL;
	if (!set_parameters(data, argc, argv))
		return (clear_data(data), 0);
	if (!set_philosophers(data))
		return (clear_data(data), 0);
	return (TRUE);

	// if (argv[5] != NULL)
	// 	data->params.nb_time_eat = (unsigned int) ft_atoi(argv[5]);	
	// return (params);
}

// int	initiate_philosophers(t_philo **philos)
// {
// 	retirn
// }

int	main(int argc, char *argv[])
{
	t_data	data;

	if (!validate_parameters(argc, argv))
		return (EXIT_FAILURE);
	if (!initiate_data(&data, argc, argv))
		return (EXIT_FAILURE);
	clear_data(&data);
	return (EXIT_SUCCESS);
	// if (initiate_philosophers(&philos))
	// 	return (EXIT_FAILURE);
	// pthread_t	thread1;

	// printf("Before Thread\n");
	// pthread_create(&thread1, NULL, custom_function, NULL);
	// pthread_join(thread1, NULL);
	// printf("After Thread\n");
	// exit(0);


	// t_data	*data;
	// if (!verify_data(argc, argv) || !build_list(assign_data(argv), &data))
	// 	return (clear_data(&data), EXIT_FAILURE);
	// return (clear_data(&data), EXIT_SUCCESS);
}
