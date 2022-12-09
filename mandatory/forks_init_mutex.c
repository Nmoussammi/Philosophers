/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   forks_init_mutex.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmoussam <nmoussam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/04 17:29:17 by nmoussam          #+#    #+#             */
/*   Updated: 2022/12/05 16:10:11 by nmoussam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

pthread_mutex_t	*ft_init_mutex(t_infos *info)
{
	int				i;
	pthread_mutex_t	*forks;

	i = 0;
	forks = malloc(sizeof(pthread_mutex_t) * info->nb_philos);
	if (!forks)
		return (0);
	while (i < info->nb_philos)
	{
		if (pthread_mutex_init(&forks[i], NULL) != 0)
			return (0);
		i++;
	}
	return (forks);
}

void	get_forks(t_philos *philos, int id, pthread_mutex_t *fork, int nb_philo)
{
	if (id == 0)
	{
		philos->left_fork = &fork[nb_philo - 1];
		philos->right_fork = &fork[0];
	}
	else
	{
		philos->left_fork = &fork[id - 1];
		philos->right_fork = &fork[id];
	}
}
