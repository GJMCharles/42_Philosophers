/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grcharle <grcharle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/13 20:30:09 by grcharle          #+#    #+#             */
/*   Updated: 2026/01/13 20:30:58 by grcharle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

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

int	main(int argc, char *argv[])
{
	t_data	*data;

	if (!verify_arguments(argc, argv))
		return (EXIT_FAILURE);
	data = build_data(argc, argv);
	if (!data)
		return (EXIT_FAILURE);
	init_pthread_mutex(&data);
	start_simulation(&data);
	destroy_pthread_mutex(&data);
	free_data(&data);
	return (EXIT_SUCCESS);
}
