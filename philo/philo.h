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
# include "libft.h"

typedef struct s_data
{
	int nb_philos;
	int t_die;
	int t_eat;
	int t_sleep;
	int nb_t_eat;
}   t_data;

#endif // PHILO_H
