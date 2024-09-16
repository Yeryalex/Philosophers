/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrodrigu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/16 17:59:29 by yrodrigu          #+#    #+#             */
/*   Updated: 2024/09/16 18:27:25 by yrodrigu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <pthread.h>

# define MESSAGE "\033[96m=========================="
# define MESSAGE2 "===========\n\t\tUsage:\n===================="
# define MESSAGE3 "=================\n./philo "
# define MESSAGE4 "[num of philos] [time_to_die] [time_to_eat] "
# define MESSAGE5 "[time_to_sleep] [num_of_times_each_philo_must_eat]\033[0m\n"

typedef struct	s_philo
{
	pthread_t	thread;
	int		id;
	size_t	num_of_philos;
	size_t	time_to_die;
	size_t	time_to_eat;
	size_t	time_to_sleep;
	size_t	meals_for_philo;
} 	t_philo;

typedef struct	s_program
{
	t_philo		*philos;	
}	t_program;

int		ft_atoi(char *str);
void	check_arg(int argc, char **argv);
int		non_numeric(char *str);

#endif
