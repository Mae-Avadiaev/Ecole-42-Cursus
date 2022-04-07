#include "../incs/philo.h"

void	my_wait(long int t_of_eat)
{
	struct timeval	tv;

	gettimeofday(&tv, NULL);
	while ((tv.tv_sec * 1000 + tv.tv_usec / 1000) < t_of_eat)
	{
		usleep(100);
		gettimeofday(&tv, NULL);
	}
}

void	philo_quit(t_philo_all *philo)
{
	int	i;

	i = 0;
	while (i < philo->num)
	{
		pthread_mutex_destroy(&(philo->mutex_arr[i]));
		i++;
	}
	pthread_mutex_destroy(&(philo->mut_print));
	pthread_mutex_destroy(&(philo->mut_death));
	free(philo->arr);
	free(philo->mutex_arr);
}

int	check_arguments(char **argv)
{
	int	i;

	i = 1;
	while (argv[i])
	{
		if (!ft_isdigit(*argv[i]))
			return (0);
		if (ft_atoi(argv[i]) < 0)
			return (0);
		i++;
	}
	return (1);
}
