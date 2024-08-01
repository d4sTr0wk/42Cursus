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

RED = \033[0;31m
GREEN = \033[0;32m
YELLOW = \033[0;33m
RESTORE = \033[0m

NAME = minitalk

SERVER_SRCS = src/server.c
CLIENT_SRCS = src/client.c

SERVER_BONUS_SRCS = bonus/server_bonus.c
CLIENT_BONUS_SRCS = bonus/client_bonus.c

SERVER_OBJS = $(SERVER_SRCS:.c=.o)
CLIENT_OBJS = $(CLIENT_SRCS:.c=.o)

SERVER_BONUS_OBJS = $(SERVER_BONUS_SRCS:.c=.o)
CLIENT_BONUS_OBJS = $(CLIENT_BONUS_SRCS:.c=.o)

INCLUDES = -I . -I libft -I bonus -I src
LIBFT_DIR = libft
LIBFT = $(LIBFT_DIR)/libft.a

CC = gcc
CFLAGS = -Wall -Wextra -Werror -g

all: $(NAME)

$(NAME): server client

%.o: %.c
	@echo "$(YELLOW)Compiling $<...$(RESTORE)"
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@
	@echo "$(GREEN)$< compiled!$(RESTORE)"

server: $(SERVER_OBJS) $(LIBFT)
	@echo "$(YELLOW)Compiling server...$(RESTORE)"
	$(CC) $(CFLAGS) $(INCLUDES) $(SERVER_OBJS) $(LIBFT) -o $@
	@echo "$(GREEN)Server compiled!$(RESTORE)"

client: $(CLIENT_OBJS) $(LIBFT)
	@echo "$(YELLOW)Compiling client...$(RESTORE)"
	$(CC) $(CFLAGS) $(INCLUDES) $(CLIENT_OBJS) $(LIBFT) -o $@
	@echo "$(GREEN)Client compiled!$(RESTORE)"

$(LIBFT):
	@echo "$(YELLOW)Compiling libft...$(RESTORE)"
	@$(MAKE) -C $(LIBFT_DIR)
	@echo "$(GREEN)Libft compiled!$(RESTORE)"

clean:
	@echo "$(RED)Cleaning...$(RESTORE)"
	rm -f $(SERVER_OBJS) $(CLIENT_OBJS)
	@$(MAKE) -C $(LIBFT_DIR) clean
	@echo "$(GREEN)Cleaned!$(RESTORE)"

fclean: clean
	@echo "$(RED)Full cleaning...$(RESTORE)"
	rm -f server client
	@$(MAKE) -C $(LIBFT_DIR) fclean
	@echo "$(GREEN)Full cleaned!$(RESTORE)"

bonus: server_bonus client_bonus

clean_bonus:
	@echo "$(RED)Cleaning bonus...$(RESTORE)"
	rm -f $(SERVER_BONUS_OBJS) $(CLIENT_BONUS_OBJS)
	@$(MAKE) -C $(LIBFT_DIR) clean
	@echo "$(GREEN)Bonus cleaned!$(RESTORE)"

fclean_bonus: clean_bonus
	@echo "$(RED)Full cleaning bonus...$(RESTORE)"
	rm -f server_bonus client_bonus
	@$(MAKE) -C $(LIBFT_DIR) fclean
	@echo "$(GREEN)Full bonus cleaned!$(RESTORE)"

server_bonus: $(SERVER_BONUS_OBJS) $(LIBFT)
	@echo "$(YELLOW)Compiling server_bonus...$(RESTORE)"
	$(CC) $(CFLAGS) $(INCLUDES) $(SERVER_BONUS_OBJS) $(LIBFT) -o server_bonus
	@echo "$(GREEN)Server_bonus compiled!$(RESTORE)"

client_bonus: $(CLIENT_BONUS_OBJS) $(LIBFT)
	@echo "$(YELLOW)Compiling client_bonus...$(RESTORE)"
	$(CC) $(CFLAGS) $(INCLUDES) $(CLIENT_BONUS_OBJS) $(LIBFT) -o client_bonus
	@echo "$(GREEN)Client_bonus compiled!$(RESTORE)"

re: fclean all

re_bonus: fclean_bonus bonus

.PHONY: all clean fclean re bonus clean_bonus fclean_bonus re_bonus server client server_bonus client_bonus
