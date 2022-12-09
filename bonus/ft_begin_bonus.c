/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_begin_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmoussam <nmoussam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 22:28:15 by nmoussam          #+#    #+#             */
/*   Updated: 2022/12/07 05:10:07 by nmoussam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	kill_philosophers(t_philos *philo)
{
	int	i;

	i = 0;
	while (i < philo->info.nb_philos)
	{
		kill(philo->pids[i], SIGKILL);
		i++;
	}
	free(philo->pids);
}

void	checker_and_routine(t_philos *philo)
{
	philo->last_meal = ft_get_time_now();
	if (pthread_create(&philo->ph, NULL, &checker, philo) != 0)
	{
		printf("Erreur pthread create\n");
		sem_post(philo->died);
	}
	pthread_detach(philo->ph);
	routine(philo);
}

int	ft_begin(t_philos *philo)
{
	int	i;

	i = 0;
	philo->start = ft_get_time_now();
	while (i < philo->info.nb_philos)
	{
		philo->id = i + 1;
		philo->pids[i] = fork();
		if (philo->pids[i] == -1)
		{
			while (--i >= 0)
				kill(philo->pids[i], SIGKILL);
			return (0);
		}
		else if (philo->pids[i] == 0)
			checker_and_routine(philo);
		i++;
	}
	sem_wait(philo->died);
	return (1);
}
