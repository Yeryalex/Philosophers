/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_actions.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrodrigu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 21:58:57 by yrodrigu          #+#    #+#             */
/*   Updated: 2024/10/22 17:18:15 by yrodrigu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "philo.h"

void	*print_message(void *philo)
{
	t_philo *philas;

	philas = (t_philo *)philo;
	pthread_mutex_lock(philas->dead_lock);
	pthread_mutex_lock(philas->write_lock);
    printf("from %zu I am philo thread %zu and my left %zu and right %zu\n", philas->num_of_philos, philas->id, *(philas)->left_fork, *(philas)->right_fork);


	printf("++++\n");
	pthread_mutex_unlock(philas->write_lock);
	pthread_mutex_unlock(philas->dead_lock);
	return (0);
}

void	create_threads(t_philo *philos, t_program *program)
{
	size_t total_philos;
	size_t	i;
	total_philos = philos[0].num_of_philos;
	i = 0;
	pthread_mutex_init(&program->write_lock, NULL);
	pthread_mutex_init(&program->dead_lock, NULL);
	while (i < total_philos)
	{
		pthread_create(&program->philo[i].thread, NULL, &print_message, &program->philo[i]);
		i++;
	}
	    i = 0;
    while (i < total_philos)
    {
        pthread_join(program->philo[i].thread, NULL);
        i++;
    }
	pthread_mutex_destroy(&program->write_lock);
	pthread_mutex_destroy(&program->dead_lock);
}
