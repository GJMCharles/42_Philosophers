/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   node.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grcharle <grcharle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/08 09:08:51 by grcharle          #+#    #+#             */
/*   Updated: 2026/01/24 13:48:08 by grcharle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	clear_philosophers(t_philo **list)
{
	t_philo		*first;
	t_philo		*temp;
	t_philo		*next;

	if (!list || !(*list))
		return ;
	next = (t_philo *) NULL;
	first = *list;
	temp = *list;
	while (temp != (t_philo *) NULL)
	{
		next = temp->next;
		free(temp);
		temp = next;
		if (first == next)
			break ;
	}
	*list = (t_philo *) NULL;
}

void	append_philosopher(t_philo *node, t_philo **list)
{
	t_philo		*temp;
	t_philo		*first;

	if (!node)
		return ;
	if (!(*list))
	{
		*list = node;
		return ;
	}
	temp = *list;
	first = *list;
	while (temp->next != (t_philo *) NULL && temp->next != first)
		temp = temp->next;
	node->next = first;
	temp->next = node;
}

t_philo	*new_philosopher(void)
{
	t_philo		*node;

	node = (t_philo *)malloc(sizeof(t_philo));
	if (!node)
		return ((t_philo *) NULL);
	return (node);
}
