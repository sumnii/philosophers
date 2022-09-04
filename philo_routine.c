#include "philosophers.h"

void	grab_fork(t_philo *philo)
{
	if (philo->id % 2 == 0)
	{
		pthread_mutex_lock(philo->l_fork);
		printf("%d philo grab the Left fork.\n", philo->id);
		pthread_mutex_lock(philo->r_fork);
		printf("%d philo grab the Right fork.\n", philo->id);
	}
	else
	{
		pthread_mutex_lock(philo->r_fork);
		printf("%d philo grab the Right fork.\n", philo->id);
		pthread_mutex_lock(philo->l_fork);
		printf("%d philo grab the Left fork.\n", philo->id);
	}
	printf("\n%d philo starts eat\n\n", philo->id);
//	usleep(100);
	pthread_mutex_unlock(philo->l_fork);
	pthread_mutex_unlock(philo->r_fork);
}

void	*philo_routine(void *param)
{
	t_philo	*philo;

	philo = (t_philo *)param;
	printf("[%d] >> I'm created philo: %d\n\n", philo->id, philo->thread);
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
		printf("%d : this is main.\n>> I just create philo: %d\n", pthread_self(), philo[i]->thread);
		pthread_join(philo[i]->thread, NULL);
//		usleep(100);
	}
	return (1);
}
