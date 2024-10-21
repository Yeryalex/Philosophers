/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_actions.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrodrigu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 21:58:57 by yrodrigu          #+#    #+#             */
/*   Updated: 2024/10/21 20:28:26 by yrodrigu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "philo.h"

void	*print_message(void *philo)
{
	t_philo *philas;
	size_t	i;

	philas = (t_philo *)philo;
	i = 0;
    printf("from %zu I am philo thread %zu and my left %zu and right %zu\n", philas[i].num_of_philos, philas[i].id, *(philas[i]).left_fork, *(philas[i]).right_fork);


	printf("++++\n");
	return (0);
}

void	create_threads(t_philo *philos)
{
	size_t total_philos;
	size_t	i;
	total_philos = philos[0].num_of_philos;
	i = 0;
//	pthread_mutex_init(philos.write_lock, NULL);
	while (i < total_philos)
	{
		pthread_create(&philos[i].thread, NULL, print_message, philos);
		i++;
	}
	    i = 0;
    while (i < total_philos)
    {
        pthread_create(&philos[i].thread, NULL, print_message, philos);
        i++;
    }
//	pthread_mutex_destroy(philos.write_lock);
}
