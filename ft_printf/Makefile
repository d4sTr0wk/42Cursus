# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: maxgarci <maxgarci@student.42malaga.com>   +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/10 14:16:19 by maxgarci          #+#    #+#              #
#    Updated: 2023/10/13 21:53:45 by maxgarci         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS = ft_printf.c ft_putchar.c ft_putstr.c ft_strlen.c ft_itoa.c ft_strdup.c ft_ftoa.c
OBJS = $(SRCS:.c=.o)
CFLAGS = -Wall -Wextra -Werror

NAME = libftprintf.a

.PHONY: clean fclean all re

all: $(NAME)

%.o: %.c
	gcc $(CFLAGS) -c $< -o $@

$(NAME): $(OBJS)
	ar -rcs $(NAME) $(OBJS)

clean:
	rm -rf $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all
