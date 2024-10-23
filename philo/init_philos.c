/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_philos.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrodrigu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/26 19:28:37 by yrodrigu          #+#    #+#             */
/*   Updated: 2024/10/23 15:51:20 by yrodrigu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "philo.h"

void	init_philo_values(t_philo *philos, char **argv, t_program *program)
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
		philos[i].write_lock = &program->write_lock;
		philos[i].write_lock = &program->dead_lock;
		philos[i].right_fork = &philos[i].id;
		philos[i].left_fork = &philos[i - 1].id;
		philos[0].left_fork = &philos[total_philo - 1].id;
		if (argv[5])
			philos[i].meals_per_philo = ft_atoi(argv[5]);
		else
			philos[i].meals_per_philo = -1;
		i++;
	}
}

void	init_forks(pthread_mutex_t *forks, int num_of_philos)
{
	int  i;

	i = 0;
	while (i < num_of_philos)
	{
		pthread_mutex_init(&forks[i], NULL);
		i++;
	}
}


void	init_program(t_program *program, t_philo *philos)
{
	program->dead_flag = 0;
	program->philo = philos;
	pthread_mutex_init(&program->write_lock, NULL);
	pthread_mutex_init(&program->dead_lock, NULL);
	pthread_mutex_init(&program->meal_lock, NULL);
}

void	destroy_threads(t_program *program, t_philo *forks, t_philo *philos)
{
	int i;

	i = 0;
	while (i < philos[0].num_of_philos)
	{
		pthread_mutex_destroy(&forks[i]);
		i++;
	}
	pthread_mutex_destroy(&program->write_lock);
	pthread_mutex_destroy(&program->dead_lock);
	pthread_mutex_destroy(&program->meal_lock);
}
