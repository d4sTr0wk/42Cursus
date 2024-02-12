# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: maxgarci <maxgarci@student.42malaga.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/28 18:22:03 by maxgarci          #+#    #+#              #
#    Updated: 2024/01/29 01:58:57 by maxgarci         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS = push_swap.c ft_atoi.c ft_printf.c ft_printf_utils_1.c ft_printf_utils_2.c
OBJS = $(SRCS:.c=.o)
CFLAGS = -Wall -Wextra -Werror

NAME = push_swap

.PHONY: clean fclean all re

all: $(NAME)

%.o: %.c
	gcc $(CFLAGS) -c $< -o $@

$(NAME): $(OBJS)
	gcc $(CFLAGS) $(OBJS) -o $(NAME)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)
re: fclean all