#include "philosophers.h"

int	main(int argc, char *argv[])
{
	t_info	*info;
	t_philo	**philo;

	if (arg_invalid_check(argc, argv))
		return (1);
	info = init_info(argv);
	philo = init_philo(info, info->num_of_philo);
	if (!info || !philo)
		return (free_return (info, philo, 1));
	if (!(create_thread(info, philo)))
		return (free_return (info, philo, 1));
	return(free_return(info, philo, 0));
}

int	free_return(t_info *info, t_philo **philo, int return_flag)
{
	int i;

	if (info && info->forks)
		free(info->forks);
	if (info)
		free(info);
	i = 0;
	if (philo)
	{
		while (philo[i])
			free(philo[i++]);
		free(philo);
	}
	return (return_flag);
}