#include "philosophers.h"

double	get_time(void)
{
	struct timeval	time;
	double			ms;

	gettimeofday(&time, NULL);
	ms = time.tv_sec * 1000 + time.tv_usec / 1000;
	return (ms);
}

double	count_time(double start_time)
{
	struct timeval	current;
	double			ms;

	gettimeofday(&current, NULL);
	ms = (current.tv_sec * 1000 + current.tv_usec / 1000) - start_time;
	return (ms);
}

void	grab_fork(t_philo *philo)
{
	double	start_time;
	double	eat_start_time;

	start_time = get_time();
	if (philo->id % 2 == 0)
	{
		pthread_mutex_lock(philo->l_fork);
		printf("%ld :%d has taken a left fork\n", count_time(start_time), philo->id);
		pthread_mutex_lock(philo->r_fork);
		printf("%ld :%d has taken a right fork\n", count_time(start_time), philo->id);
	}
	else
	{
		pthread_mutex_lock(philo->r_fork);
		printf("%ld :%d has taken a right fork\n", count_time(start_time), philo->id);
		pthread_mutex_lock(philo->l_fork);
		printf("%ld :%d has taken a left fork\n", count_time(start_time), philo->id);
	}
	eat_start_time = get_time();
	printf("%ld :%d is eating\n", count_time(start_time), philo->id);
	usleep(philo->info->time_to_eat);
	pthread_mutex_unlock(philo->l_fork);
	pthread_mutex_unlock(philo->r_fork);
}

void	*philo_routine(void *param)
{
	t_philo	*philo;

	philo = (t_philo *)param;
	printf("[%d] philo create.\n\n", philo->id, philo->thread);
	usleep(10);
	grab_fork(philo);
	return (NULL);
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
		printf("main >> create philo: %d\n", philo[i]->id);
		pthread_detach(philo[i]->thread);
//		pthread_join(philo[i]->thread, NULL);
	}
	while (1)
		;
	return (1);
}
