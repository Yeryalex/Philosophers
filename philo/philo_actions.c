/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_actions.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrodrigu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 20:05:45 by yrodrigu          #+#    #+#             */
/*   Updated: 2024/10/30 14:42:30 by yrodrigu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "philo.h"

void	print_message(char *str, t_philo *philo, int id)
{
	size_t	time;
	pthread_mutex_lock(philo->write_lock);
	time =  get_current_time() - philo->start_meal;
	if (!is_dead(philo))
		printf("%zu %i %s\n", time, id, str);
	pthread_mutex_unlock(philo->write_lock);
}

size_t	ft_usleep(size_t miliseconds)
{
	size_t	start;

	start = get_current_time();
	while ((get_current_time() - start) < miliseconds)
		usleep(500);
	return (0);
}

void	think(t_philo *philo)
{
	print_message("is thinking", philo, philo->id);
}

void	sleep(t_philo *philo)
{
	print_message("is sleeping", philo, philo->id);
	ft_usleep(philo->time_to_sleep);
}

void	eat(t_philo *philo)
{
	pthread_mutex_lock(philo->r_fork);
	print_message("has taken a fork", philo, philo->id);
	if (philo->num_of_philos == 1)
	{
		ft_usleep(philo->time_to_die);
		pthread_mutex_unlock(philo->r_fork);
		return ;
	}
	pthread_mutex_lock(philo->l_fork);
	print_message("has taken a fork", philo, philo->id);
	philo->eating = 1;
	print_message("is eating", philo, philo->id);
	pthread_mutex_lock(philo->meal_lock);
	philo->last_meal = get_current_time();
	philo->meals_eaten++;
	pthread_mutex_unlock(philo->meal_lock);
	ft_usleep(philo->time_to_eat);
	philo->eating = 0;
	pthread_mutex_unlock(philo->l_fork);
	pthread_mutex_unlock(philo->r_fork);
}
