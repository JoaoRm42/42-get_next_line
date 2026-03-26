# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: joaoped2 <joaoped2@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/03/25 00:00:00 by joaoped2          #+#    #+#              #
#    Updated: 2026/03/25 00:00:00 by joaoped2         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS = -Wall -Wextra -Werror
BUFFER_SIZE ?= 42

NAME = gnl
BONUS_NAME = gnl_bonus

MANDATORY_SRCS = main.c get_next_line.c get_next_line_utils.c
BONUS_SRCS = main_bonus.c get_next_line_bonus.c get_next_line_utils_bonus.c

MANDATORY_OBJS = $(MANDATORY_SRCS:.c=.o)
BONUS_OBJS = $(BONUS_SRCS:.c=.o)

all: $(NAME)

bonus: $(BONUS_NAME)

$(NAME): $(MANDATORY_OBJS)
	$(CC) $(CFLAGS) -D BUFFER_SIZE=$(BUFFER_SIZE) $(MANDATORY_OBJS) -o $(NAME)

$(BONUS_NAME): $(BONUS_OBJS)
	$(CC) $(CFLAGS) -D BUFFER_SIZE=$(BUFFER_SIZE) $(BONUS_OBJS) -o $(BONUS_NAME)

main.o: main.c get_next_line.h
	$(CC) $(CFLAGS) -D BUFFER_SIZE=$(BUFFER_SIZE) -c main.c -o main.o

get_next_line.o: get_next_line.c get_next_line.h
	$(CC) $(CFLAGS) -D BUFFER_SIZE=$(BUFFER_SIZE) -c get_next_line.c -o get_next_line.o

get_next_line_utils.o: get_next_line_utils.c get_next_line.h
	$(CC) $(CFLAGS) -D BUFFER_SIZE=$(BUFFER_SIZE) -c get_next_line_utils.c -o get_next_line_utils.o

main_bonus.o: main_bonus.c get_next_line_bonus.h
	$(CC) $(CFLAGS) -D BUFFER_SIZE=$(BUFFER_SIZE) -c main_bonus.c -o main_bonus.o

get_next_line_bonus.o: get_next_line_bonus.c get_next_line_bonus.h
	$(CC) $(CFLAGS) -D BUFFER_SIZE=$(BUFFER_SIZE) -c get_next_line_bonus.c -o get_next_line_bonus.o

get_next_line_utils_bonus.o: get_next_line_utils_bonus.c get_next_line_bonus.h
	$(CC) $(CFLAGS) -D BUFFER_SIZE=$(BUFFER_SIZE) -c get_next_line_utils_bonus.c -o get_next_line_utils_bonus.o

clean:
	rm -f $(MANDATORY_OBJS) $(BONUS_OBJS)

fclean: clean
	rm -f $(NAME) $(BONUS_NAME)

re: fclean all

.PHONY: all bonus clean fclean re