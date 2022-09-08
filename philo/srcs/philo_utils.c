/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sumsong <sumsong@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/06 20:42:19 by sumsong           #+#    #+#             */
/*   Updated: 2022/09/06 22:13:24 by sumsong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philosophers.h"

int	ft_strlen(char *str)
{
	int	len;

	len = 0;
	while (str[len])
		++len;
	return (len);
}

int	ft_atoi(char *str)
{
	int	str_len;
	int	num;
	int	i;

	str_len = ft_strlen(str);
	num = 0;
	i = 0;
	while (str_len >= 1)
	{
		if (str[i] - '0' < 0 || 9 < str[i] - '0')
			return (-1);
		num = num * 10 + str[i] - '0';
		--str_len;
		++i;
	}
	return (num);
}

long	get_time(void)
{
	struct timeval	time;
	long			ms;

	gettimeofday(&time, NULL);
	ms = time.tv_sec * 1000 + time.tv_usec / 1000;
	return (ms);
}

long	count_time(long start_time)
{
	struct timeval	current;
	long			ms;

	gettimeofday(&current, NULL);
	ms = (current.tv_sec * 1000 + current.tv_usec / 1000) - start_time;
	return (ms);
}

void	usleep_while(long time_to_act)
{
	long	start;
	long	time_diff;

	start = get_time();
	time_diff = count_time(start);
	while (time_diff < time_to_act)
	{
		usleep(100);
		time_diff = count_time(start);
	}
}
