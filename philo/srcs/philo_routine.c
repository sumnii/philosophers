/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_routine.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sumsong <sumsong@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/06 20:42:17 by sumsong           #+#    #+#             */
/*   Updated: 2022/09/08 12:15:33 by sumsong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philosophers.h"

void	philo_eat_odd(t_philo *philo)
{
	pthread_mutex_lock(philo->r_fork);
	print_status(philo, RIGHT_FORK);
	pthread_mutex_lock(philo->l_fork);
	print_status(philo, LEFT_FORK);
	++(philo->count_eat);
	philo->last_eat_time = get_time();
	print_status(philo, EAT);
	usleep_while(philo->info->time_to_eat);
	pthread_mutex_unlock(philo->r_fork);
	pthread_mutex_unlock(philo->l_fork);
}

void	philo_eat_even(t_philo *philo)
{
	pthread_mutex_lock(philo->l_fork);
	print_status(philo, LEFT_FORK);
	pthread_mutex_lock(philo->r_fork);
	print_status(philo, RIGHT_FORK);
	++(philo->count_eat);
	philo->last_eat_time = get_time();
	print_status(philo, EAT);
	usleep_while(philo->info->time_to_eat);
	pthread_mutex_unlock(philo->l_fork);
	pthread_mutex_unlock(philo->r_fork);
}

void	philo_sleep(t_philo *philo)
{
	print_status(philo, SLEEP);
	usleep_while(philo->info->time_to_sleep);
}

void	philo_think(t_philo *philo)
{
	print_status(philo, THINK);
	usleep(200);
}

void	philo_routine(void *param)
{
	t_philo	*philo;

	philo = (t_philo *)param;
	while (1)
	{
		if (philo->id % 2 == 0)
			philo_eat_even(philo);
		else
			philo_eat_odd(philo);
		philo_sleep(philo);
		philo_think(philo);
	}
}
