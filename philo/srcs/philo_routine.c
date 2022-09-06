#include "../philosophers.h"

void	philo_eat(t_philo *philo)
{
	long	start_time;

	start_time = philo->info->start_time;
	if (philo->id % 2 == 0)
	{
		pthread_mutex_lock(philo->l_fork);
		pthread_mutex_lock(&(philo->info->printer));
		printf("%6ld | %3d has taken a left fork\n", count_time(start_time), philo->id);
		pthread_mutex_unlock(&(philo->info->printer));
		pthread_mutex_lock(philo->r_fork);
		pthread_mutex_lock(&(philo->info->printer));
		printf("%6ld | %3d has taken a right fork\n", count_time(start_time), philo->id);
		pthread_mutex_unlock(&(philo->info->printer));
	}
	else
	{
		pthread_mutex_lock(philo->r_fork);
		pthread_mutex_lock(&(philo->info->printer));
		printf("%6ld | %3d has taken a right fork\n", count_time(start_time), philo->id);
		pthread_mutex_unlock(&(philo->info->printer));
		pthread_mutex_lock(philo->l_fork);
		pthread_mutex_lock(&(philo->info->printer));
		printf("%6ld | %3d has taken a left fork\n", count_time(start_time), philo->id);
		pthread_mutex_unlock(&(philo->info->printer));
	}
	--(philo->count_eat);
	pthread_mutex_lock(&(philo->info->printer));
	printf("%6ld | %3d is eating\n", count_time(start_time), philo->id);
	philo->last_eat_time = get_time();
	pthread_mutex_unlock(&(philo->info->printer));
	usleep_while(philo->info->time_to_eat);
//	philo->last_eat_time = get_time();
	pthread_mutex_unlock(philo->l_fork);
	pthread_mutex_unlock(philo->r_fork);
}

void	philo_sleep(t_philo *philo)
{
	long start_time;

	start_time = philo->info->start_time;
	pthread_mutex_lock(&(philo->info->printer));
	printf("%6ld | %3d is sleeping\n", count_time(start_time), philo->id);
	pthread_mutex_unlock(&(philo->info->printer));
	usleep_while(philo->info->time_to_sleep);
}

void	philo_think(t_philo *philo)
{
	long start_time;

	start_time = philo->info->start_time;
	pthread_mutex_lock(&(philo->info->printer));
	printf("%6ld | %3d is thinking\n", count_time(start_time), philo->id);
	pthread_mutex_unlock(&(philo->info->printer));
	usleep(200);
}

void	philo_routine(void *param)
{
	t_philo	*philo;

	philo = (t_philo *)param;
	while (philo->count_eat != 0)
	{
		philo_eat(philo);
		if (philo->count_eat == 0)
			break;
		philo_sleep(philo);
		philo_think(philo);
	}
}

int	create_thread(t_info *info, t_philo *philo)
{
	int 	i;

	i = info->num_of_philo;
	while (--i >= 0)
	{
		if ((pthread_create(&(philo[i].thread), NULL, (void *)philo_routine, &philo[i])) < 0)
		{
			printf("%3d philo create error!\n", i);
			return (0);
		}
		pthread_detach(philo[i].thread);
//		pthread_join(philo[i].thread, NULL);
	}
	return (1);
}
