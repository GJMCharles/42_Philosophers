/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grcharle <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/06 17:58:28 by grcharle          #+#    #+#             */
/*   Updated: 2025/08/12 21:37:54 by grcharle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	int					i;
	unsigned char		*dst;
	const unsigned char	*source;

	dst = dest;
	source = src;
	i = 0;
	if (!dest && !src)
		return (NULL);
	while (n--)
	{
		dst[i] = source[i];
		i++;
	}
	return (dest);
}

/*
int main()
{
	char s[] =  "khaled";
	char d[4];

	ft_memcpy(d, s, 7);
	printf("%s", d);
}
*/
