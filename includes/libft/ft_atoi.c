/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grcharle <grcharle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/01 23:12:18 by grcharle          #+#    #+#             */
/*   Updated: 2025/05/02 08:54:59 by grcharle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *nptr)
{
	int	i;
	int	nb;
	int	neg;

	i = 0;
	nb = 0;
	neg = 1;
	if (!nptr)
		return (0);
	while (nptr[i] == ' ' || (nptr[i] >= 9 && nptr[i] <= 13))
		i += 1;
	if ((nptr[i] == '+' || nptr[i] == '-') && ft_isdigit(nptr[i + 1]))
	{
		if (nptr[i] == '-')
			neg = -1;
		i += 1;
	}
	while (ft_isdigit(nptr[i]))
	{
		if (((nb * 10) + (nptr[i] - 48)) > INT_MAX)
			return (0);
		nb = (nb * 10) + (nptr[i] - 48);
		i += 1;
	}
	return (nb * neg);
}
