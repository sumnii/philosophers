#include "../philosophers.h"

void	philo_eat(t_philo *philo)
{
	long	start_time;
//	long	eat_start_time;

	start_time = philo->info->start_time;
	if (philo->id % 2 == 0)
	{
		pthread_mutex_lock(philo->l_fork);
		pthread_mutex_lock(&(philo->info->printer));
		printf("%6ld : %4d has taken a left fork\n", count_time(start_time), philo->id);
		pthread_mutex_unlock(&(philo->info->printer));
		pthread_mutex_lock(philo->r_fork);
		pthread_mutex_lock(&(philo->info->printer));
		printf("%6ld : %4d has taken a right fork\n", count_time(start_time), philo->id);
		pthread_mutex_unlock(&(philo->info->printer));
	}
	else
	{
		pthread_mutex_lock(philo->r_fork);
		pthread_mutex_lock(&(philo->info->printer));
		printf("%6ld : %4d has taken a right fork\n", count_time(start_time), philo->id);
		pthread_mutex_unlock(&(philo->info->printer));
		pthread_mutex_lock(philo->l_fork);
		pthread_mutex_lock(&(philo->info->printer));
		printf("%6ld : %4d has taken a left fork\n", count_time(start_time), philo->id);
		pthread_mutex_unlock(&(philo->info->printer));
	}
//	eat_start_time = get_time();
	pthread_mutex_lock(&(philo->info->printer));
	--philo->count_eat;
	printf("%6ld : %4d is eating\n", count_time(start_time), philo->id);
	pthread_mutex_unlock(&(philo->info->printer));
	usleep_while(philo->info->time_to_eat);
	pthread_mutex_unlock(philo->l_fork);
	pthread_mutex_unlock(philo->r_fork);
}

void	philo_sleep(t_philo *philo)
{
	long start_time;

	start_time = philo->info->start_time;
	pthread_mutex_lock(&(philo->info->printer));
	printf("%6ld : %4d is sleeping\n", count_time(start_time), philo->id);
	pthread_mutex_unlock(&(philo->info->printer));
	usleep_while(philo->info->time_to_sleep);
}

void	*philo_routine(void *param)
{
	t_philo	*philo;

	philo = (t_philo *)param;
//	printf("[%4d] philo create.\n\n", philo->id);
	while (1)
	{
		philo_eat(philo);
		if (philo->count_eat == 0)
			return (NULL);
		philo_sleep(philo);
	}
}

int	create_thread(t_info *info, t_philo **philo)
{
	int 	i;

	i = info->num_of_philo;
	while (--i >= 0)
	{
		if ((pthread_create(&(philo[i]->thread), NULL, philo_routine, (void *)philo[i])) < 0)
		{
			printf("philo create error!\n");
			return (0);
		}
//		printf("main >> create philo: %4d\n", philo[i]->id);
		pthread_detach(philo[i]->thread);
//		pthread_join(philo[i]->thread, NULL);
	}
	while (1)
		;
	return (1);
}
