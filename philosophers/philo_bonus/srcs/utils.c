#include "../incs/philo_bonus.h"

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
	sem_close(philo->death);
	sem_close(philo->forks);
	sem_close(philo->print);
	sem_close(philo->take_forks);
	sem_unlink("death");
	sem_unlink("forks");
	sem_unlink("print");
	sem_unlink("take_forks");
	free(philo->pid_arr);
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
