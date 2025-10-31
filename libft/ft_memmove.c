/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grcharle <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/06 20:58:57 by grcharle          #+#    #+#             */
/*   Updated: 2025/08/09 21:36:53 by grcharle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>
#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char		*d;
	const unsigned char	*s;
	size_t				i;

	d = dest;
	s = src;
	i = 0;
	if (d == s || n == 0)
		return (dest);
	if (d < s)
	{
		ft_memcpy(dest, src, n);
	}
	else
	{
		i = n;
		while (i)
		{
			d[i - 1] = s[i - 1];
			i--;
		}
	}
	return (dest);
}
/*
int main()
{
	char s[] = "hello world";
	char s2[50];
	ft_memmove(s + 2, s , 5);
	printf("%s\n", s2);
	char d[] = "hello world";
	char d2[50];
        memmove(d2, s, 5);
        printf("%s", d2);

}
*/
