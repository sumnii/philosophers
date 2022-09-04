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
	pthread_mutex_t *forks;
}				t_info;

typedef struct s_philo {
	pthread_t		thread;
	int 			id;
	pthread_mutex_t *l_fork;
	pthread_mutex_t *r_fork;
	t_info			*info;
}				t_philo;

int 	ft_strlen(char *str);
int 	ft_atoi(char *str);

int		arg_count_check(int argc);
int 	arg_is_num_check(char *argv[]);
int		arg_invalid_check(int argc, char *argv[]);

int 	put_arg(t_info *info, char *argv[]);
t_info	*init_info(char *argv[]);
t_philo	*init_philo(t_info *info, int num_of_philo);
void	*intro_print(void *param);
int		routine_philo(t_info *info, t_philo *philo);

int		free_return(t_info *info, t_philo *philo, int return_flag);

#endif PHILOSOPHERS_H