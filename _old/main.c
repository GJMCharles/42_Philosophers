
#include "./philo.h"

static int	create_threads(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->num_philos)
	{
		if (pthread_create(&data->philos[i].thread, NULL,
				philosopher_routine, &data->philos[i]) != 0)
		{
			data->someone_died = TRUE;
			while (--i >= 0)
				pthread_join(data->philos[i].thread, NULL);
			return (FALSE);
		}
		i++;
	}
	return (TRUE);
}

static void	join_threads(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->num_philos)
	{
		pthread_join(data->philos[i].thread, NULL);
		i++;
	}
}

static int	handle_single_philosopher(t_data *data)
{
	if (data->num_philos == 1)
	{
		printf("0 1 has taken a fork\n");
		ft_usleep(data->time_to_die);
		printf("%d 1 died\n", data->time_to_die);
		return (TRUE);
	}
	return (FALSE);
}

static void	start_simulation(t_data *data)
{
	pthread_mutex_lock(&data->start_mutex);
	data->start_time = get_time();
	data->simulation_started = TRUE;
	pthread_mutex_unlock(&data->start_mutex);
}

int	main(int argc, char **argv)
{
	t_data	data;

	if (!validate_args(argc, argv))
		return (1);
	if (!init_data(&data, argc, argv))
		return (printf("Error: Initialization failed\n"), 1);
	if (handle_single_philosopher(&data))
		return (cleanup(&data), 0);
	if (!create_threads(&data))
		return (printf("Error: Thread creation failed\n"),
			cleanup(&data), 1);
	start_simulation(&data);
	monitor_philosophers(&data);
	join_threads(&data);
	cleanup(&data);
	return (0);
}
