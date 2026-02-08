/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grcharle <grcharle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/05 17:57:25 by grcharle          #+#    #+#             */
/*   Updated: 2026/02/05 17:57:31 by grcharle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*ft_calloc(long int nmemb, long int size)
{
	size_t	lnmemb;
	size_t	lsize;
	void	*alloc;

	lnmemb = (size_t) nmemb;
	lsize = (size_t) size;
	if (nmemb <= 0 || size <= 0)
		return (0);
	if (INT_MAX < lnmemb || INT_MAX < lsize)
		return (0);
	alloc = malloc(lsize * lnmemb);
	if (!alloc)
		return (0);
	(void) memset(alloc, '\0', lsize * lnmemb);
	return (alloc);
}
