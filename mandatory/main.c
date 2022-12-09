/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmoussam <nmoussam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 14:05:08 by nmoussam          #+#    #+#             */
/*   Updated: 2022/12/06 02:00:40 by nmoussam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int argc, char **argv)
{
	t_infos			info;
	pthread_mutex_t	*forks;

	if ((argc != 5 && argc != 6) || ft_check_args(argv) == 0)
		return (printf("Invalid arguments !"), 0);
	if (ft_init_args(argc, argv, &info) == 0)
		return (0);
	forks = ft_init_mutex(&info);
	ft_begin(&info, forks);
}
