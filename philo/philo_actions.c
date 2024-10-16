/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_actions.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrodrigu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 21:58:57 by yrodrigu          #+#    #+#             */
/*   Updated: 2024/10/16 13:05:43 by yrodrigu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "philo.h"

void	*print_message(void *argument)
{
	t_philo	*philo;

	philo = (t_philo *)argument;
	printf("Hello, I am a philo %zu printing this function!\n", philo->id);
	return (0);
}

void	create_threads(t_philo *philos)
{
	int i;
	int total_philos;

	i = 0;
	total_philos = philos[i].num_of_philos;
	while (i < total_philos)
	{
		pthread_create(&philos[i].thread, NULL, print_message, &philos[i]);
		printf("philo thread number %zu is created\n", philos[i].id);
		i++;
	}
	sleep(1);
	i = 0;
	while (i < total_philos)
	{
		pthread_join(philos[i].thread, NULL);
		printf("philo thread number %zu finished execution\n", philos[i].id);
		i++;
	}
}
