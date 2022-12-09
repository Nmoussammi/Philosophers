/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   begin.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmoussam <nmoussam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/04 17:01:18 by nmoussam          #+#    #+#             */
/*   Updated: 2022/12/07 20:37:25 by nmoussam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_init_philos(t_philos *philos, t_infos *info)
{
	int		i;
	long	start;

	i = 0;
	start = ft_get_time_now();
	if (info->nb_eat > 0)
		info->must_eat = info->nb_eat * info->nb_philos;
	while (i < info->nb_philos)
	{
		philos[i].id = i + 1;
		philos[i].info = info;
		philos[i].died = 0;
		philos[i].start = start;
		i++;
	}
}

int	ft_begin(t_infos *info, pthread_mutex_t *forks)
{
	t_philos	*philos;
	int			i;

	philos = malloc(sizeof(t_philos) * info->nb_philos);
	if (!philos)
		return (0);
	pthread_mutex_init(&info->msg, NULL);
	ft_init_philos(philos, info);
	i = -1;
	while (++i < info->nb_philos)
	{
		get_forks(&philos[i], i, forks, info->nb_philos);
		if (pthread_create(&philos[i].ph, NULL, &routine, &philos[i]) != 0)
			return (0);
		usleep(100);
	}
	i = -1;
	while (++i < info->nb_philos)
	{
		if (pthread_detach(philos[i].ph) != 0)
			return (0);
	}
	if (check_philos(info, philos, forks) == 0)
		return (0);
	return (1);
}
