/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sumsong <sumsong@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/06 20:42:23 by sumsong           #+#    #+#             */
/*   Updated: 2022/09/09 12:20:29 by sumsong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

# include <stdio.h>
# include <stdlib.h>
# include <pthread.h>
# include <unistd.h>
# include <sys/time.h>
# include <time.h>

enum e_status {
	LEFT_FORK,
	RIGHT_FORK,
	EAT,
	SLEEP,
	THINK
};

typedef struct s_info {
	int				num_of_philo;
	long			time_to_die;
	long			time_to_eat;
	long			time_to_sleep;
	int				must_eat;
	long			start_time;
	pthread_mutex_t	printer;
	pthread_mutex_t	*forks;
	pthread_mutex_t	eat_status;
}				t_info;

typedef struct s_philo {
	pthread_t		thread;
	int				id;
	int				count_eat;
	long			last_eat_time;
	pthread_mutex_t	*l_fork;
	pthread_mutex_t	*r_fork;
	t_info			*info;
}				t_philo;

int		ft_strlen(char *str);
int		ft_atoi(char *str);
long	get_time(void);
long	count_time(long start_time);
void	usleep_while(long time_to_act);

int		arg_count_check(int argc);
int		arg_is_num_check(char *argv[]);
int		arg_invalid_check(int argc, char *argv[]);

int		put_arg(t_info *info, char *argv[]);
t_info	*init_info(char *argv[]);
t_philo	*init_philo(t_info *info, int num_of_philo);

void	philo_eat_odd(t_philo *philo);
void	philo_eat_even(t_philo *philo);
void	philo_sleep(t_philo *philo);
void	philo_think(t_philo *philo);
void	philo_routine(void *philo);

void	print_status(t_philo *philo, int status);

int		alert_die(t_philo *philo, int idx);
int		monitoring(t_philo *philo);

int		create_thread(t_info *info, t_philo *philo);
int		free_return(t_info *info, t_philo *philo, int return_flag);

#endif