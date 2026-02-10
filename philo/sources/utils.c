/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grcharle <grcharle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/05 17:57:25 by grcharle          #+#    #+#             */
/*   Updated: 2026/02/10 13:51:06 by grcharle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_putstr_fd(const char *s, int fd)
{
	ui	index;

	index = 0;
	while (s[index] != '\0')
	{
		(void) write(fd, &s[index], sizeof(s[index]));
		index += 1;
	}
}

/**
 * '0' = 48
 * '9' = 57
 */
int	ft_isdigit(int c)
{
	return (c >= 48 && c <= 57);
}

/**
 * 
 */
long int	ft_atol(const char *nptr)
{
	ui			i;
	long int	nb;
	long int	neg;

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
		if (INT_MAX < ((nb * 10) + (nptr[i] - 48)))
			return (0);
		nb = (nb * 10) + (nptr[i] - 48);
		i += 1;
	}
	return (nb * neg);
}

/**
 * 
 */
void	*ft_calloc(long int nmemb, long int size)
{
	size_t	lnmemb;
	size_t	lsize;
	void	*alloc;

	lnmemb = (size_t) nmemb;
	lsize = (size_t) size;
	if (nmemb <= 0 || size <= 0)
		return (0);
	if (INT_MAX < lnmemb || INT_MAX < lsize)
		return (0);
	alloc = malloc(lsize * lnmemb);
	if (!alloc)
		return (0);
	(void) memset(alloc, '\0', lsize * lnmemb);
	return (alloc);
}
