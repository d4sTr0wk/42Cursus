# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: maxgarci <maxgarci@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/03/31 16:38:43 by maxgarci          #+#    #+#              #
#    Updated: 2024/07/08 17:16:35 by maxgarci         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = minitalk

SERVER_SRCS = src/server.c
CLIENT_SRCS = src/client.c

SERVER_OBJS = $(SERVER_SRCS:.c=.o)
CLIENT_OBJS = $(CLIENT_SRCS:.c=.o)

INCLUDES = -I . -I libft -I bonus -I src
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
	rm -f $(SERVER_BONUS_OBJS) $(CLIENT_BONUS_OBJS)

fclean: clean
	rm -f server client
	@$(MAKE) -C $(LIBFT_DIR) fclean
	rm -f server_bonus client_bonus

bonus: server_bonus client_bonus

server_bonus: $(SERVER_BONUS_OBJS) $(LIBFT)
	$(CC) $(CFLAGS) $(INCLUDES) $(SERVER_BONUS_OBJS) $(LIBFT) -o $@

client_bonus: $(CLIENT_BONUS_OBJS) $(LIBFT)
	$(CC) $(CFLAGS) $(INCLUDES) $(CLIENT_BONUS_OBJS) $(LIBFT) -o $@

re: fclean all

.PHONY: all clean fclean re bonus
