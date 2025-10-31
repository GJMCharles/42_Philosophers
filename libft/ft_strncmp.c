/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grcharle <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/09 16:50:51 by grcharle          #+#    #+#             */
/*   Updated: 2025/08/11 19:22:15 by grcharle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>
#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	int		i;
	size_t	n2;

	n2 = n;
	i = 0;
	while (n && s1[i] == s2[i] && s1[i] && s2[i])
	{
		i++;
		n--;
	}
	if (n2 == 0)
		return (0);
	if (n == 0)
		return ((unsigned char)s1[i - 1] - (unsigned char)s2[i - 1]);
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}
/*
int main()
{
	//char s1[] = "kbaled";
	//char s2[] = "kbjned";
	printf("%d\n", ft_strncmp("abcdefgh", "abcdwxyz", 4));
	printf("%d\n", strncmp("abcdefgh", "abcdwxyz", 4));

	return (0);
}
*/
