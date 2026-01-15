/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grcharle </var/spool/mail/grcharle>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/13 20:30:09 by grcharle          #+#    #+#             */
/*   Updated: 2026/01/13 20:30:58 by grcharle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	print_error_message(const char *message)
{
	ft_putendl_fd((char *) message, STDERR_FILENO);
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

int	main(int argc, char *argv[])
{
	t_data	*data;

	data = (t_data *) NULL;
	if (!verify_arguments(argc, argv))
		return (print_error_message("Error: Invalid arguments"), EXIT_FAILURE);
	if (!init_data(argc, argv, &data))
		return (print_error_message("Error: Failed init"), EXIT_FAILURE);
	init_pthread_mutex(&data);
	start_simulation(&data);
	destroy_pthread_mutex(&data);
	free_all(&data);
	return (EXIT_SUCCESS);
}
