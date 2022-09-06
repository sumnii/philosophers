#ifndef PHILOSOPHERS_H
#define PHILOSOPHERS_H

#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>
#include <sys/time.h>
#include <time.h>

typedef struct s_info {
	int 			num_of_philo;
	int			 	time_to_die;
	int 			time_to_eat;
	int 			time_to_sleep;
	int 			must_eat;
	double			start_time;
	pthread_mutex_t *printer;
	pthread_mutex_t *forks;
}				t_info;

typedef struct s_philo {
	pthread_t		thread;
	int 			id;
	int 			count_eat;
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
t_philo	**init_philo(t_info *info, int num_of_philo);

double	get_time(void);
double	count_time(double start_time);
void	grab_fork(t_philo *philo);
void	*philo_routine(void *param);
int		create_thread(t_info *info, t_philo **philo);

int		free_return(t_info *info, t_philo **philo, int return_flag);

#endif PHILOSOPHERS_H