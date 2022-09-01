#ifndef PHILOSOPHERS_H
#define PHILOSOPHERS_H

#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>

typedef struct s_info {
	int num_of_philo;
	int time_to_die;
	int time_to_eat;
	int time_to_sleep;
	int must_eat;
	int *forks;
}				t_info;

typedef struct s_philo {
	pthread_t	thread;
	int			id;
}			t_philo;

int 	ft_strlen(char *str);
int 	ft_atoi(char *str);

int		arg_count_check(int argc);
int 	arg_is_num_check(char *argv[]);
int		arg_invalid_check(int argc, char *argv[]);

int 	put_arg(t_info *info, char *argv[]);
t_info *initialize(char *argv[]);

#endif PHILOSOPHERS_H
