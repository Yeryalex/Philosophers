/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_actions.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrodrigu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 20:05:45 by yrodrigu          #+#    #+#             */
/*   Updated: 2024/10/30 14:22:32 by yrodrigu         ###   ########.fr       */
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
