/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrodrigu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/16 18:00:34 by yrodrigu          #+#    #+#             */
/*   Updated: 2024/10/23 15:29:40 by yrodrigu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "philo.h"

int main(int argc, char **argv)
{
	t_philo		philos[MAX_PHILOS];
	t_program	program;
	t_philo		forks[MAX_PHILOS];

	check_arg(argc, argv);
	init_program(&program, philos);
	init_forks(philos, forks);
	init_philo_values(philos, argv, &program);
	create_threads(philos, &program);
	return (0);
}


