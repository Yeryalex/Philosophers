/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrodrigu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/16 18:00:34 by yrodrigu          #+#    #+#             */
/*   Updated: 2024/10/08 17:50:42 by yrodrigu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "philo.h"

int main(int argc, char **argv)
{
	t_philo		philos[MAX_PHILOS];

	(void)philos;
	check_arg(argc, argv);
	init_philo_values(philos, argv);
	
	return (0);
}
