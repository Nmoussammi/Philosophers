/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmoussam <nmoussam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/04 16:58:14 by nmoussam          #+#    #+#             */
/*   Updated: 2022/12/05 16:18:51 by nmoussam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

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

long	ft_get_time_now(void)
{
	struct timeval	tp;
	long			ms;

	gettimeofday(&tp, NULL);
	ms = (tp.tv_sec * 1000) + (tp.tv_usec / 1000);
	return (ms);
}

void	ft_usleep(int time, t_philos *philos)
{
	long	start;

	start = ft_get_time_now();
	while (((ft_get_time_now() - start) <= time) && philos->died == 0)
		usleep(100);
}

void	print_msg(t_philos *philos, char *msg)
{
	long	time;

	time = ft_get_time_now() - philos->start;
	printf("%ldms philo %d %s\n", time, philos->id, msg);
}
