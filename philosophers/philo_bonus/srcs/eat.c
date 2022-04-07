#include "../incs/philo_bonus.h"

void	take_forks(t_philo_all *philo)
{
	struct timeval	tv;

	sem_wait(philo->take_forks);
	sem_wait(philo->forks);
	sem_wait(philo->forks);
	sem_post(philo->take_forks);
	gettimeofday(&tv, NULL);
	sem_wait(philo->print);
	if (philo->simulation_on)
	{
		printf("%lu %d has taken a fork\n", tv.tv_sec * 1000
			+ tv.tv_usec / 1000, philo->philo.coun);
		printf("%lu %d has taken a fork\n", tv.tv_sec * 1000
			+ tv.tv_usec / 1000, philo->philo.coun);
	}
	sem_post(philo->print);
}

void	reinitiate_ts(t_philo_all *philo, long int tv_ms)
{
	sem_wait(philo->death);
	philo->philo.t_of_dth = tv_ms + philo->philo.t_to_d;
	philo->philo.t_of_eat = tv_ms + philo->philo.t_to_e;
	sem_post(philo->death);
}

int	eat(t_philo_all *philo)
{
	struct timeval	tv;
	long int		tv_ms;

	if (philo->num == 1)
		return (0);
	take_forks(philo);
	gettimeofday(&tv, NULL);
	tv_ms = tv.tv_sec * 1000 + tv.tv_usec / 1000;
	if (philo->simulation_on)
		printf("%lu %d is eating\n", tv_ms, philo->philo.coun);
	reinitiate_ts(philo, tv_ms);
	my_wait(philo->philo.t_of_eat);
	philo->philo.num_eat++;
	sem_post(philo->forks);
	sem_post(philo->forks);
	return (1);
}
