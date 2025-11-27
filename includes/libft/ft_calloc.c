/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grcharle <grcharle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/02 01:49:34 by grcharle          #+#    #+#             */
/*   Updated: 2025/07/30 11:59:36 by grcharle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
// #include "limits.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	void		*alloc;
	long int	lnmemb;
	long int	lsize;
	size_t		i;
	char		*ptr;

	lnmemb = (long int) nmemb;
	lsize = (long int) size;
	if ((lnmemb < 0 && lsize != 0) || (lsize < 0 && lnmemb != 0))
		return (0);
	alloc = malloc(size * nmemb);
	if (!alloc)
		return (0);
	i = 0;
	ptr = (char *)alloc;
	while (i < (size * nmemb))
	{
		ptr[i] = '\0';
		i += 1;
	}
	return (alloc);
}
