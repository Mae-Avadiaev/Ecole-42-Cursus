#include "../incs/philo.h"

void	p_sleep(t_philo_arr *philo)
{
	struct timeval	tv;

	gettimeofday(&tv, NULL);
	if (*philo->simulation_on)
		printf("%lu %d is sleeping\n", tv.tv_sec * 1000
			+ tv.tv_usec / 1000, philo->coun);
	philo->t_of_slp = (tv.tv_sec * 1000 + tv.tv_usec / 1000) + philo->t_to_s;
	my_wait(philo->t_of_slp);
}

void	init_time_of_death(t_philo_arr *philo)
{
	struct timeval	tv;

	philo->num_eat = 0;
	gettimeofday(&tv, NULL);
	philo->t_of_dth = (tv.tv_sec * 1000 + tv.tv_usec / 1000) + philo->t_to_d;
}

int	think(t_philo_arr *philo)
{
	struct timeval	tv;

	gettimeofday(&tv, NULL);
	if (*philo->simulation_on)
		printf("%lu %d is thinking\n", tv.tv_sec * 1000
			+ tv.tv_usec / 1000, philo->coun);
	return (1);
}

void	*thread_func(void *v_philo)
{
	t_philo_arr	*philo;
	int			thinking;

	philo = (t_philo_arr *)v_philo;
	init_time_of_death(philo);
	thinking = 0;
	while (*philo->simulation_on && !philo->is_full)
	{
		if (eat(philo))
		{
			if (philo->num_eat == philo->num_to_e)
			{
				philo->is_full = 1;
				return (0);
			}
			thinking = 0;
			p_sleep(philo);
		}
		if (!thinking)
			thinking = think(philo);
		usleep(50);
	}
	return (0);
}
