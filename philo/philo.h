/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrodrigu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/16 17:59:29 by yrodrigu          #+#    #+#             */
/*   Updated: 2024/10/30 18:00:42 by yrodrigu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <pthread.h>
# include <sys/time.h>

# define MESSAGE "\033[93m"
# define MESSAGE2 "\n\tUsage:"
# define MESSAGE3 "\n\033[0m\n ./philo "
# define MESSAGE4 "[Num Philos] [time_to_die] [time_to_eat] "
# define MESSAGE5 "[time_to_sleep] [num_of_times_each_philo_must_eat]\n\033[0m\n"
# define MAX_PHILOS 242
# define CYAN "\033[96m"
# define GREEN "\033[92m"
# define YELLOW "\033[93m"
# define MAGENTA "\033[95m"
# define RED "\033[31m"
# define BLUE "\033[94m"
# define GRAY "\033[90m"

typedef struct	s_philo
{
	pthread_t	thread;
	int			id;
	int			eating;
	int			meals_eaten;
	int			num_of_philos;
	size_t		time_to_die;
	size_t		time_to_eat;
	size_t		time_to_sleep;
	size_t		start_meal;
	size_t		last_meal;
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
void	init_philo_values(t_philo *philos, char **argv, t_program *program, pthread_mutex_t *forks);
size_t	get_current_time(void);
int		create_threads(pthread_mutex_t *forks, t_program *program);
void	init_program(t_program *program, t_philo *philos);
void	init_forks(pthread_mutex_t *forks, int num_of_philos);
void	destroy_threads(t_program *program, pthread_mutex_t *forks);
size_t	ft_usleep(size_t miliseconds);
void	print_message(char *color, char *str, t_philo *philo, int id);
int		is_dead(t_philo *philo);
void	dream(t_philo *philo);
void	think(t_philo *philo);
void	eat(t_philo *philo);
void	*supervisor(void *pointer);
void	*procedure(void *pointer);
int		check_if_all_ate(t_philo *philos);
int		check_if_dead(t_philo *philos);
int		philosopher_dead(t_philo *philo, size_t time_to_die);

#endif
