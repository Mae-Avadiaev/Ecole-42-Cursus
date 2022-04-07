#ifndef PHILO_H
# define PHILO_H

# include <pthread.h>
# include <stdlib.h>
# include <sys/time.h>
# include <stdio.h>
# include <unistd.h>

typedef struct s_philo_arr {
	pthread_t			pt;
	size_t				t_to_d;
	size_t				t_to_e;
	size_t				t_to_s;
	size_t				num_to_e;
	long int			t_of_dth;
	long int			t_of_eat;
	long int			t_of_slp;
	int					coun;
	pthread_mutex_t		*left_fork;
	pthread_mutex_t		*right_fork;
	pthread_mutex_t		*mut_print;
	pthread_mutex_t		*mut_death;
	int					is_full;
	size_t				num_eat;
	int					*simulation_on;

}						t_philo_arr;

typedef struct s_philo_all {
	int				simulation_on;
	int				num;
	t_philo_arr		*arr;
	pthread_mutex_t	*mutex_arr;
	pthread_mutex_t	mut_print;
	pthread_mutex_t	mut_death;
	int				simulation__on;
}				t_philo_all;

int		ft_atoi(const char *str);

void	turn_off_simulation(t_philo_all *philo, int i);
int		create_and_execute_treads(t_philo_all *philo);
void	controll_philos(t_philo_all *philo);

void	philo_quit(t_philo_all *philo);
void	my_wait(long int t_of_eat);
int		check_arguments(char **argv);

void	*thread_func(void *v_philo);
void	init_time_of_death(t_philo_arr *philo);
void	p_sleep(t_philo_arr *philo);
int		think(t_philo_arr *philo);

int		eat(t_philo_arr *philo);
int		right_take_forks(t_philo_arr *philo);
int		left_take_forks(t_philo_arr *philo);
void	reinitiate_ts(t_philo_arr *philo, long int tv_ms);

void	philo_struct_init(char **argv, t_philo_all *philo);
void	distribute_forks(t_philo_all *philo, int i);
void	distribute_args(char **argv, t_philo_all *philo, int i);

int		ft_isdigit(int c);

#endif
