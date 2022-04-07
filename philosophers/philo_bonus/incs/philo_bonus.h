#ifndef PHILO_BONUS_H
# define PHILO_BONUS_H

# include <semaphore.h>
# include <pthread.h>
# include <stdlib.h>
# include <sys/time.h>
# include <stdio.h>
# include <unistd.h>
# include <signal.h>
# include <sys/types.h>
# include <sys/wait.h>

# define DEATH 0
# define FULL 1
# define MAIN 3

typedef struct s_philo {
	pthread_t			pt;
	size_t				t_to_d;
	size_t				t_to_e;
	size_t				t_to_s;
	size_t				num_to_e;
	long int			t_of_dth;
	long int			t_of_eat;
	long int			t_of_slp;
	int					coun;
	int					is_full;
	size_t				num_eat;
}						t_philo;

typedef struct s_philo_all {
	int					simulation_on;
	int					num;
	sem_t				*forks;
	sem_t				*print;
	sem_t				*death;
	sem_t				*take_forks;
	t_philo				philo;
	pid_t				*pid_arr;
}						t_philo_all;

int		ft_atoi(const char *str);

void	turn_off_simulation(t_philo_all *philo);
int		create_and_execute_proc(t_philo_all *philo);
int		controll_philos(t_philo_all *philo);

void	philo_quit(t_philo_all *philo);
void	my_wait(long int t_of_eat);
int		check_arguments(char **argv);

void	*thread_func(void *v_philo);
void	init_time_of_death(t_philo_all *philo);
void	p_sleep(t_philo_all *philo);
void	think(t_philo_all *philo);

int		eat(t_philo_all *philo);
void	reinitiate_ts(t_philo_all *philo, long int tv_ms);
void	take_forks(t_philo_all *philo);

void	philo_struct_init(char **argv, t_philo_all *philo);
void	distribute_args(char **argv, t_philo_all *philo);

void	kill_all_proc(t_philo_all *philo);
int		kill_or_wait(t_philo_all *philo);

int		ft_isdigit(int c);

#endif
