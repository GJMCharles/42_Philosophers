/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grcharle <grcharle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/29 19:14:17 by grcharle          #+#    #+#             */
/*   Updated: 2025/09/29 22:04:26 by grcharle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char	*tmp_dest;
	unsigned char	*tmp_src;
	size_t			i;

	if (!dest && !src)
		return (0);
	tmp_dest = (unsigned char *)dest;
	tmp_src = (unsigned char *)src;
	i = 0;
	if (tmp_dest > tmp_src)
	{
		while (n--)
			tmp_dest[n] = tmp_src[n];
	}
	else
	{
		while (i < n)
		{
			tmp_dest[i] = tmp_src[i];
			i += 1;
		}
	}
	return (dest);
}
