
#ifndef PHILO_H
# define PHILO_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <pthread.h>
# include <sys/time.h>

# define TRUE 1
# define FALSE 0

typedef struct s_data	t_data;

typedef struct s_philo
{
	int				id;
	int				meals_eaten;
	long long		last_meal_time;
	pthread_t		thread;
	pthread_mutex_t	*left_fork;
	pthread_mutex_t	*right_fork;
	t_data			*data;
}	t_philo;

typedef struct s_data
{
	int				num_philos;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				must_eat_count;
	int				has_must_eat;
	long long		start_time;
	int				someone_died;
	int				all_ate_enough;
	int				simulation_started;
	pthread_mutex_t	*forks;
	pthread_mutex_t	print_mutex;
	pthread_mutex_t	death_mutex;
	pthread_mutex_t	meal_mutex;
	pthread_mutex_t	start_mutex;
	t_philo			*philos;
}	t_data;

int			init_data(t_data *data, int argc, char **argv);
int			init_philosophers(t_data *data);

int			init_mutexes(t_data *data);
void		cleanup_fork_mutexes(t_data *data, int count);

int			ft_atoi(const char *str);
int			ft_isdigit(int c);
void		print_message(t_philo *philo, char *message);
void		wait_thinking_time(t_philo *philo, long long think_time);
void		wait_for_start(t_philo *philo);

int			validate_args(int argc, char **argv);

long long	get_time(void);
void		ft_usleep(long long milliseconds);

void		*philosopher_routine(void *arg);

void		monitor_philosophers(t_data *data);
int			check_death(t_data *data);

void		cleanup(t_data *data);
void		destroy_mutexes(t_data *data);

#endif
