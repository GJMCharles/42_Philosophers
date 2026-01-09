/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grcharle <grcharle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/08 09:08:51 by grcharle          #+#    #+#             */
/*   Updated: 2026/01/08 09:09:00 by grcharle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	display_philosophers(t_data *data)
{
	t_philo			*temp;
	unsigned int	index;

	index = 0;
	temp = data->philo;
	while (temp && index < 15)
	{
		printf("ID [%u]: || ", temp->id);
		if (temp->prev)
			printf("(prev ID) [%u]: || ", temp->prev->id);
		else
			printf("(prev ID) [X]: || ");
		if (temp->next)
			printf("(next ID) [%u]: \n", temp->next->id);
		else
			printf("(next ID) [X]: \n");
		temp = temp->next;
		index += 1;
	}
}

void	add_philosopher(t_philo *new_philo, t_philo **list)
{
	t_philo	*temp;
	t_philo	*first;

	if (!new_philo)
		return ;
	if (!(*list))
	{
		*list = new_philo;
		return ;
	}
	temp = *list;
	first = *list;
	while (temp->next != (t_philo *) NULL && temp->next != first)
		temp = temp->next;
	temp->next = new_philo;
	first->prev = new_philo;
	new_philo->prev = temp;
	new_philo->next = first;
}

void	clear_philosophers(t_philo **list)
{
	t_philo	*temp;
	t_philo	*next;

	if (!(*list))
		return ;
	temp = *list;
	while (temp)
	{
		next = temp->next;
		pthread_mutex_destroy(&(temp->fork));
		free(temp);
		temp = (t_philo *) NULL;
		temp = next;
	}
	*list = (t_philo *) NULL;
}

t_philo	*new_philosopher(unsigned int index)
{
	t_philo	*new_philo;

	new_philo = (t_philo *) malloc(sizeof(t_philo));
	if (!new_philo)
		return ((t_philo *) NULL);
	new_philo->id = index;
	new_philo->eat_counter = 0;
	new_philo->status = IDLE;
	new_philo->thread = (pthread_t) NULL;
	new_philo->prev = (t_philo *) NULL;
	new_philo->next = (t_philo *) NULL;
	return (new_philo);
}
