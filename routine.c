
#include "../philo.h"

static void	take_forks(t_philo *philo)
{
	if (philo->id % 2 == 0)
	{
		pthread_mutex_lock(philo->right_fork);
		print_message(philo, "has taken a fork");
		pthread_mutex_lock(philo->left_fork);
		print_message(philo, "has taken a fork");
	}
	else
	{
		pthread_mutex_lock(philo->left_fork);
		print_message(philo, "has taken a fork");
		pthread_mutex_lock(philo->right_fork);
		print_message(philo, "has taken a fork");
	}
}

static void	eat(t_philo *philo)
{
	take_forks(philo);
	print_message(philo, "is eating");
	pthread_mutex_lock(&philo->data->meal_mutex);
	philo->last_meal_time = get_time();
	philo->meals_eaten++;
	pthread_mutex_unlock(&philo->data->meal_mutex);
	ft_usleep(philo->data->time_to_eat);
	pthread_mutex_unlock(philo->left_fork);
	pthread_mutex_unlock(philo->right_fork);
}

static void	philo_sleep(t_philo *philo)
{
	long long	start_time;
	long long	elapsed;

	print_message(philo, "is sleeping");
	start_time = get_time();
	elapsed = get_time() - start_time;
	while (elapsed < philo->data->time_to_sleep)
	{
		pthread_mutex_lock(&philo->data->death_mutex);
		if (philo->data->someone_died || philo->data->all_ate_enough)
		{
			pthread_mutex_unlock(&philo->data->death_mutex);
			return ;
		}
		pthread_mutex_unlock(&philo->data->death_mutex);
		usleep(1000);
		elapsed = get_time() - start_time;
	}
}

static void	think(t_philo *philo)
{
	long long	think_time;

	print_message(philo, "is thinking");
	if (philo->data->num_philos % 2 != 0)
	{
		think_time = (philo->data->time_to_eat * 2)
			- (philo->data->time_to_sleep);
		if (think_time < 0)
			think_time = 0;
		if (think_time > 600)
			think_time = 200;
		if (think_time > 0)
			wait_thinking_time(philo, think_time);
	}
}

void	*philosopher_routine(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	wait_for_start(philo);
	pthread_mutex_lock(&philo->data->meal_mutex);
	philo->last_meal_time = philo->data->start_time;
	pthread_mutex_unlock(&philo->data->meal_mutex);
	if (philo->id % 2 == 0)
		ft_usleep(philo->data->time_to_eat / 2);
	while (1)
	{
		pthread_mutex_lock(&philo->data->death_mutex);
		if (philo->data->someone_died || philo->data->all_ate_enough)
		{
			pthread_mutex_unlock(&philo->data->death_mutex);
			break ;
		}
		pthread_mutex_unlock(&philo->data->death_mutex);
		eat(philo);
		philo_sleep(philo);
		think(philo);
	}
	return (NULL);
}
