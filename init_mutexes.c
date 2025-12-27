
#include "../philo.h"

void	cleanup_fork_mutexes(t_data *data, int count)
{
	int	i;

	i = 0;
	while (i < count)
	{
		pthread_mutex_destroy(&data->forks[i]);
		i++;
	}
	free(data->forks);
	data->forks = NULL;
}

static int	init_fork_mutexes(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->num_philos)
	{
		if (pthread_mutex_init(&data->forks[i], NULL) != 0)
		{
			cleanup_fork_mutexes(data, i);
			return (FALSE);
		}
		i++;
	}
	return (TRUE);
}

static int	init_control_mutexes(t_data *data)
{
	if (pthread_mutex_init(&data->print_mutex, NULL) != 0)
		return (cleanup_fork_mutexes(data, data->num_philos), FALSE);
	if (pthread_mutex_init(&data->death_mutex, NULL) != 0)
		return (pthread_mutex_destroy(&data->print_mutex),
			cleanup_fork_mutexes(data, data->num_philos), FALSE);
	if (pthread_mutex_init(&data->meal_mutex, NULL) != 0)
		return (pthread_mutex_destroy(&data->death_mutex),
			pthread_mutex_destroy(&data->print_mutex),
			cleanup_fork_mutexes(data, data->num_philos), FALSE);
	if (pthread_mutex_init(&data->start_mutex, NULL) != 0)
		return (pthread_mutex_destroy(&data->meal_mutex),
			pthread_mutex_destroy(&data->death_mutex),
			pthread_mutex_destroy(&data->print_mutex),
			cleanup_fork_mutexes(data, data->num_philos), FALSE);
	return (TRUE);
}

int	init_mutexes(t_data *data)
{
	data->forks = malloc(sizeof(pthread_mutex_t) * data->num_philos);
	if (!data->forks)
		return (FALSE);
	if (!init_fork_mutexes(data))
		return (FALSE);
	if (!init_control_mutexes(data))
		return (FALSE);
	return (TRUE);
}
