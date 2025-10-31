/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putptr_printf.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grcharle <grcharle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/19 21:11:47 by grcharle          #+#    #+#             */
/*   Updated: 2025/08/21 18:12:24 by grcharle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static unsigned int	length(unsigned long n)
{
	int	len;

	len = 0;
	if (n == 0)
		len = 1;
	while (n)
	{
		n = n / 16;
		len++;
	}
	return (len);
}

int	ft_putptr_printf(unsigned long n)
{
	if (!n)
		return (ft_putstr_printf("(nil)"));
	ft_putstr_printf("0x");
	ft_puthex_printf(n, 0);
	return (length(n) + 2);
}
