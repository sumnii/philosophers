/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arg_invalid_check.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sumsong <sumsong@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/06 20:42:07 by sumsong           #+#    #+#             */
/*   Updated: 2022/09/06 20:46:34 by sumsong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philosophers.h"

int	arg_count_check(int argc)
{
	if (argc != 5 && argc != 6)
	{
		printf("philo needs 4 or 5 arguments.\n");
		return (1);
	}
	return (0);
}

int	arg_is_num_check(char *argv[])
{
	int	i;

	i = 1;
	while (argv[i])
	{
		if (ft_atoi(argv[i]) == -1)
		{
			printf("argument isn't number.");
			return (1);
		}
		++i;
	}
	return (0);
}

int	arg_invalid_check(int argc, char *argv[])
{
	if (arg_count_check(argc))
		return (1);
	else if (arg_is_num_check(argv))
		return (1);
	return (0);
}
