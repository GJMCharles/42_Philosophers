/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grcharle <grcharle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/12 00:20:15 by grcharle          #+#    #+#             */
/*   Updated: 2025/12/12 00:20:17 by grcharle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include "libft.h"
# include <pthread.h>
# include <stdio.h>

typedef struct s_params
{
	int	nb_philos;
	int	t_die;
	int	t_eat;
	int	t_sleep;
	int	nb_times_must_eat;
}	t_params;

typedef struct s_data
{
	unsigned int	id;
	unsigned int	count;
	int				status;
	pthread_t		thread;
	struct s_data	*next;
}	t_data;

void		*process_data(void *data);
void		clear_data(t_data **list);
t_params	assign_data(char *argv[]);
int			build_list(t_params params, t_data **list);
int			verify_data(int argc, char **argv);

#endif // PHILO_H
