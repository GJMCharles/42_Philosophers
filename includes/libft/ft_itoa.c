/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grcharle <grcharle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/02 02:51:44 by grcharle          #+#    #+#             */
/*   Updated: 2025/05/17 09:47:12 by grcharle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	get_size(int n)
{
	size_t	len;

	len = 0;
	if (n <= 0)
		len += 1;
	while (n)
	{
		n /= 10;
		len += 1;
	}
	return (len);
}

static char	*fill_pointer(char *ptr, size_t len, int n)
{
	size_t	i;

	i = 0;
	if (n == -2147483648)
	{
		ptr[i++] = '-';
		ptr[i++] = '2';
		n = 147483648;
	}
	if (n < 0)
	{
		ptr[i++] = '-';
		n *= -1;
	}
	while (i < len)
	{
		ptr[(len--) - 1] = (n % 10) + 48;
		n /= 10;
	}
	return (ptr);
}

char	*ft_itoa(int n)
{
	size_t	len;
	char	*ptr;

	len = get_size(n);
	ptr = (char *) ft_calloc(len + 1, sizeof(char));
	if (!ptr)
		return (0);
	ptr = fill_pointer(ptr, len, n);
	return (ptr);
}
