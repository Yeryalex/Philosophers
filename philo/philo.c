/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrodrigu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/16 18:00:34 by yrodrigu          #+#    #+#             */
/*   Updated: 2024/10/23 17:02:10 by yrodrigu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "philo.h"

int main(int argc, char **argv)
{
	t_philo		philos[MAX_PHILOS];
	t_program	program;
	pthread_mutex_t	forks[MAX_PHILOS];

	check_arg(argc, argv);
	init_program(&program, philos);
	init_forks(forks, ft_atoi(argv[1]));
	init_philo_values(philos, argv, &program, forks);
	create_threads(philos, &program);
   	destroy_threads(&program, forks,philos);
	return (0);
}


