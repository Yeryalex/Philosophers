/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_philos.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrodrigu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/26 19:28:37 by yrodrigu          #+#    #+#             */
/*   Updated: 2024/10/16 14:43:16 by yrodrigu         ###   ########.fr       */
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
/*	i = 0;
	while (i < total_philo)
	{
		   printf("I AM philo number %zu with right fork %zu and left fork %zu\n", philos[i].id, *(philos[i]).right_fork, *(philos[i]).left_fork);
		i++;
	}*/
}
