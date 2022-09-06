#include "../philosophers.h"

int	main(int argc, char *argv[])
{
	t_info	*info;
	t_philo	*philo;

	if (arg_invalid_check(argc, argv))
		return (1);
	info = init_info(argv);
	philo = init_philo(info, info->num_of_philo);
	if (!info || !philo)
		return (free_return (info, philo, 1));
	if (!(create_thread(info, philo)))
		return (free_return (info, philo, 1));
	return(0);
}

int	free_return(t_info *info, t_philo *philo, int return_flag)
{
	int i;

	if (info && info->forks)
	{
		i = -1;
		while (++i < info->num_of_philo)
			pthread_mutex_destroy(&(info->forks[i]));
		free(info->forks);
	}
	if (info)
	{
		pthread_mutex_destroy(&(info->printer));
		free(info);
	}
	if (philo)
		free(philo);
	return (return_flag);
}