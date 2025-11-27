/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grcharle <grcharle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/02 02:47:43 by grcharle          #+#    #+#             */
/*   Updated: 2025/05/21 13:07:11 by grcharle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char			*sub;
	unsigned int	i;
	unsigned int	j;

	i = 0;
	j = 0;
	if (!s)
		return (0);
	if (start > (unsigned int) ft_strlen(s))
		return ((char *) ft_calloc(1, 1));
	if (len > (unsigned int) ft_strlen(s + start))
		len = ft_strlen(s + start);
	sub = (char *) ft_calloc(len + 1, sizeof(char));
	if (sub == 0)
		return (0);
	while (s[i] != '\0' && i < start)
		i++;
	while (s[i] != '\0' && j < len)
	{
		sub[j] = s[i];
		i++;
		j++;
	}
	sub[j] = '\0';
	return (sub);
}
