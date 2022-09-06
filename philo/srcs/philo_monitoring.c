#include "../philosophers.h"

int	alert_die(t_philo *philo, int idx, int flag)
{
	long start_time;

	if (philo[idx].die_alerted == 1)
		return (0);
	start_time = philo->info->start_time;
	pthread_mutex_lock(&(philo->info->printer));
	printf("%6ld | %3d is died", count_time(start_time), philo[idx].id);
	philo[idx].die_alerted = 1;
	if (flag == 1)
	{
		printf("    because eat %d times.\n", 15 - philo[idx].count_eat);
		pthread_mutex_unlock(&(philo->info->printer));
	}
	else
	{
		printf("    because of hunger.\n");
		return (free_return(philo->info, philo, 0));
	}
	return (0);
}

int	monitoring(t_philo *philo)
{
	int		i;
	int		sum_count_eat;

	while (1)
	{
		sum_count_eat = 0;
		i = -1;
		while (++i < philo->info->num_of_philo)
		{
			if (count_time(philo[i].last_eat_time) > philo->info->time_to_die)
				return (alert_die(philo, i, 0));
			else if (philo[i].count_eat == 0)
				alert_die(philo, i, 1);
			else
				sum_count_eat += philo[i].count_eat;
		}
		if (sum_count_eat == 0)
		{
			printf("%6ld |   all philosphers finished eating\n", count_time(philo->info->start_time));
			return (free_return(philo->info, philo, 0));
		}
	}
}