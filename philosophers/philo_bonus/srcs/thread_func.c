#include "../incs/philo_bonus.h"

void	p_sleep(t_philo_all *philo)
{
	struct timeval	tv;

	gettimeofday(&tv, NULL);
	sem_wait(philo->print);
	if (philo->simulation_on)
		printf("%lu %d is sleeping\n", tv.tv_sec * 1000
			+ tv.tv_usec / 1000, philo->philo.coun);
	sem_post(philo->print);
	philo->philo.t_of_slp = (tv.tv_sec * 1000
			+ tv.tv_usec / 1000) + philo->philo.t_to_s;
	my_wait(philo->philo.t_of_slp);
}

void	init_time_of_death(t_philo_all *philo)
{
	struct timeval	tv;

	philo->philo.num_eat = 0;
	gettimeofday(&tv, NULL);
	philo->philo.t_of_dth = (tv.tv_sec * 1000
			+ tv.tv_usec / 1000) + philo->philo.t_to_d;
}

void	think(t_philo_all *philo)
{
	struct timeval	tv;

	gettimeofday(&tv, NULL);
	sem_wait(philo->print);
	if (philo->simulation_on)
		printf("%lu %d is thinking\n", tv.tv_sec * 1000
			+ tv.tv_usec / 1000, philo->philo.coun);
	sem_post(philo->print);
}

void	*thread_func(void *v_philo)
{
	t_philo_all	*philo;
	int			thinking;

	philo = (t_philo_all *)v_philo;
	init_time_of_death(philo);
	thinking = 0;
	while (philo->simulation_on)
	{
		if (eat(philo))
		{
			thinking = 0;
			if (philo->philo.num_eat == philo->philo.num_to_e)
			{
				philo->philo.is_full = 1;
				return (0);
			}
			p_sleep(philo);
		}
		if (!thinking)
		{
			thinking = 1;
			think(philo);
		}
	}
	return (0);
}
