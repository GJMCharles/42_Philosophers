
#include "../philo.h"

int	ft_isdigit(int c)
{
	return (c >= '0' && c <= '9');
}

int	ft_atoi(const char *str)
{
	int	result;
	int	sign;

	result = 0;
	sign = 1;
	while (*str == ' ' || (*str >= 9 && *str <= 13))
		str++;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			sign = -1;
		str++;
	}
	while (ft_isdigit(*str))
	{
		result = result * 10 + (*str - '0');
		str++;
	}
	return (result * sign);
}

void	print_message(t_philo *philo, char *message)
{
	long long	timestamp;

	pthread_mutex_lock(&philo->data->death_mutex);
	if (!philo->data->someone_died)
	{
		pthread_mutex_lock(&philo->data->print_mutex);
		timestamp = get_time() - philo->data->start_time;
		printf("%lld %d %s\n", timestamp, philo->id, message);
		pthread_mutex_unlock(&philo->data->print_mutex);
	}
	pthread_mutex_unlock(&philo->data->death_mutex);
}

void	wait_thinking_time(t_philo *philo, long long think_time)
{
	long long	start_time;
	long long	elapsed;

	start_time = get_time();
	elapsed = get_time() - start_time;
	while (elapsed < think_time)
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

void	wait_for_start(t_philo *philo)
{
	while (1)
	{
		pthread_mutex_lock(&philo->data->start_mutex);
		if (philo->data->simulation_started)
		{
			pthread_mutex_unlock(&philo->data->start_mutex);
			break ;
		}
		pthread_mutex_unlock(&philo->data->start_mutex);
		usleep(100);
	}
}
