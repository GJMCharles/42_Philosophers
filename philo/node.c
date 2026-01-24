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

// void	display_philosophers(t_philo *philo)
// {
// 	t_philo		*first;

// 	first = philo;
// 	while (philo != (t_philo *) NULL)
// 	{
// 		printf("ID [%u]: || ", philo->id);
// 		if (philo->prev)
// 			printf("(prev ID) [%u]: || ", philo->prev->id);
// 		else
// 			printf("(prev ID) [X]: || ");
// 		if (philo->next)
// 			printf("(next ID) [%u]: \n", philo->next->id);
// 		else
// 			printf("(next ID) [X]: \n");
// 		philo = philo->next;
// 		if (first == philo)
// 			break ;
// 	}
// }

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

t_philo	*new_philosopher(unsigned int index)
{
	t_philo		*node;

	node = (t_philo *)malloc(sizeof(t_philo));
	if (!node)
		return ((t_philo *) NULL);
	node->id = index;
	node->status = IDLE;
	node->thread = (pthread_t) NULL;
	node->param = (t_param *) NULL;
	node->next = (t_philo *) NULL;
	node->last_eaten = 0;
	node->eating_counter = 0;
	return (node);
}
