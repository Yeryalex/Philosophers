/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrodrigu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/16 18:00:34 by yrodrigu          #+#    #+#             */
/*   Updated: 2024/08/20 18:55:52 by yrodrigu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "philo.h"

int main(int argc, char **argv)
{
	if (argc < 5 || argc > 6)
	{
		printf("%s%s%s%s%s", MESSAGE, MESSAGE2, MESSAGE3, MESSAGE4, MESSAGE5);
	}
	int i = 1;
	while (argv[i])
	{
		ft_atoi(argv[i]);
		i++;
	}
	return (0);
}
