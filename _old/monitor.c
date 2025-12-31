
#include "./philo.h"

static int	check_philosopher_death(t_data *data, int i)
{
	long long	current_time;
	long long	time_since_meal;
	long long	death_time;

	pthread_mutex_lock(&data->meal_mutex);
	current_time = get_time();
	time_since_meal = current_time - data->philos[i].last_meal_time;
	pthread_mutex_unlock(&data->meal_mutex);
	if (time_since_meal > data->time_to_die)
	{
		death_time = current_time - data->start_time;
		pthread_mutex_lock(&data->death_mutex);
		if (!data->someone_died)
		{
			data->someone_died = TRUE;
			pthread_mutex_unlock(&data->death_mutex);
			pthread_mutex_lock(&data->print_mutex);
			printf("%lld %d died\n", death_time, data->philos[i].id);
			pthread_mutex_unlock(&data->print_mutex);
			return (TRUE);
		}
		pthread_mutex_unlock(&data->death_mutex);
	}
	return (FALSE);
}

static int	all_philos_ate_enough(t_data *data)
{
	int	i;
	int	meals_count;

	i = 0;
	while (i < data->num_philos)
	{
		meals_count = data->philos[i].meals_eaten;
		if (meals_count < data->must_eat_count)
			return (FALSE);
		i++;
	}
	return (TRUE);
}

static int	check_all_ate_enough(t_data *data)
{
	int	all_done;

	if (!data->has_must_eat)
		return (FALSE);
	pthread_mutex_lock(&data->meal_mutex);
	all_done = all_philos_ate_enough(data);
	pthread_mutex_unlock(&data->meal_mutex);
	if (all_done)
	{
		pthread_mutex_lock(&data->death_mutex);
		data->all_ate_enough = TRUE;
		pthread_mutex_unlock(&data->death_mutex);
		return (TRUE);
	}
	return (FALSE);
}

void	monitor_philosophers(t_data *data)
{
	int			i;
	long long	sleep_time;

	sleep_time = data->time_to_die / 2;
	if (sleep_time > 1000)
		sleep_time = 1000;
	if (sleep_time < 100)
		sleep_time = 100;
	while (1)
	{
		i = 0;
		while (i < data->num_philos)
		{
			if (check_philosopher_death(data, i))
				return ;
			i++;
		}
		if (check_all_ate_enough(data))
			return ;
		usleep(sleep_time);
	}
}
