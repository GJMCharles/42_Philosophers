/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grcharle <grcharle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/02 02:48:37 by grcharle          #+#    #+#             */
/*   Updated: 2025/08/02 16:01:40 by grcharle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*str_join;
	int		s1_len;
	int		s2_len;

	if (!s1 && !s2)
		return (0);
	s1_len = ft_strlen(s1);
	s2_len = ft_strlen(s2);
	str_join = (char *) ft_calloc((s1_len + s2_len + 1), sizeof(char));
	if (!str_join)
		return (0);
	ft_strlcpy(str_join, s1, s1_len + 1);
	ft_strlcpy(str_join + s1_len, s2, s2_len + 1);
	return (str_join);
}
