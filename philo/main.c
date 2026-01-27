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
	int	index;
	int	i;
	int	value;

	if (argc < 5 || argc > 6)
		return (1);
	index = 1;
	while (index < argc)
	{
		value = ft_atoi(argv[index]);
		if (!value || value < 0)
			return (1);
		i = 0;
		while (argv[index][i] != '\0')
		{
			if (!ft_isdigit(argv[index][i]))
				return (1);
			i += 1;
		}
		index += 1;
	}
	return (0);
}

int	main(int argc, char *argv[])
{
	t_data	*data;

	if (verify_arguments(argc, argv))
		return (EXIT_FAILURE);
	data = build_data(argc, argv);
	if (!data)
		return (EXIT_FAILURE);
	start_pthreads(&data);
	start_simulators(&data);
	end_pthreads(&data);
	free_data(&data);
	return (EXIT_SUCCESS);
}
