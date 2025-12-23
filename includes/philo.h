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
# include <stdlib.h>
# include <stdio.h>

typedef struct s_philo
{
	char			fork_used;
	int				status;
	struct s_philo	*prev;
	struct s_philo	*next;
}	t_philo;

typedef struct s_params
{
	unsigned int	nb_philos;
	unsigned int	time_die;
	unsigned int	time_eat;
	unsigned int	time_sleep;
	unsigned int	nb_time_eat;
}	t_params;

#endif // PHILO_H
