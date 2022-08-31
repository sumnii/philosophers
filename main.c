#include "philosophers.h"

void	*print()
{
	pthread_t id;

	id = pthread_self();
	printf("this is philo : %d\n", id);
}

int	main(int argc, char *argv[])
{
	t_info	info;
	t_philo philo;

//	info.num_of_philo = 1;
//	if ((pthread_create(&(philo.thread), NULL, print, &info)) < 0)
//	{
//		printf("create error!\n");
//		return (0);
//	}
//	printf("%d : philo\n%d : this is main.\n", philo.thread, pthread_self());
//	sleep(1);
//	return (0);
	if (arg_invalid_check(argc, argv))
		return (1);
//	initialize(argc, argv);
//	philosophers();
}