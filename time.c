
#include "../philo.h"

long long	get_time(void)
{
	struct timeval	tv;

	gettimeofday(&tv, NULL);
	return ((tv.tv_sec * 1000) + (tv.tv_usec / 1000));
}

void	ft_usleep(long long milliseconds)
{
	long long	start;
	long long	remaining;

	start = get_time();
	while ((get_time() - start) < milliseconds)
	{
		remaining = milliseconds - (get_time() - start);
		if (remaining > 10)
			usleep(5000);
		else if (remaining > 1)
			usleep(500);
		else
			usleep(100);
	}
}
