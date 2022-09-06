#include "../philosophers.h"

int	alert_die(t_philo *philo, int id, int flag)
{
	long start_time;

	start_time = philo->info->start_time;
	pthread_mutex_lock(&(philo->info->printer));
	printf("%6ld | %4d is died\n", count_time(start_time), id);
	if (flag == 1)
		pthread_mutex_unlock(&(philo->info->printer));
	else
		return (free_return(philo->info, philo, 0));
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
			if (get_time() > philo[i].last_eat_time &&
			count_time(philo[i].last_eat_time) > philo->info->time_to_die)
				return (alert_die(philo, i, 0));
			else if (philo[i].count_eat == 0)
				alert_die(philo, i, 1);
			sum_count_eat += philo[i].count_eat;
		}
		if (sum_count_eat == 0)
			return (free_return(philo->info, philo, 0));
	}
}