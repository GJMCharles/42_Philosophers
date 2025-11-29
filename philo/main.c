/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grcharle </var/spool/mail/grcharle>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/11 12:06:06 by grcharle          #+#    #+#             */
/*   Updated: 2025/11/11 12:06:50 by grcharle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

/**
int	verify_data(int nb_args, char *args[])
{
	(void) *args;
	if (nb_args == 6)
	{
		//
	}
	return (1);
}

void	initiate_thread(t_params *data)
{
	//
}

void	exit_thread(t_params *data)
{
	//
}
*/

void	*process_data(void *data)
{
	// printf("{%s}", (t_data *)data.id);
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

t_params	assign_data_list(char *argv[])
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

int	build_structure(t_params params, t_data **list)
{
	int		index;
	t_data	*node;
	t_data	*temp;

	index = 0;
	while (index++ < params.nb_philos)
	{		
		node = (t_data *) malloc(sizeof(t_data));
		if (!node)
			return (0);
		node->id = index;
		if (pthread_create(&(node->thread), NULL, process_data, &params) == -1)
			return (free(node), 0);
		node->next = (struct s_data *) NULL;
		temp = *list;
		if (!(*list))
			temp = node;
		else
		{
			while (temp->next)
				temp = temp->next;
			temp->next = node;
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

int	main(int argc, char *argv[])
{
	t_data	*data;

	if (!verify_data(argc, argv) || \
		!build_structure(assign_data_list(argv), &data))
		return (clear_data(&data), EXIT_FAILURE);
	return (clear_data(&data), EXIT_SUCCESS);
}
