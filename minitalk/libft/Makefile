# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: maxgarci <maxgarci@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/09/19 19:17:40 by maxgarci          #+#    #+#              #
#    Updated: 2024/03/30 23:35:13 by maxgarci         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Archivos fuente
SRCS = ft_putstr_fd.c ft_putnbr_fd.c ft_putchar_fd.c
OBJS = $(SRCS:.c=.o)
CFLAGS = -Wall -Wextra -Werror

NAME = libft.a

all: $(NAME)

%.o: %.c
	gcc $(CFLAGS) -c $< -o $@

$(NAME): $(OBJS)
	ar -rcs $(NAME) $(OBJS)	

clean:
	rm -f $(OBJS) $(OBJS_BONUS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: clean fclean all re
