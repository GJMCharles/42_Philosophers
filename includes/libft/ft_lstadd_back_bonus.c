/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grcharle <grcharle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/30 12:01:28 by grcharle          #+#    #+#             */
/*   Updated: 2025/08/26 14:29:27 by grcharle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *back_node)
{
	t_list	*tmp;

	if (!back_node)
		return ;
	if (!*lst)
	{
		*lst = back_node;
		return ;
	}
	tmp = *lst;
	while (tmp && tmp->next)
		tmp = tmp->next;
	tmp->next = back_node;
}
