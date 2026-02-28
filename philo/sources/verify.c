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
 * t_ui	get_int_size(long long int n)
 */
t_ui	get_int_size(long long int n)
{
	int	count;

	count = 0;
	if (n == 0)
		return (1);
	if (n < 0)
	{
		count += 1;
		n *= -1;
	}
	while (n > 0)
	{
		n /= 10;
		count += 1;
	}
	return (count);
}

/**
 * bool	verify_parameters(int argc, char *argv[]);
 */
bool	verify_parameters(int argc, char *argv[])
{
	int			index;
	long int	value;
	t_ui		j;

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
			if (!(argv[index][j] >= 48 && argv[index][j] <= 57))
				return (false);
			j += 1;
		}
		index += 1;
	}
	return (true);
}
