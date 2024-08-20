/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utilities.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrodrigu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/20 18:33:39 by yrodrigu          #+#    #+#             */
/*   Updated: 2024/08/20 18:46:52 by yrodrigu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "philo.h"

int	ft_atoi(char *str)
{
	int result;
	int sign;

	result = 0;
	sign = 1;
	while (*str == 32 || (*str >= 9 && *str <= 13))
		str++;
	if (*str == '-')
	{
		sign = -sign;
		str++;
	}
	while(*str)
	{
		result = result * 10 + (*str - 48);
		str++;
	}
	if ((sign * result) < 0)
	{
		printf("non-numeric values allowed\n");
		exit(0);
	}
	return (sign * result);
}
