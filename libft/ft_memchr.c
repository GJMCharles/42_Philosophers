/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grcharle <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/09 17:06:05 by grcharle          #+#    #+#             */
/*   Updated: 2025/08/09 18:23:42 by grcharle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>
#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	int					i;
	const unsigned char	*ptr;

	ptr = s;
	i = 0;
	while (n--)
	{
		if (ptr[i] == (unsigned char)c)
			return ((void *)(s + i));
		i++;
	}
	return (NULL);
}
/*
int main ()
{
	char s[] = "khaled";
	char c = 0;
	char *find = ft_memchr(s, c, 1);
	char *find2 = memchr(s, c, 1);
	printf("%s\n", find);
        printf("%s\n", find2);
	return (0);
}
*/
