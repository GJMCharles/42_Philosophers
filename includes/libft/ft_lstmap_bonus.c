/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grcharle <grcharle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/30 12:02:48 by grcharle          #+#    #+#             */
/*   Updated: 2025/08/26 14:32:08 by grcharle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*result;
	void	*content;
	t_list	*tmp;

	result = (t_list *)(void *)0;
	if (!f || !del)
		return (result);
	while (lst)
	{
		content = (*f)(lst->content);
		tmp = ft_lstnew(content);
		if (!tmp)
		{
			(*del)(content);
			ft_lstclear(&result, del);
			return ((t_list *)(void *)0);
		}
		ft_lstadd_back(&result, tmp);
		lst = lst->next;
	}
	return (result);
}
