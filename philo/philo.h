/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrodrigu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/16 17:59:29 by yrodrigu          #+#    #+#             */
/*   Updated: 2024/10/23 15:39:22 by yrodrigu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <pthread.h>
# include <sys/time.h>

# define MESSAGE "\033[96m=========================="
# define MESSAGE2 "===========\n\t\tUsage:\n===================="
# define MESSAGE3 "=================\n./philo "
# define MESSAGE4 "[num of philos] [time_to_die] [time_to_eat] "
# define MESSAGE5 "[time_to_sleep] [num_of_times_each_philo_must_eat]\033[0m\n"
# define MAX_PHILOS 242
# define CYAN "\033[96m"
# define GREEN "\033[92m"
# define YELLOW "\033[93m"
# define MAGENTA "\033[95m"

typedef struct	s_philo
{
	pthread_t	thread;
	int			id;
	int			num_of_philos;
	int			time_to_die;
	int			time_to_eat;
	int			time_to_sleep;
	int			meals_per_philo;
	int			*dead;
	pthread_mutex_t	*right_fork;
	pthread_mutex_t	*left_fork;
	pthread_mutex_t	*write_lock;
	pthread_mutex_t	*dead_lock;
	pthread_mutex_t	*meal_lock;
} 	t_philo;

typedef struct s_program
{
	int	dead_flag;
	pthread_mutex_t	write_lock;
	pthread_mutex_t dead_lock;
	pthread_mutex_t	meal_lock;
	t_philo *philo;
}	t_program;

int		ft_atoi(char *str);
void	check_arg(int argc, char **argv);
int		non_numeric(char *str);
void	init_philo_values(t_philo *philos, char **argv, t_program *program);
size_t	get_current_time(void);
void	create_threads(t_philo *philos, t_program *program);

#endif
