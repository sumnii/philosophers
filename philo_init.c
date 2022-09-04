#include "philosophers.h"

int put_arg(t_info *info, char *argv[])
{
	info->num_of_philo = ft_atoi(argv[1]);
	info->time_to_die = ft_atoi(argv[2]);
	info->time_to_eat = ft_atoi(argv[3]);
	info->time_to_sleep = ft_atoi(argv[4]);
	if (argv[5])
		info->must_eat = ft_atoi(argv[5]);
	info->forks = malloc(sizeof(pthread_mutex_t) * info->num_of_philo);
	if (!info->forks)
		return (0);
	return (1);
}

t_info *init_info(char *argv[])
{
	t_info	*info;

	info = malloc(sizeof(t_info));
	if (!info)
	{
		printf("info malloc error!\n");
		return (0);
	}
	if (!put_arg(info, argv))
		return (0);
	return (info);
}

t_philo	**init_philo(t_info *info, int num_of_philo)
{
	t_philo	**philos;
	int 	i;

	philos = malloc(sizeof(t_philo *) * num_of_philo);
	if (!philos)
	{
		printf("philo malloc error!\n");
		return (0);
	}
	i = -1;
	while (++i < num_of_philo)
	{
		philos[i] = malloc(sizeof(t_philo));
		if (!philos[i])
			return (0);
		philos[i]->id = i + 1;
		if (i == 0)
			philos[i]->l_fork = &(info->forks[num_of_philo]);
		else
			philos[i]->l_fork = &(info->forks[i - 1]);
		philos[i]->r_fork = &(info->forks[i]);
		philos[i]->info = info;
	}
	return (philos);
}

void	*intro_print(void *param)
{
	t_philo	*philo;

	philo = (t_philo *)param;
	printf("[%d] >> I'm created philo: %d\n\n", philo->id, philo->thread);
	return (NULL);
}

int	routine_philo(t_info *info, t_philo **philo)
{
	int 	i;

	i = info->num_of_philo;
	while (i-- >= 0)
	{
		if ((pthread_create(&(philo[i]->thread), NULL, intro_print, (void *)philo[i])) < 0)
		{
			printf("philo create error!\n");
			return (0);
		}
		printf("%d : this is main. >> I just create %d:philo\n", pthread_self(), philo[i]->thread);
		usleep(100);
	}
	return (1);
}
