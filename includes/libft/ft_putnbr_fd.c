/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grcharle <grcharle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/02 02:58:07 by grcharle          #+#    #+#             */
/*   Updated: 2025/05/21 01:36:59 by grcharle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	int	get_size(int n)
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

void	ft_putnbr_fd(int n, int fd)
{
	int		i;
	int		size;
	char	nb[11];

	if (n == -2147483648)
	{
		ft_strlcpy(nb, "-2147483648", 12);
		ft_putstr_fd(nb, fd);
		return ;
	}
	i = 0;
	size = get_size(n);
	if (n < 0)
	{
		nb[i] = '-';
		n *= -1;
		i += 1;
	}
	nb[size] = '\0';
	while (i < size--)
	{
		nb[size] = (n % 10) + 48;
		n /= 10;
	}
	ft_putstr_fd(nb, fd);
}
