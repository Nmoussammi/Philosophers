/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmoussam <nmoussam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 17:16:07 by nmoussam          #+#    #+#             */
/*   Updated: 2022/12/07 21:19:03 by nmoussam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_BONUS_H
# define PHILO_BONUS_H
# include <stdio.h>
# include <unistd.h>
# include <string.h>
# include <stdlib.h>
# include <pthread.h>
# include <sys/time.h>
# include <semaphore.h>
# include <sys/stat.h>
# include <sys/wait.h>
# include <sys/types.h>
# include <signal.h>

typedef struct s_infos
{
	int				nb_philos;
	int				time_eat;
	int				time_sleep;
	int				time_die;
	int				nb_eat;
}	t_infos;

typedef struct s_philos
{
	t_infos			info;
	sem_t			*forks;
	sem_t			*msg;
	sem_t			*died;
	sem_t			*eat;
	pid_t			*pids;
	int				id;
	long			last_meal;
	long			start;
	int				nb_meals;
	pthread_t		ph;
	pthread_t		ph_eat;
}			t_philos;

int		ft_check_args(char **argv);
int		ft_init_args(int argc, char **argv, t_philos *philo);
void	init_semaphores(t_philos *philo);
long	ft_get_time_now(void);
int		ft_begin(t_philos *philo);
void	checker_and_routine(t_philos *philo);
void	*checker(void *arg);
void	*routine(void *args);
void	pickup_forks(t_philos *philo);
void	print_msg(t_philos *philo, char *msg);
void	ft_usleep(int time);
void	eating(t_philos *philo);
void	sleeping_thinking(t_philos *philo);
void	kill_philosophers(t_philos *philo);
int		create_thread(t_philos *philo);
void	*eating_checker(void *arg);

#endif