/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grcharle <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/07 15:23:51 by grcharle          #+#    #+#             */
/*   Updated: 2025/08/07 17:52:25 by grcharle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	dst_len;
	size_t	src_len;
	size_t	i;

	i = 0;
	dst_len = 0;
	src_len = 0;
	while (src[src_len])
		src_len++;
	while (dst[dst_len] && dst_len < size)
		dst_len++;
	if (dst_len >= size)
		return (size + src_len);
	while (src[i] && i + dst_len + 1 < size)
	{
		dst[dst_len + i] = src[i];
		i++;
	}
	if (dst_len + 1 < size)
		dst[dst_len + i] = '\0';
	return (dst_len + src_len);
}
/*
int	main(void)
{
	char src[] = "khaled";
	char dst[10] = " haj";
	printf("%zu\n", ft_strlcat(dst,src, 1));
	printf("%s\n", dst);
        char src1[] = "khaled";
        char dst1[10] = " haj";
        printf("%zu\n", strlcat(dst1,src1, 1));
	printf("%s", dst1);
	return (0);
}
*/
