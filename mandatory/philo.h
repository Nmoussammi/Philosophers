/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmoussam <nmoussam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 14:05:13 by nmoussam          #+#    #+#             */
/*   Updated: 2022/12/07 19:54:26 by nmoussam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H
# include <stdio.h>
# include <unistd.h>
# include <string.h>
# include <stdlib.h>
# include <pthread.h>
# include <sys/time.h>

typedef struct s_infos
{
	int				nb_philos;
	int				time_eat;
	int				time_sleep;
	int				time_die;
	int				nb_eat;
	int				must_eat;
	pthread_mutex_t	msg;
}	t_infos;

typedef struct s_philos
{
	t_infos			*info;
	int				id;
	long			last_meal;
	int				died;
	long			start;
	pthread_mutex_t	*left_fork;
	pthread_mutex_t	*right_fork;
	pthread_t		ph;
}	t_philos;

int				ft_check_args(char **argv);
int				ft_init_args(int argc, char **argv, t_infos *info);
int				ft_atoi(const char *str);
pthread_mutex_t	*ft_init_mutex(t_infos *info);
void			get_forks(t_philos *philos, int id, pthread_mutex_t *fork, \
int nb_philo);
void			ft_init_philos(t_philos *philos, t_infos *info);
long			ft_get_time_now(void);
void			ft_usleep(int time, t_philos *philos);
void			print_msg(t_philos *philos, char *msg);
int				pickup_forks(t_philos *philos);
int				eating(t_philos *philos);
int				sleeping_thinking(t_philos *philos);
void			*routine(void *args);
int				ft_begin(t_infos *info, pthread_mutex_t *forks);
int				check_philos(t_infos *infos, t_philos *philos, \
				pthread_mutex_t *forks);
int				check_end(t_philos *philos, t_infos *infos);
int				check_meals(t_philos *philos);
int				philo_died(t_philos *philos);

#endif