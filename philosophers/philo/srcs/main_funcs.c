#include "../incs/philo.h"

void	turn_off_simulation(t_philo_all *philo, int i)
{
	pthread_mutex_lock(&philo->mut_death);
	printf("%lu %d died\n", philo->arr[i].t_of_dth, i + 1);
	philo->simulation__on = 0;
	pthread_mutex_unlock(&philo->mut_death);
}

void	controll_philos(t_philo_all *philo)
{
	int				i;
	int				full_philos;
	struct timeval	tv;

	usleep(50);
	while (philo->simulation__on)
	{
		i = 0;
		full_philos = 0;
		while (i < philo->num)
		{
			gettimeofday(&tv, NULL);
			if (!philo->arr[i].is_full && philo->arr[i].t_of_dth
				<= tv.tv_sec * 1000 + tv.tv_usec / 1000)
			{
				turn_off_simulation(philo, i);
				break ;
			}
			if (philo->arr[i].is_full)
				full_philos++;
			i++;
		}
		if (full_philos == philo->num)
			philo->simulation__on = 0;
	}
}

int	create_and_execute_treads(t_philo_all *philo)
{
	int	i;

	i = 0;
	while (i < philo->num)
	{
		if ((pthread_create(&philo->arr[i].pt, NULL,
					&thread_func, &philo->arr[i])) != 0)
			return (2);
		i++;
	}
	controll_philos(philo);
	i = 0;
	while (i < philo->num)
	{
		if (pthread_join(philo->arr[i].pt, NULL) != 0)
			return (3);
		i++;
	}
	return (0);
}
