/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_routine.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sumsong <sumsong@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/06 20:42:17 by sumsong           #+#    #+#             */
/*   Updated: 2022/09/06 20:53:16 by sumsong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philosophers.h"

void	philo_eat_odd(t_philo *philo)
{
	long	start;
	int		id;

	start = philo->info->start_time;
	id = philo->id;
	pthread_mutex_lock(philo->r_fork);
	pthread_mutex_lock(&(philo->info->printer));
	printf("%6ld | %3d has taken a right fork\n", count_time(start), id);
	pthread_mutex_unlock(&(philo->info->printer));
	pthread_mutex_lock(philo->l_fork);
	pthread_mutex_lock(&(philo->info->printer));
	printf("%6ld | %3d has taken a left fork\n", count_time(start), id);
	pthread_mutex_unlock(&(philo->info->printer));
	--(philo->count_eat);
	pthread_mutex_lock(&(philo->info->printer));
	printf("%6ld | %3d is eating\n", count_time(start), id);
	philo->last_eat_time = get_time();
	pthread_mutex_unlock(&(philo->info->printer));
	usleep_while(philo->info->time_to_eat);
	pthread_mutex_unlock(philo->l_fork);
	pthread_mutex_unlock(philo->r_fork);
}

void	philo_eat_even(t_philo *philo)
{
	long	start;
	int		id;

	start = philo->info->start_time;
	id = philo->id;
	pthread_mutex_lock(philo->l_fork);
	pthread_mutex_lock(&(philo->info->printer));
	printf("%6ld | %3d has taken a left fork\n", count_time(start), id);
	pthread_mutex_unlock(&(philo->info->printer));
	pthread_mutex_lock(philo->r_fork);
	pthread_mutex_lock(&(philo->info->printer));
	printf("%6ld | %3d has taken a right fork\n", count_time(start), id);
	pthread_mutex_unlock(&(philo->info->printer));
	--(philo->count_eat);
	pthread_mutex_lock(&(philo->info->printer));
	printf("%6ld | %3d is eating\n", count_time(start), id);
	philo->last_eat_time = get_time();
	pthread_mutex_unlock(&(philo->info->printer));
	usleep_while(philo->info->time_to_eat);
	pthread_mutex_unlock(philo->l_fork);
	pthread_mutex_unlock(philo->r_fork);
}

void	philo_sleep(t_philo *philo)
{
	long	start_time;

	start_time = philo->info->start_time;
	pthread_mutex_lock(&(philo->info->printer));
	printf("%6ld | %3d is sleeping\n", count_time(start_time), philo->id);
	pthread_mutex_unlock(&(philo->info->printer));
	usleep_while(philo->info->time_to_sleep);
}

void	philo_think(t_philo *philo)
{
	long	start_time;

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
		if (philo->id % 2 == 0)
			philo_eat_even(philo);
		else
			philo_eat_odd(philo);
		if (philo->count_eat == 0)
			break ;
		philo_sleep(philo);
		philo_think(philo);
	}
}
