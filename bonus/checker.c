/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmoussam <nmoussam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 01:44:00 by nmoussam          #+#    #+#             */
/*   Updated: 2022/12/07 20:01:18 by nmoussam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	*checker(void *arg)
{
	t_philos	*philo;
	long		time_now;

	philo = (t_philos *)arg;
	while (1)
	{
		time_now = ft_get_time_now();
		if (time_now - philo->last_meal > philo->info.time_die)
		{
			sem_wait(philo->msg);
			print_msg(philo, "died ⚰️");
			sem_post(philo->died);
			exit(0);
		}
	}
	return (NULL);
}
