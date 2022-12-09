# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nmoussam <nmoussam@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/30 14:03:43 by nmoussam          #+#    #+#              #
#    Updated: 2022/12/07 19:54:12 by nmoussam         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = philo
INC  = philo.h
SRCS = 	begin.c \
		check_end_simulation.c \
		check_init_args.c \
		forks_init_mutex.c \
		main.c \
		routine.c \
		utils.c
OBJS = $(SRCS:.c=.o)
CFLAGS = -Wall -Wextra -Werror -pthread
CC = cc
RM = rm -rf

all : $(NAME)

$(NAME): $(OBJS)
	@$(CC) $(CFLAGS) -o $(NAME) $^

%.o: %.c $(INC)
	@$(CC) $(CFLAGS) -c $< -o $@

clean :
	@$(RM) $(OBJS)

fclean : clean
	@$(RM) $(NAME)

re : fclean all