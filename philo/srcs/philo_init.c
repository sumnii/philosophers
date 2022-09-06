/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sumsong <sumsong@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/06 20:42:12 by sumsong           #+#    #+#             */
/*   Updated: 2022/09/06 20:46:25 by sumsong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philosophers.h"

int	put_arg(t_info *info, char *argv[])
{
	int	i;

	info->num_of_philo = ft_atoi(argv[1]);
	info->time_to_die = ft_atoi(argv[2]);
	info->time_to_eat = ft_atoi(argv[3]);
	info->time_to_sleep = ft_atoi(argv[4]);
	if (argv[5])
		info->must_eat = ft_atoi(argv[5]);
	else
		info->must_eat = -1;
	info->start_time = get_time();
	pthread_mutex_init(&(info->printer), NULL);
	info->forks = malloc(sizeof(pthread_mutex_t) * info->num_of_philo);
	if (!info->forks)
		return (0);
	i = -1;
	while (++i < info->num_of_philo)
		pthread_mutex_init(&((info->forks)[i]), NULL);
	return (1);
}

t_info	*init_info(char *argv[])
{
	t_info	*info;

	info = malloc(sizeof(t_info));
	if (!info)
		return (0);
	if (!put_arg(info, argv))
		return (0);
	return (info);
}

t_philo	*init_philo(t_info *info, int num_of_philo)
{
	t_philo	*philos;
	int		i;

	philos = (t_philo *)malloc(sizeof(t_philo) * num_of_philo);
	if (!philos)
		return (0);
	i = -1;
	while (++i < num_of_philo)
	{
		philos[i].id = i + 1;
		philos[i].count_eat = 0;
		philos[i].last_eat_time = get_time();
		philos[i].die_alerted = 0;
		if (i == 0)
			philos[i].l_fork = &(info->forks[num_of_philo - 1]);
		else
			philos[i].l_fork = &(info->forks[i - 1]);
		philos[i].r_fork = &(info->forks[i]);
		philos[i].info = info;
	}
	return (philos);
}
