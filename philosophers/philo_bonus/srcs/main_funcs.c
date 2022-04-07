#include "../incs/philo_bonus.h"

void	turn_off_simulation(t_philo_all *philo)
{
	sem_wait(philo->death);
	sem_wait(philo->print);
	printf("%lu %d died\n", philo->philo.t_of_dth, philo->philo.coun);
	philo->simulation_on = 0;
	sem_post(philo->print);
	sem_post(philo->death);
}

int	controll_philos(t_philo_all *philo)
{
	struct timeval	tv;

	usleep(50);
	while (philo->simulation_on)
	{
		gettimeofday(&tv, NULL);
		if (philo->philo.t_of_dth <= tv.tv_sec * 1000 + tv.tv_usec / 1000)
			turn_off_simulation(philo);
		if (philo->philo.is_full)
		{
			free(philo->pid_arr);
			return (FULL);
		}
	}
	free(philo->pid_arr);
	return (DEATH);
}

int	create_and_execute_proc(t_philo_all *philo)
{
	int		i;
	pid_t	temp_pid;

	i = 0;
	while (i < philo->num)
	{
		temp_pid = fork();
		if (temp_pid != 0)
			philo->pid_arr[i] = temp_pid;
		else
		{
			philo->philo.coun = i + 1;
			break ;
		}
		i++;
	}
	if (temp_pid == 0)
	{
		if (pthread_create(&philo->philo.pt, NULL, &thread_func, philo) != 0)
			return (2);
		return (controll_philos(philo));
	}
	return (kill_or_wait(philo));
}
