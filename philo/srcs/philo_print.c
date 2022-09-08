/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_print.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sumsong <sumsong@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/06 22:14:16 by sumsong           #+#    #+#             */
/*   Updated: 2022/09/08 12:15:43 by sumsong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philosophers.h"

void	print_status(t_philo *philo, int status)
{
	long	start;
	int		id;

	start = philo->info->start_time;
	id = philo->id;
	pthread_mutex_lock(&(philo->info->printer));
	if (status == LEFT_FORK)
		printf("%6ld | %3d has taken a left fork\n", count_time(start), id);
	else if (status == RIGHT_FORK)
		printf("%6ld | %3d has taken a right fork\n", count_time(start), id);
	else if (status == EAT)
		printf("%6ld | %3d is eating\n", count_time(start), id);
	else if (status == SLEEP)
		printf("%6ld | %3d is sleeping\n", count_time(start), philo->id);
	else if (status == THINK)
		printf("%6ld | %3d is thinking\n", count_time(start), philo->id);
	pthread_mutex_unlock(&(philo->info->printer));
}
