#include "../incs/philo_bonus.h"

void	distribute_args(char **argv, t_philo_all *philo)
{
	philo->philo.t_to_d = ft_atoi(argv[2]);
	philo->philo.t_to_e = ft_atoi(argv[3]);
	philo->philo.t_to_s = ft_atoi(argv[4]);
	if (argv[5])
		philo->philo.num_to_e = ft_atoi(argv[5]);
	else
		philo->philo.num_to_e = -1;
}

void	philo_struct_init(char **argv, t_philo_all *philo)
{
	philo->num = ft_atoi(argv[1]);
	philo->forks = sem_open("forks", O_CREAT, 0777, philo->num);
	philo->print = sem_open("print", O_CREAT, 0777, 1);
	philo->death = sem_open("death", O_CREAT, 0777, 1);
	philo->take_forks = sem_open("take_forks", O_CREAT, 0777, 1);
	philo->pid_arr = malloc(sizeof(pid_t) * philo->num);
	distribute_args(argv, philo);
	philo->philo.num_eat = 0;
}
