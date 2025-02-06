# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: maxgarci <maxgarci@student.42malaga.com>   +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/02/05 10:31:34 by maxgarci          #+#    #+#              #
#    Updated: 2025/02/05 12:06:02 by maxgarci         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

RED := \033[0;31m
GREEN := \033[0;32m
YELLOW := \033[0;33m
RESTORE := \033[0;0m

NAME		:= philo

CC			:= cc
CFLAGS		:= -Werror -Wextra -Wall
INCLUDES	:= -I./include

MAIN		:= main.c
SRC_PATH	:= src/
SRC			:= print_error.c ft_strlen.c

SRCS		:= $(addprefix $(SRC_PATH), $(SRC))

OBJ_PATH	:= obj/
OBJ			:= $(SRC:.c=.o)
OBJS		:= $(addprefix $(OBJ_PATH), $(OBJ))

all: $(NAME)

$(OBJ_PATH)%.o: $(SRC_PATH)%.c
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

$(OBJ_PATH):
	@mkdir -p $@

$(OBJS): $(OBJ_PATH)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(INCLUDES) $(MAIN) $(OBJS) -o $(NAME)
	@echo "$(MAGENTA)$(ITALIC)Minishell compiled!$(RESET)"


.PHONY: all clean fclean re
