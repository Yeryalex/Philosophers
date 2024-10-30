/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_threads.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrodrigu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 21:58:57 by yrodrigu          #+#    #+#             */
/*   Updated: 2024/10/30 14:35:47 by yrodrigu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "philo.h"

int	is_dead(t_philo *philo)
{
	pthread_mutex_lock(philo->dead_lock);
	if (*philo->dead == 1)
		return (pthread_mutex_unlock(philo->dead_lock), 1);
	pthread_mutex_unlock(philo->dead_lock);
	return (0);
}
void	*procedure(void *arg)
{
	t_philo *philo;

	philo = (t_philo *)arg;
	if (philo->id % 2 == 0)
		ft_usleep(1);
	while (!is_dead(philo))
	{
		eat(philo);
		sleep(philo);
		think(philo);	
	}
	return (arg);
}

void	create_threads(t_philo *philos, t_program *program)
{
	int	total_philos;

	int	i;
	
	total_philos = philos[0].num_of_philos;
	i = 0;
	while (i < total_philos)
	{
		pthread_create(&program->philo[i].thread, NULL, &procedure, &program->philo[i]);
		i++;
	}
	i= 0;
    while (i < total_philos)
    {
        pthread_join(program->philo[i].thread, NULL);
        i++;
    }
}
