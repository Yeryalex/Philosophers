/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_philos.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrodrigu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/26 19:28:37 by yrodrigu          #+#    #+#             */
/*   Updated: 2024/10/08 17:13:30 by yrodrigu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "philo.h"

void	assign_philos(t_philo *philos, char **argv)
{
	t_philo philos[ft_atoi(argv[1])];
	size_t i;
	size_t total_philo;

	i = 0;
	total_philo = ft_atoi(argv[1]);
	while(i < total_philo)
	{
		philos[i].num_of_philos = total_philo;
		philos[i].id = i;
		i++;
	}
	i = 0;
	while (i < total_philo)
	{
		printf("Among all %zu philos, I am number %zu\n", philos[i].num_of_philos, philos[i].id);
		i++;
	}
}
