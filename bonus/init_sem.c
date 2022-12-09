/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_sem.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmoussam <nmoussam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 21:37:52 by nmoussam          #+#    #+#             */
/*   Updated: 2022/12/07 20:01:32 by nmoussam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	init_semaphores(t_philos *philo)
{
	sem_unlink("forks");
	sem_unlink("msg");
	sem_unlink("died");
	sem_unlink("eat");
	philo->forks = sem_open("forks", O_CREAT | O_EXCL, S_IRWXU, \
	philo->info.nb_philos);
	philo->msg = sem_open("msg", O_CREAT | O_EXCL, S_IRWXU, 1);
	philo->died = sem_open("died", O_CREAT | O_EXCL, S_IRWXU, 0);
	if (philo->info.nb_eat)
		philo->eat = sem_open("eat", O_CREAT | O_EXCL, S_IRWXU, 0);
}
