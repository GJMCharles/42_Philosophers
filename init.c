
#include "../philo.h"

int	init_philosophers(t_data *data)
{
	int	i;

	data->philos = malloc(sizeof(t_philo) * data->num_philos);
	if (!data->philos)
		return (FALSE);
	i = 0;
	while (i < data->num_philos)
	{
		data->philos[i].id = i + 1;
		data->philos[i].meals_eaten = 0;
		data->philos[i].last_meal_time = data->start_time;
		data->philos[i].left_fork = &data->forks[i];
		data->philos[i].right_fork = &data->forks[(i + 1) % data->num_philos];
		data->philos[i].data = data;
		i++;
	}
	return (TRUE);
}

static void	parse_arguments(t_data *data, int argc, char **argv)
{
	data->num_philos = ft_atoi(argv[1]);
	data->time_to_die = ft_atoi(argv[2]);
	data->time_to_eat = ft_atoi(argv[3]);
	data->time_to_sleep = ft_atoi(argv[4]);
	if (argc == 6)
	{
		data->must_eat_count = ft_atoi(argv[5]);
		data->has_must_eat = TRUE;
	}
	else
	{
		data->must_eat_count = -1;
		data->has_must_eat = FALSE;
	}
	data->someone_died = FALSE;
	data->all_ate_enough = FALSE;
	data->simulation_started = FALSE;
	data->start_time = get_time();
}

int	init_data(t_data *data, int argc, char **argv)
{
	data->forks = NULL;
	data->philos = NULL;
	parse_arguments(data, argc, argv);
	if (!init_mutexes(data))
		return (FALSE);
	if (!init_philosophers(data))
	{
		destroy_mutexes(data);
		return (FALSE);
	}
	return (TRUE);
}
