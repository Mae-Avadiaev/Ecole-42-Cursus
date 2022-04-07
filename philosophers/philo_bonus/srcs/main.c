#include "../incs/philo_bonus.h"

int	main(int argc, char **argv)
{
	t_philo_all	philo;

	if (argc < 5)
		return (1);
	if (!check_arguments(argv))
		return (1);
	philo.simulation_on = 1;
	philo_struct_init(argv, &philo);
	return (create_and_execute_proc(&philo));
}
