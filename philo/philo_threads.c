/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_threads.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrodrigu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 21:58:57 by yrodrigu          #+#    #+#             */
/*   Updated: 2024/10/24 16:39:56 by yrodrigu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "philo.h"

/*
int	check_flag(t_program *program)
{
	int i;

	i = 0;
	while (i < program->philo[0].num_of_philos)
	{
		pthread_mutex_lock(program->philo[i].meal_lock);
		if (program->dead_flag == 1)
		{
			pthread_mutex_unlock(program->philo[i].meal_lock);
			return (1);
		}
		pthread_mutex_unlock(program->philo[i].meal_lock);
		i++;
	}
	return (0);
}
*/
/*
void	*ft_supervisor(void *pointer)
{
	t_program	*program;
	int i;

	program = (t_program *)pointer;
	i = 0;
	while (1)
	{
		if (check_flag(program) == 1)
			break ;
		usleep(100);
	}
	return (NULL);
}
*/

void	*ft_supervisor(void *pointer)
{
	t_philo	*all_philos;

	all_philos = (t_philo *)pointer;
	
	
	printf("I am Supervisor %i!\n", *(all_philos[0].dead));
	return (pointer);
}

void	*print_message(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;

	pthread_mutex_lock(philo->dead_lock);
		//if (*(philo->dead) == 0)
			printf("Hello There! I am philo Number %i\n", philo->id);
	pthread_mutex_unlock(philo->dead_lock);
	return (NULL);
}

void	create_threads(t_philo *philos, t_program *program)
{
	int	total_philos;
	int	i;
	pthread_t	supervisor;
	
	total_philos = philos[0].num_of_philos;
	i = 0;

	pthread_create(&supervisor, NULL, &ft_supervisor, philos);

	while (i < total_philos)
	{
		pthread_create(&program->philo[i].thread, NULL, &print_message, &program->philo[i]);
		i++;
	}

	pthread_join(supervisor, NULL);
	i= 0;
    while (i < total_philos)
    {
        pthread_join(program->philo[i].thread, NULL);
        i++;
    }
}
