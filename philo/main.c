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

int	main(int argc, char *argv[])
{
	t_data	*data;

	
	if (!verify_data(argc, argv) || !build_list(assign_data(argv), &data))
		return (clear_data(&data), EXIT_FAILURE);
	return (clear_data(&data), EXIT_SUCCESS);
}
