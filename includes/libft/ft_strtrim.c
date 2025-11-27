/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grcharle <grcharle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/02 02:49:50 by grcharle          #+#    #+#             */
/*   Updated: 2025/05/16 21:13:02 by grcharle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	exists_in_set(char c, const char *set)
{
	size_t	i;

	i = 0;
	while (set[i])
	{
		if ((unsigned char)set[i] == (unsigned char)c)
			return (1);
		i += 1;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	first;
	size_t	last;
	size_t	len;
	char	*ptr;

	first = 0;
	last = ft_strlen(s1);
	while (s1[last - 1] && exists_in_set(s1[last - 1], set))
		last -= 1;
	while (s1[first] && exists_in_set(s1[first], set))
		first += 1;
	len = 0;
	if (last > first)
		len = last - first;
	ptr = (char *) ft_calloc(len + 1, sizeof(char));
	if (!ptr)
		return (0);
	(void) ft_strlcpy(ptr, s1 + first, len + 1);
	return (ptr);
}
