/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grcharle <grcharle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/12 00:18:04 by grcharle          #+#    #+#             */
/*   Updated: 2025/12/12 00:18:06 by grcharle         ###   ########.fr       */
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
