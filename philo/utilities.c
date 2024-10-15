/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utilities.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrodrigu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/20 18:33:39 by yrodrigu          #+#    #+#             */
/*   Updated: 2024/10/15 20:42:04 by yrodrigu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "philo.h"

int	non_numeric(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (!(str[i] >= 48 && str[i] <= 57))
			return (1);
		i++;
	}
	return (0);
}

int	ft_atoi(char *str)
{
	int	result;

	result = 0;
	while (*str == 32 || (*str >= 9 && *str <= 13))
		str++;
	if (non_numeric(str) == 1)
	{
		printf("Only positive and numeric values are allowed!!!\n");
		exit(1);
	}
	while (*str)
	{
		result = result * 10 + (*str - 48);
		str++;
	}
	return (result);
}

void	check_arg(int argc, char **argv)
{
    if (argc < 5 || argc > 6)
    {
        printf("%s%s%s%s%s", MESSAGE, MESSAGE2, MESSAGE3, MESSAGE4, MESSAGE5);
   		exit (1);
   	}
    int i = 1;
    while (argv[i])
    {
        ft_atoi(argv[i]);
        i++;
    }
}

size_t	get_current_time(void)
{
	struct timeval current_time;

	gettimeofday(&current_time, 0);
	return(current_time.tv_sec * 1000 + current_time.tv_usec / 1000);
}
