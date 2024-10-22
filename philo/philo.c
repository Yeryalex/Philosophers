/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrodrigu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/16 18:00:34 by yrodrigu          #+#    #+#             */
/*   Updated: 2024/10/22 17:23:43 by yrodrigu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "philo.h"

int main(int argc, char **argv)
{
	t_philo		philos[MAX_PHILOS];
	t_program	program;	
	check_arg(argc, argv);
	program.philo = philos;
	init_philo_values(philos, argv, &program);
	create_threads(philos, &program);
	return (0);
}

//git push https://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@github.com/Yeryalex/Philosophers.git/

