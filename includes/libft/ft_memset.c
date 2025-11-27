/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grcharle <grcharle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/29 13:24:51 by grcharle          #+#    #+#             */
/*   Updated: 2025/04/30 12:59:15 by grcharle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *s, int c, size_t n)
{
	size_t	i;
	char	*ptr;

	i = 0;
	if (!s || n < 1)
		return ((void *)0);
	ptr = (char *)s;
	while (i < n)
	{
		ptr[i] = c;
		i += 1;
	}
	return (s);
}
