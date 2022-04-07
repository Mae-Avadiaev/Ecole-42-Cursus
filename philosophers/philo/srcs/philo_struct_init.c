#include "../incs/philo.h"

void	distribute_forks(t_philo_all *philo, int i)
{
	if (i == 0)
	{
		philo->arr[i].left_fork = &philo->mutex_arr[0];
		philo->arr[i].right_fork = &philo->mutex_arr[philo->num - 1];
	}
	else
	{
		philo->arr[i].left_fork = &philo->mutex_arr[i];
		philo->arr[i].right_fork = &philo->mutex_arr[i - 1];
	}
}

void	distribute_args(char **argv, t_philo_all *philo, int i)
{
	philo->arr[i].t_to_d = ft_atoi(argv[2]);
	philo->arr[i].t_to_e = ft_atoi(argv[3]);
	philo->arr[i].t_to_s = ft_atoi(argv[4]);
	if (argv[5])
		philo->arr[i].num_to_e = ft_atoi(argv[5]);
	else
		philo->arr[i].num_to_e = -1;
}

void	philo_struct_init(char **argv, t_philo_all *philo)
{
	int	i;

	philo->num = ft_atoi(argv[1]);
	philo->arr = malloc(sizeof(t_philo_arr) * philo->num);
	philo->mutex_arr = malloc(sizeof(pthread_mutex_t) * philo->num);
	pthread_mutex_init(&philo->mut_print, NULL);
	pthread_mutex_init(&philo->mut_death, NULL);
	i = 0;
	while (i < philo->num)
	{
		pthread_mutex_init(&philo->mutex_arr[i], NULL);
		distribute_args(argv, philo, i);
		philo->arr[i].simulation_on = &philo->simulation__on;
		philo->arr[i].mut_print = &philo->mut_print;
		philo->arr[i].mut_death = &philo->mut_death;
		philo->arr[i].coun = i + 1;
		philo->arr[i].num_eat = 0;
		distribute_forks(philo, i);
		i++;
	}
}
