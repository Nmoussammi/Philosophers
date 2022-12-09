/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmoussam <nmoussam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 01:45:02 by nmoussam          #+#    #+#             */
/*   Updated: 2022/12/07 05:22:04 by nmoussam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	pickup_forks(t_philos *philo)
{
	sem_wait(philo->forks);
	sem_wait(philo->forks);
	sem_wait(philo->msg);
	print_msg(philo, "has taken a fork 🍴");
	print_msg(philo, "has taken a fork 🍴");
	sem_post(philo->msg);
}

void	eating(t_philos *philo)
{
	sem_wait(philo->msg);
	print_msg(philo, "is eating 🍝");
	sem_post(philo->msg);
	philo->last_meal = ft_get_time_now();
	philo->nb_meals++;
	if (philo->nb_meals == philo->info.nb_eat)
		sem_post(philo->eat);
	ft_usleep(philo->info.time_eat);
	sem_post(philo->forks);
	sem_post(philo->forks);
}

void	sleeping_thinking(t_philos *philo)
{
	sem_wait(philo->msg);
	print_msg(philo, "is sleeping 😴");
	sem_post(philo->msg);
	ft_usleep(philo->info.time_sleep);
	sem_wait(philo->msg);
	print_msg(philo, "is thinking 🤔");
	sem_post(philo->msg);
}

void	*routine(void *args)
{
	t_philos		*philo;

	philo = (t_philos *)args;
	philo->last_meal = ft_get_time_now();
	while (1)
	{
		pickup_forks(philo);
		eating(philo);
		sleeping_thinking(philo);
	}
	return (NULL);
}
