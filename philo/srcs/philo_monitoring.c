/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_monitoring.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sumsong <sumsong@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/06 20:42:15 by sumsong           #+#    #+#             */
/*   Updated: 2022/09/06 20:43:54 by sumsong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philosophers.h"

int	alert_die(t_philo *philo, int idx)
{
	long	start_time;

	start_time = philo->info->start_time;
	pthread_mutex_lock(&(philo->info->printer));
	printf("%6ld | %3d is died\n", count_time(start_time), philo[idx].id);
	return (free_return(philo->info, philo, 0));
}

int	monitoring(t_philo *philo)
{
	int		i;
	int		count_full;
	int		must_eat;

	must_eat = philo->info->must_eat;
	while (1)
	{
		count_full = 0;
		i = -1;
		while (++i < philo->info->num_of_philo)
		{
			if (count_time(philo[i].last_eat_time) > philo->info->time_to_die)
				return (alert_die(philo, i));
			else if (must_eat != -1 && philo[i].count_eat >= must_eat)
				++count_full;
		}
		if (count_full == philo->info->num_of_philo)
			return (free_return(philo->info, philo, 0));
	}
}
