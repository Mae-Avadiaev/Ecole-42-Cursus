#include "../incs/philo.h"

int	main(int argc, char **argv)
{
	t_philo_all	philo;

	if (argc < 5 || argc > 6)
		return (1);
	if (!check_arguments(argv))
		return (1);
	philo.simulation__on = 1;
	philo_struct_init(argv, &philo);
	create_and_execute_treads(&philo);
	philo_quit(&philo);
	return (0);
}
