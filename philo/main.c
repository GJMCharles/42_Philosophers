/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grcharle <grcharle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/13 20:30:09 by grcharle          #+#    #+#             */
/*   Updated: 2026/01/13 20:30:58 by grcharle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int argc, char *argv[])
{
	t_data	*data;

	if (verify_arguments(argc, argv) == FALSE)
		return (ft_putendl_fd((char *) "Error", STDERR_FILENO), EXIT_FAILURE);
	data = build_data(argc, argv);
	if (!data)
		return (EXIT_FAILURE);
	init_pthreads_mutex(&data);
	start_simulator(&data);
	destroy_pthreads_mutex(&data);
	free_data(&data);

	/**
	//start_simulators(&data);
	int						exec_pthread_mutex(pthread_mutex_t mutex,\
	//							t_philo *philo, t_param *param,\
	//							int (*f)(t_philo *, t_param *));
	//int						everyone_satiated(t_philo *philo, t_param *param);
	//int						should_abort_simulator(t_philo *philo, t_param *param);
	//char					*get_status_text(t_status code);
	//void					display_message(t_philo *philo, char *message);
	//void					forced_waiting(t_param *param, unsigned int delay);
	//void					action_die(t_philo *philo, t_param *param);
	//int						thinking_process(t_philo *philo, t_param *param);
	//int						action_think(t_philo *philo, t_param *param);
	//int						sleeping_process(t_philo *philo, t_param *param);
	//int						action_sleep(t_philo *philo, t_param *param);
	//int						eating_process(t_philo *philo, t_param *param);
	//int						pick_right_fork(t_philo *philo, t_param *param);
	//int						pick_left_fork(t_philo *philo, t_param *param);
	//int						action_eat(t_philo *philo, t_param *param);
	//void					*simulator(void *arg);
	//unsigned long int		get_timestamp_ms(void);
	//void					start_simulators(t_data **data);
	//void					end_pthreads(t_data **data);
	//void					init_pthreads_mutex(t_data **data);
	//void					append_philosopher(t_philo *node, t_philo **list);
	//void					clear_philosophers(t_philo **list);
	//t_philo					*new_philosopher(void);
	//t_philo					*init_philosophers(t_param *param);
	//t_param					*init_parameters(int argc, char *argv[]);
	//void					free_data(t_data **data);
	//t_data					*build_data(int argc, char *argv[]);
	*/
	return (EXIT_SUCCESS);
}
