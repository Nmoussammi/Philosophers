/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmoussam <nmoussam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 17:16:28 by nmoussam          #+#    #+#             */
/*   Updated: 2022/12/07 21:18:44 by nmoussam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

int	main(int argc, char **argv)
{
	t_philos	philo;

	if ((argc != 5 && argc != 6) || ft_check_args(argv) == 0)
		return (printf("Invalid arguments !"), 0);
	if (ft_init_args(argc, argv, &philo) == 0)
		return (0);
	if (ft_begin(&philo) == 0)
		return (0);
	kill_philosophers(&philo);
	return (0);
}
