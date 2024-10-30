/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_threads.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrodrigu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 21:58:57 by yrodrigu          #+#    #+#             */
/*   Updated: 2024/10/30 16:31:05 by yrodrigu         ###   ########.fr       */
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
	if (!is_dead(philo))
	{
		eat(philo);
		dream(philo);
		think(philo);
	}
	return (arg);
}

void	create_threads(pthread_mutex_t *forks, t_program *program)
{
	pthread_t	observer;
	int			i;

	(void)forks;
	pthread_create(&observer, NULL, &supervisor, program->philo);
	i = 0;
	while (i < program->philo[0].num_of_philos)
	{
		pthread_create(&program->philo[i].thread, NULL, &procedure,
				&program->philo[i]);
			i++;
	}
	i = 0;
	pthread_join(observer, NULL);
	while (i < program->philo[0].num_of_philos)
	{
		pthread_join(program->philo[i].thread, NULL);
		i++;
	}
}
