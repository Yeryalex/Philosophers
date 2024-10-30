/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_philos.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrodrigu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/26 19:28:37 by yrodrigu          #+#    #+#             */
/*   Updated: 2024/10/30 16:24:47 by yrodrigu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "philo.h"

void	init_input_values(t_philo *philos, char **argv)
{
	philos->num_of_philos = ft_atoi(argv[1]);
	philos->time_to_die = ft_atoi(argv[2]);
	philos->time_to_eat = ft_atoi(argv[3]);
	philos->time_to_sleep = ft_atoi(argv[4]);
	if (argv[5])
		philos->meals_per_philo = ft_atoi(argv[5]);
	else
		philos->meals_per_philo = -1;
}

void	init_philo_values(t_philo *philos, char **argv, t_program *program, pthread_mutex_t *forks)
{
	int	i;

	i = 0;
	while(i < ft_atoi(argv[1]))
	{
		init_input_values(&philos[i], argv);
		philos[i].id = i + 1;
		philos[i].eating = 0;
		philos[i].meals_eaten = 0;
		philos[i].start_meal = get_current_time();
		philos[i].last_meal = get_current_time();
		philos[i].dead = &program->dead_flag;
		philos[i].write_lock = &program->write_lock;
		philos[i].dead_lock = &program->dead_lock;
		philos[i].meal_lock = &program->meal_lock;
		philos[i].right_fork = &forks[i];
		if (i == 0)
			philos[i].left_fork = &forks[ft_atoi(argv[1]) - 1];
		else
			philos[i].left_fork = &forks[i - 1];
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

void	destroy_threads(t_program *program, pthread_mutex_t *forks)
{
	int i;

	i = 0;
	while (i < program->philo[0].num_of_philos)
	{
		pthread_mutex_destroy(&forks[i]);
		i++;
	}
	pthread_mutex_destroy(&program->write_lock);
	pthread_mutex_destroy(&program->dead_lock);
	pthread_mutex_destroy(&program->meal_lock);
}
