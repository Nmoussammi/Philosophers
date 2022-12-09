/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmoussam <nmoussam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 01:43:01 by nmoussam          #+#    #+#             */
/*   Updated: 2022/12/07 05:26:24 by nmoussam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

long	ft_get_time_now(void)
{
	struct timeval	tp;
	long			ms;

	gettimeofday(&tp, NULL);
	ms = (tp.tv_sec * 1000) + (tp.tv_usec / 1000);
	return (ms);
}

void	print_msg(t_philos *philo, char *msg)
{
	long	time;

	time = ft_get_time_now() - philo->start;
	printf("%ldms philo %d %s\n", time, philo->id, msg);
}

void	ft_usleep(int time)
{
	long	start;

	start = ft_get_time_now();
	while (((ft_get_time_now() - start) < time))
		usleep(100);
}
