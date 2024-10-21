/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_philos.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrodrigu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/26 19:28:37 by yrodrigu          #+#    #+#             */
/*   Updated: 2024/10/21 18:16:11 by yrodrigu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "philo.h"

void	init_philo_values(t_philo *philos, char **argv)
{
	size_t i;
	size_t total_philo;

	i = 0;
	total_philo = ft_atoi(argv[1]);
	while(i < total_philo)
	{
		philos[i].num_of_philos = total_philo;
		philos[i].time_to_die = ft_atoi(argv[2]);
		philos[i].time_to_eat = ft_atoi(argv[3]);
		philos[i].time_to_sleep = ft_atoi(argv[4]);
		philos[i].id = i + 1;
		philos[i].right_fork = &philos[i].id;
		philos[i].left_fork = &philos[i - 1].id;
		philos[0].left_fork = &philos[total_philo - 1].id;
		if (argv[5])
			philos[i].meals_per_philo = ft_atoi(argv[5]);
		else
			philos[i].meals_per_philo = -1;
		i++;
	}
	for(size_t i = 0; i < total_philo; i++)
	{
		printf("from %zu I am philo %zu and my left %zu and right %zu\n", philos[i].num_of_philos, philos[i].id, *(philos[i]).left_fork, *(philos[i]).right_fork);
	}
}
