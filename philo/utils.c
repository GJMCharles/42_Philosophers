/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grcharle <grcharle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/12 00:18:34 by grcharle          #+#    #+#             */
/*   Updated: 2025/12/12 00:18:37 by grcharle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*process_data(void *data)
{
	printf("{%d}", ((t_data *) data)->id);
	return (NULL);
}

void	clear_data(t_data **list)
{
	t_data	*temp;

	while (*list)
	{
		temp = (*list)->next;
		pthread_detach((*list)->thread);
		pthread_cancel((*list)->thread);
		free(*list);
		*list = temp;
	}
}

t_params	assign_data(char *argv[])
{
	t_params	params;

	params.nb_philos = ft_atoi(argv[1]);
	params.t_die = ft_atoi(argv[2]);
	params.t_eat = ft_atoi(argv[3]);
	params.t_sleep = ft_atoi(argv[4]);
	if (argv[5] != NULL)
		params.nb_times_must_eat = ft_atoi(argv[5]);
	return (params);
}

int	build_list(t_params params, t_data **list)
{
	int		index;
	t_data	*n;
	t_data	*temp;

	index = 0;
	while (index++ <= params.nb_philos)
	{
		n = (t_data *) malloc(sizeof(t_data));
		if (!n)
			return (0);
		n->id = index;
		if (pthread_create(&(n->thread), NULL, process_data, &(*n)) == -1)
			return (free(n), 0);
		n->next = (struct s_data *) NULL;
		temp = *list;
		if (!(*list))
			temp = n;
		else
		{
			while (temp->next)
				temp = temp->next;
			temp->next = n;
		}
	}
	return (1);
}

int	verify_data(int argc, char **argv)
{
	int	index;
	int	value;

	if (argc < 5 || argc > 6)
	{
		ft_putendl_fd("Error: invalid argument(s)", 2);
		ft_putstr_fd("./philo ", 2);
		ft_putstr_fd("(nb_pholosophers) (t_die) (t_eat) (t_sleep) ", 2);
		ft_putendl_fd("[nb_times_each_philosopher_must_eat]", 2);
		return (0);
	}
	index = 0;
	while (++index < argc)
	{
		value = ft_atoi(argv[index]);
		if (!value || value < 0)
			return (0);
	}
	return (1);
}
