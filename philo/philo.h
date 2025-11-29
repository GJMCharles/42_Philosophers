/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grcharle </var/spool/mail/grcharle>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/17 23:53:58 by grcharle          #+#    #+#             */
/*   Updated: 2025/11/17 23:53:59 by grcharle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <pthread.h>
# include <stdio.h>
# include "libft.h"

typedef struct	s_params
{
	int nb_philos;
	int t_die;
	int t_eat;
	int t_sleep;
	int nb_times_must_eat;
}   t_params;

typedef struct	s_data
{
	unsigned int	id;
	unsigned int	count;
	int				status;
	pthread_t		thread;
	struct s_data	*next;
}	t_data;

#endif // PHILO_H
