# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: maxgarci <maxgarci@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/03/31 16:38:43 by maxgarci          #+#    #+#              #
#    Updated: 2024/04/01 12:42:16 by maxgarci         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = minitalk

MINITALK_SRCS = src/server.c \
		 src/client.c

MINITALK_OBJS = $(MINITALK_SRCS:.c=.o)

INCLUDES = -I . -I libft
LIBFT_DIR = libft
LIBFT = $(LIBFT_DIR)/libft.a

CC = gcc
CFLAGS = -Wall -Wextra -Werror -g

all: $(NAME)

$(NAME): server client

%.o: %.c
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

server: $(MINITALK_OBJS) $(LIBFT)
	$(CC) $(CFLAGS) $(INCLUDES) $(MINITALK_OBJS) $(LIBFT) -o $@

client: $(MINITALK_OBJS) $(LIBFT)
	$(CC) $(CFLAGS) $(INCLUDES) $(MINITALK_OBJS) $(LIBFT) -o $@

$(LIBFT):
	@$(MAKE) -C $(LIBFT_DIR)

clean:
	rm -f $(MINITALK_OBJS)
	@$(MAKE) -C $(LIBFT_DIR) clean

fclean: clean
	rm -f server client
	@$(MAKE) -C $(LIBFT_DIR) fclean

re: fclean all

.PHONY: all clean fclean re