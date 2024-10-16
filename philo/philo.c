/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrodrigu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/16 18:00:34 by yrodrigu          #+#    #+#             */
/*   Updated: 2024/10/16 15:27:33 by yrodrigu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "philo.h"

int main(int argc, char **argv)
{
	t_philo		philos[MAX_PHILOS];
	
	check_arg(argc, argv);
	init_philo_values(philos, argv);
	create_threads(philos);
	return (0);
}
