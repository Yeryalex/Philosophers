/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_philos.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrodrigu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/26 19:28:37 by yrodrigu          #+#    #+#             */
/*   Updated: 2024/09/16 18:29:32 by yrodrigu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "philo.h"

void	assign_philos(t_philo *philo, t_program *program)
{
	size_t	philos_number;
	int		i;

	philos_number = philo->num_of_philos;
	i = 1;
	while (i <= philos_number)
	{
		philo->id = i;
		i++;
	}
}
