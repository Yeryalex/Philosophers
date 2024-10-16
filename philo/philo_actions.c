/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_actions.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrodrigu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 21:58:57 by yrodrigu          #+#    #+#             */
/*   Updated: 2024/10/16 15:32:33 by yrodrigu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "philo.h"

void	*print_message(void *argument)
{
	t_philo	*philo;

	philo = (t_philo *)argument;

	pthread_mutex_lock(philo->mutex);
	printf("%sHello, I am a philo %zu using fork right %zu and left %zu!\n", MAGENTA, philo->id, *(philo)->right_fork, *(philo)->left_fork);
	pthread_mutex_unlock(philo->mutex);
	return (0);
}

void	create_threads(t_philo *philos)
{
	int i;
	int total_philos;
	pthread_mutex_t	mutex;

	pthread_mutex_init(&mutex, NULL);

	i = 0;
	total_philos = philos[i].num_of_philos;
	while (i < total_philos)
	{
		philos[i].mutex = &mutex;
		pthread_create(&philos[i].thread, NULL, print_message, &philos[i]);
		printf("%sphilo thread number %zu is created\n\033[0m",CYAN, philos[i].id);
		i++;
	}
	sleep(1);
	i = 0;
	while (i < total_philos)
	{
		pthread_join(philos[i].thread, NULL);
		printf("%sphilo thread number %zu finished execution\n",GREEN, philos[i].id);
		i++;
	}
	pthread_mutex_destroy(&mutex);
}
