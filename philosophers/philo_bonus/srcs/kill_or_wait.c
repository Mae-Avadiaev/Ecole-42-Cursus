#include "../incs/philo_bonus.h"

void	kill_all_proc(t_philo_all *philo)
{
	int	i;

	i = 0;
	while (philo->pid_arr[i])
	{
		kill(philo->pid_arr[i], SIGKILL);
		i++;
	}
}

int	kill_or_wait(t_philo_all *philo)
{
	int	full_philos;
	int	res;
	int	status;

	res = -1;
	full_philos = 0;
	while (full_philos < philo->num && res != DEATH)
	{
		waitpid(-1, &status, 0);
		res = WEXITSTATUS(status);
		if (res == FULL)
			full_philos++;
		else if (res == DEATH)
			kill_all_proc(philo);
	}
	philo_quit(philo);
	return (0);
}
