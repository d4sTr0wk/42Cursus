# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: maxgarci <maxgarci@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/03/31 16:38:43 by maxgarci          #+#    #+#              #
#    Updated: 2024/04/01 19:20:07 by maxgarci         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = minitalk

SERVER_SRCS = src/server.c
CLIENT_SRCS = src/client.c

SERVER_OBJS = $(SERVER_SRCS:.c=.o)
CLIENT_OBJS = $(CLIENT_SRCS:.c=.o)

INCLUDES = -I . -I libft
LIBFT_DIR = libft
LIBFT = $(LIBFT_DIR)/libft.a

CC = gcc
CFLAGS = -Wall -Wextra -Werror -g

all: $(NAME)

$(NAME): server client

%.o: %.c
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

server: $(SERVER_OBJS) $(LIBFT)
	$(CC) $(CFLAGS) $(INCLUDES) $(SERVER_OBJS) $(LIBFT) -o $@

client: $(CLIENT_OBJS) $(LIBFT)
	$(CC) $(CFLAGS) $(INCLUDES) $(CLIENT_OBJS) $(LIBFT) -o $@

$(LIBFT):
	@$(MAKE) -C $(LIBFT_DIR)

clean:
	rm -f $(SERVER_OBJS) $(CLIENT_OBJS)
	@$(MAKE) -C $(LIBFT_DIR) clean

fclean: clean
	rm -f server client
	@$(MAKE) -C $(LIBFT_DIR) fclean

re: fclean all

.PHONY: all clean fclean re