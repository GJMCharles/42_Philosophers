
#include "../philo.h"

static int	check_arg_format(char *arg)
{
	int	j;

	if (arg[0] == '\0')
		return (FALSE);
	j = 0;
	while (arg[j])
	{
		if (!ft_isdigit(arg[j]))
			return (FALSE);
		j++;
	}
	if (ft_atoi(arg) <= 0)
		return (FALSE);
	return (TRUE);
}

int	validate_args(int argc, char **argv)
{
	int	i;

	if (argc < 5 || argc > 6)
	{
		printf("Error: Invalid number of arguments\n");
		printf("Usage: ./philo number_of_philosophers time_to_die ");
		printf("time_to_eat time_to_sleep ");
		printf("[number_of_times_each_philosopher_must_eat]\n");
		return (FALSE);
	}
	i = 1;
	while (i < argc)
	{
		if (!check_arg_format(argv[i]))
		{
			printf("Error: Invalid number\n");
			return (FALSE);
		}
		i++;
	}
	return (TRUE);
}
