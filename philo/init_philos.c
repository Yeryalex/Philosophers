/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_philos.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrodrigu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/26 19:28:37 by yrodrigu          #+#    #+#             */
/*   Updated: 2024/10/09 21:09:28 by yrodrigu         ###   ########.fr       */
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
		i++;
	}
	i = 0;
	while (i < total_philo)
	{
		printf("Among all %zu philos, I am number %zu! and %zu %zu %zu\n", philos[i].num_of_philos, philos[i].id, philos[i].time_to_die, philos[i].time_to_eat, philos[i].time_to_sleep);
		i++;
	}
}
//testing  philo for threads!
