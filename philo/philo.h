/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrodrigu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/16 17:59:29 by yrodrigu          #+#    #+#             */
/*   Updated: 2024/08/26 18:26:50 by yrodrigu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

# define MESSAGE "\033[96m=========================="
# define MESSAGE2 "===========\n\t\tUsage:\n===================="
# define MESSAGE3 "=================\n./philo "
# define MESSAGE4 "[num of philos] [time_to_die] [time_to_eat] "
# define MESSAGE5 "[time_to_sleep] [num_of_times_each_philo_must_eat]\033[0m\n"

int		ft_atoi(char *str);
void	check_arg(int argc, char **argv);

#endif
