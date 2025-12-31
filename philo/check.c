/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grcharle <grcharle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/30 05:38:58 by grcharle          #+#    #+#             */
/*   Updated: 2025/12/30 05:39:00 by grcharle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	validate_parameters(int argc, char **argv)
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
			return (FALSE);
		while (argv[i][j] != '\0')
		{
			if (!ft_isdigit(argv[i][j]))
				return (FALSE);
			j += 1;
		}
		value = ft_atoi(argv[i]);
		if (!value || value < 1)
			return (FALSE);
		i += 1;
	}
	return (TRUE);
}
