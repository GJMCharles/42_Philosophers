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

void	*custom_function(void *vargp)
{
	(void) vargp;
	sleep(1);
	printf("TEST CODE 1 2 3\n");
	return (NULL);
}

int	validate_parameters(int argc, char *argv[])
{
	int	index;
	int	value;

	if (argc < 5 || argc > 6)
		return (0);
	index = 0;
	while (++index < argc)
	{
		value = ft_atoi(argv[index]);
		if (!value || value < 1)
			return (0);
	}
	return (1);
}

t_params	initiate_params(char *argv[])
{
	t_params	params;

	params.nb_philos = (unsigned int) ft_atoi(argv[1]);
	params.time_die = (unsigned int) ft_atoi(argv[2]);
	params.time_eat = (unsigned int) ft_atoi(argv[3]);
	params.time_sleep = (unsigned int) ft_atoi(argv[4]);
	params.nb_time_eat = 0;
	if (argv[5] != NULL)
		params.nb_time_eat = (unsigned int) ft_atoi(argv[5]);	
	return (params);
}

int	initiate_philosophers(t_philo **philos)
{
	//
}

int	main(int argc, char *argv[])
{
	t_params params;
	t_philo	*philos;

	if (!validate_parameters(argc, argv))
		return (EXIT_FAILURE);
	params = initiate_params(argv);
	if (initiate_philosophers(&philos))
		return (EXIT_FAILURE);
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
