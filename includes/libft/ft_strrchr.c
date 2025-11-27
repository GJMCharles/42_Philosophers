/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grcharle <grcharle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/30 13:09:57 by grcharle          #+#    #+#             */
/*   Updated: 2025/05/15 05:35:52 by grcharle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	size_t	i;

	i = ft_strlen(s);
	while (i)
	{
		if ((unsigned char)s[i] == (unsigned char)c)
			break ;
		i -= 1;
	}
	if (c == 0 || (unsigned char)s[i] == (unsigned char)c)
		return ((char *)(s + i));
	return (0);
}
