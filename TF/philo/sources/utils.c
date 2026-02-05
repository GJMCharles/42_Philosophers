/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grcharle <grcharle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/23 05:49:05 by grcharle          #+#    #+#             */
/*   Updated: 2026/01/23 05:49:21 by grcharle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

unsigned long int	get_current_timestamp(void)
{
	struct timeval	time;

	if (gettimeofday(&time, NULL) == -1)
		display_error(ERROR_03);
	return ((time.tv_sec * 1000) + (time.tv_usec / 1000));
}

int	ft_usleep(unsigned long int milliseconds)
{
	unsigned long int	start;

	start = get_current_timestamp();
	while ((get_current_timestamp() - start) < milliseconds)
		usleep(100);
	return (0);
}

void	*ft_calloc(size_t nmemb, size_t size)
{
	void		*alloc;
	long int	lnmemb;
	long int	lsize;

	lnmemb = (long int) nmemb;
	lsize = (long int) size;
	if (lnmemb < 0 || lsize < 0)
		return (0);
	if (INT_MAX < size)
		return (0);
	alloc = malloc(size * nmemb);
	if (!alloc)
		return (0);
	(void) memset(alloc, '\0', size * nmemb);
	return (alloc);
}

/*
'0' = 48
'9' = 57
*/
int	ft_isdigit(int c)
{
	return (c >= 48 && c <= 57);
}

int	ft_atoi(const char *nptr)
{
	unsigned int	i;
	int				nb;
	int				neg;

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
