#include "philosophers.h"

int put_arg(t_info *info, char *argv[])
{
	printf("info size : %d\n", sizeof(t_info));
	info->num_of_philo = ft_atoi(argv[1]);
	info->time_to_die = ft_atoi(argv[2]);
	info->time_to_eat = ft_atoi(argv[3]);
	info->time_to_sleep = ft_atoi(argv[4]);
	if (argv[5])
		info->must_eat = ft_atoi(argv[5]);
	return (1);
}

t_info *initialize(char *argv[])
{
	t_info	*info;

	info = malloc(sizeof(t_info));
	if (!info)
	{
		printf("malloc error!\n");
		return (0);
	}
	if (!put_arg(info, argv))
		return (0);
	return (info);
}