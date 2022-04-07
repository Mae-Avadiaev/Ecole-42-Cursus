#include "../incs/philo.h"

int	left_take_forks(t_philo_arr *philo)
{
	struct timeval	tv;

	if (pthread_mutex_lock(philo->left_fork) == 0)
	{
		gettimeofday(&tv, NULL);
		if (*philo->simulation_on)
			printf("%lu %d has taken a fork\n", tv.tv_sec * 1000
				+ tv.tv_usec / 1000, philo->coun);
		if (pthread_mutex_lock(philo->right_fork) == 0)
		{
			gettimeofday(&tv, NULL);
			if (*philo->simulation_on)
				printf("%lu %d has taken a fork\n", tv.tv_sec * 1000
					+ tv.tv_usec / 1000, philo->coun);
			return (1);
		}
		pthread_mutex_unlock(philo->left_fork);
		return (0);
	}
	return (0);
}

int	right_take_forks(t_philo_arr *philo)
{
	struct timeval	tv;

	if (pthread_mutex_lock(philo->right_fork) == 0)
	{
		gettimeofday(&tv, NULL);
		if (*philo->simulation_on)
			printf("%lu %d has taken a fork\n", tv.tv_sec * 1000
				+ tv.tv_usec / 1000, philo->coun);
		if (pthread_mutex_lock(philo->left_fork) == 0)
		{
			gettimeofday(&tv, NULL);
			if (*philo->simulation_on)
				printf("%lu %d has taken a fork\n", tv.tv_sec * 1000
					+ tv.tv_usec / 1000, philo->coun);
			return (1);
		}
		pthread_mutex_unlock(philo->right_fork);
		return (0);
	}
	return (0);
}

void	reinitiate_ts(t_philo_arr *philo, long int tv_ms)
{
	pthread_mutex_lock(philo->mut_death);
	philo->t_of_dth = tv_ms + philo->t_to_d;
	pthread_mutex_unlock(philo->mut_death);
	philo->t_of_eat = tv_ms + philo->t_to_e;
}

int	eat(t_philo_arr *philo)
{
	struct timeval	tv;
	int				taken_forks;
	long int		tv_ms;

	if (philo->left_fork == philo->right_fork)
		return (0);
	if (philo->coun % 2 != 0)
		taken_forks = right_take_forks(philo);
	else
		taken_forks = left_take_forks(philo);
	if (taken_forks)
	{
		gettimeofday(&tv, NULL);
		tv_ms = tv.tv_sec * 1000 + tv.tv_usec / 1000;
		if (*philo->simulation_on)
			printf("%lu %d is eating\n", tv_ms, philo->coun);
		reinitiate_ts(philo, tv_ms);
		my_wait(philo->t_of_eat);
		philo->num_eat++;
		pthread_mutex_unlock(philo->left_fork);
		pthread_mutex_unlock(philo->right_fork);
		return (1);
	}
	return (0);
}
