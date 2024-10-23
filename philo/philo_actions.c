/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_actions.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrodrigu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 21:58:57 by yrodrigu          #+#    #+#             */
/*   Updated: 2024/10/23 17:37:01 by yrodrigu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "philo.h"

void	*print_message(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	printf("Helo There! I am philo Number %i with leftfork %p and rightfork %p\n", philo->id, philo->left_fork, philo->right_fork);
	return (NULL);
}

void	create_threads(t_philo *philos, t_program *program)
{
	int	total_philos;
	int	i;

	total_philos = philos[0].num_of_philos;
	i = 0;
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
}
