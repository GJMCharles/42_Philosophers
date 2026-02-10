/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verify.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grcharle <grcharle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/09 11:21:57 by grcharle          #+#    #+#             */
/*   Updated: 2026/02/09 11:22:00 by grcharle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

/**
 * 
 */
bool	verify_parameters(int argc, char *argv[])
{
	int			index;
	long int	value;
	ui			j;

	if (argc < 5 || argc > 6)
		return (false);
	index = 1;
	while (index < argc)
	{
		value = ft_atol(argv[index]);
		if (!value || value < 0)
			return (false);
		j = 0;
		while (argv[index][j] != '\0')
		{
			if (!ft_isdigit(argv[index][j]))
				return (false);
			j += 1;
		}
		index += 1;
	}
	return (true);
}
