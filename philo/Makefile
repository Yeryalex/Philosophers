# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yrodrigu <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/08/16 17:58:45 by yrodrigu          #+#    #+#              #
#    Updated: 2024/10/23 20:06:08 by yrodrigu         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #
CC = cc
CFLAGS = -Wall -Wextra -Werror
CFILES =	philo.c\
			utilities.c\
			init_philos.c\
			philo_threads.c\
			philo_actions.c\

OFILES = $(CFILES:.c=.o)

NAME = philo

all: $(NAME)

$(NAME): $(OFILES)
	$(CC) $(CFLAGS) $(OFILES) -o $(NAME)

%.o: %.c philo.h 
	$(CC) $(CFLAGS) -c $<

clean:
	rm -f $(OFILES)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
