/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmoussam <nmoussam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 00:54:25 by nmoussam          #+#    #+#             */
/*   Updated: 2022/12/07 20:01:01 by nmoussam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

int	ft_atoi(const char *str)
{
	int			i;
	long int	resultat;
	int			sign;

	i = 0;
	sign = 1;
	resultat = 0;
	while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		resultat = resultat * 10 + (int)(str[i] - '0');
		i++;
	}
	return (sign * resultat);
}

int	ft_check_args(char **argv)
{
	int	i;
	int	j;

	i = 1;
	while (argv[i])
	{
		j = 0;
		while (argv[i][j])
		{
			if (argv[i][j] > '9' || argv[i][j] < '0')
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

void	*eating_checker(void *arg)
{
	t_philos	*philo;
	int			i;

	philo = (t_philos *)arg;
	i = -1;
	sem_wait(philo->msg);
	while (++i < philo->info.nb_philos)
	{
		sem_post(philo->msg);
		sem_wait(philo->eat);
		sem_wait(philo->msg);
	}
	sem_post(philo->died);
	return (NULL);
}

int	create_thread(t_philos *philo)
{
	if (philo->info.nb_eat)
	{
		if (pthread_create(&philo->ph_eat, NULL, &eating_checker, philo) != 0)
		{
			printf("Error pthread creation");
			return (1);
		}
		pthread_detach(philo->ph_eat);
	}
	return (0);
}

int	ft_init_args(int argc, char **argv, t_philos *philo)
{
	philo->info.nb_philos = ft_atoi(argv[1]);
	philo->info.time_die = ft_atoi(argv[2]);
	philo->info.time_eat = ft_atoi(argv[3]);
	philo->info.time_sleep = ft_atoi(argv[4]);
	philo->info.nb_eat = -1;
	philo->pids = malloc(sizeof(pid_t) * philo->info.nb_philos);
	if (!philo->pids)
		return (0);
	if (argc == 6)
	{
		philo->info.nb_eat = ft_atoi(argv[5]);
		if (philo->info.nb_eat <= 0)
			return (printf("Invalid Arguments !!"), 0);
	}
	if (philo->info.nb_philos <= 0 || philo->info.time_eat <= 0 || \
	philo->info.time_sleep <= 0 || philo->info.time_die <= 0)
		return (printf("Invalid Arguments !!"), 0);
	init_semaphores(philo);
	create_thread(philo);
	return (1);
}
