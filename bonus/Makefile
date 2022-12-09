# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nmoussam <nmoussam@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/05 17:15:44 by nmoussam          #+#    #+#              #
#    Updated: 2022/12/07 21:18:25 by nmoussam         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = philo_bonus
INC = philo_bonus.h
SRCS_B = utils.c \
		check_bonus.c \
		ft_begin_bonus.c \
		init_sem.c \
		checker.c \
		routine.c \
		main.c

OBJS_B = $(SRCS_B:%.c=%.o)
CFLAGS = -Wall -Wextra -Werror -pthread
CC = cc
RM = rm -f

all:$(NAME)

$(NAME): $(OBJS_B)
	$(CC) $(CFLAGS) -o $(NAME) $^ 

%.o: %.c $(INC)
	$(CC) $(CFLAGS) -c $< -o $@

clean :
	$(RM) $(OBJS_B)

fclean : clean
	$(RM) $(NAME)

re : fclean all