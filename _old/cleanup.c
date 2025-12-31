
#include "./philo.h"

void	destroy_mutexes(t_data *data)
{
	int	i;

	if (data->forks)
	{
		i = 0;
		while (i < data->num_philos)
		{
			pthread_mutex_destroy(&data->forks[i]);
			i++;
		}
	}
	pthread_mutex_destroy(&data->print_mutex);
	pthread_mutex_destroy(&data->death_mutex);
	pthread_mutex_destroy(&data->meal_mutex);
	pthread_mutex_destroy(&data->start_mutex);
}

void	cleanup(t_data *data)
{
	destroy_mutexes(data);
	if (data->forks)
		free(data->forks);
	if (data->philos)
		free(data->philos);
}
