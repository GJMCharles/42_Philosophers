/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grcharle <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/07 13:46:09 by grcharle          #+#    #+#             */
/*   Updated: 2025/08/07 15:20:19 by grcharle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	len;

	len = 0;
	i = 0;
	while (src[len])
		len++;
	if (size > 0)
	{
		while (src[i] && i < size - 1)
		{
			dst[i] = src[i];
			i++;
		}
		dst[i] = '\0';
	}
	return (len);
}
/*
int	main(void)
{
	char src[] = "khaled";
	char dst[8];
	printf("%zu\n", ft_strlcpy(dst,src, 9));
	printf("%s\n", dst);
        char src1[] = "khaled";
        char dst1[8];
        printf("%zu\n", strlcpy(dst1,src1, 9));
	printf("%s", dst);
	return (0);
}
*/
