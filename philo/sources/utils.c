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

/**
 * 
 */
long int	ft_atol(const char *np)
{
	t_ui		i;
	long int	nb;
	long int	neg;

	i = 0;
	nb = 0;
	neg = 1;
	if (!np)
		return (0);
	while (np[i] == ' ' || (np[i] >= 9 && np[i] <= 13))
		i += 1;
	if ((np[i] == '+' || np[i] == '-') && (np[i + 1] >= 48 && np[i + 1] <= 57))
	{
		if (np[i] == '-')
			neg = -1;
		i += 1;
	}
	while (np[i] >= 48 && np[i] <= 57)
	{
		if (INT_MAX < ((nb * 10) + (np[i] - 48)))
			return (0);
		nb = (nb * 10) + (np[i] - 48);
		i += 1;
	}
	return (nb * neg);
}

/**
 * 
 */
void	ft_putnbr(long long int l, int fd)
{
	char	nb[21];
	t_ui	size;
	t_ui	i;

	(void) memset(nb, '\0', 21);
	size = get_int_size(l);
	i = 0;
	if (l < 0)
	{
		nb[i] = '-';
		l *= -1;
		i += 1;
	}
	while (i < size--)
	{
		nb[size] = (char)((l % 10) + 48);
		l /= 10;
	}
	ft_putstr_fd(nb, fd);
}

/**
 * 
 */
void	ft_putstr_fd(const char *s, int fd)
{
	t_ui	index;

	index = 0;
	while (s[index] != '\0')
	{
		(void) write(fd, &s[index], sizeof(s[index]));
		index += 1;
	}
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
