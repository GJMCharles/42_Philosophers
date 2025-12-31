/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grcharle <grcharle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/31 04:08:45 by grcharle          #+#    #+#             */
/*   Updated: 2025/12/31 04:08:49 by grcharle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	add_back_philo_list(t_philo **list, t_philo *back_node)
{
	t_philo	*temp;

	if (!back_node)
		return ;
	if (!*list)
	{
		*list = back_node;
		return ;
	}
	temp = *list;
	while (temp && temp->next)
		temp = temp->next;
	temp->next = back_node;
}

void	clear_philo_list(t_philo **list)
{
	t_philo	*first;
	t_philo	*next;

	if (!*list)
		return ;
	first = *list;
	*list = (*list)->next;
	while (*list != first)
	{
		next = (*list)->next;
		free(*list);
		*list = next;
	}
	if (*list)
		free(*list);
	*list = (t_philo *) NULL;
}
