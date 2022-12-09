/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_init_args.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmoussam <nmoussam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/04 16:58:03 by nmoussam          #+#    #+#             */
/*   Updated: 2022/12/06 02:00:26 by nmoussam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

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

int	ft_init_args(int argc, char **argv, t_infos *info)
{
	info->nb_philos = ft_atoi(argv[1]);
	info->time_die = ft_atoi(argv[2]);
	info->time_eat = ft_atoi(argv[3]);
	info->time_sleep = ft_atoi(argv[4]);
	info->nb_eat = -1;
	if (argc == 6)
	{
		info->nb_eat = ft_atoi(argv[5]);
		if (info->nb_eat <= 0)
			return (printf("Invalid Arguments !!"), 0);
	}
	if (info->nb_philos <= 0 || info->time_eat <= 0 || info->time_sleep <= 0
		|| info->time_die <= 0)
		return (printf("Invalid Arguments !!"), 0);
	return (1);
}
