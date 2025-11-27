/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grcharle <grcharle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/01 23:14:50 by grcharle          #+#    #+#             */
/*   Updated: 2025/05/15 04:08:33 by grcharle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t n)
{
	size_t	i;
	size_t	dest_len;
	size_t	src_len;

	dest_len = ft_strlen(dest);
	src_len = ft_strlen(src);
	if (n <= dest_len)
	{
		return (src_len + n);
	}
	i = 0;
	while ((dest_len + i) < (n - 1) && src[i] != '\0')
	{
		dest[dest_len + i] = src[i];
		i += 1;
	}
	dest[dest_len + i] = '\0';
	return (dest_len + src_len);
}
