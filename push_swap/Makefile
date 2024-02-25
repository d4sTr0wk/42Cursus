# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: maxgarci <maxgarci@student.42malaga.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/28 18:22:03 by maxgarci          #+#    #+#              #
#    Updated: 2024/02/25 15:27:08 by maxgarci         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
CC = gcc
CFLAGS = -Wall -Wextra -Werror -g
FT_PRINTF_DIR = ft_printf
FT_PRINTF = $(FT_PRINTF_DIR)/libftprintf.a
INCLUDES = -I . -I include -I ft_printf

COMMON_SRCS = src/stack/stack.c src/stack/push.c src/stack/swap.c src/stack/rotate.c src/stack/reverserotate.c src/stack/push_swap.c src/stack/push_swap_utils1.c src/stack/push_swap_utils2.c
PUSH_SWAP_SRCS = $(COMMON_SRCS) src/main.c
PUSH_SWAP_OBJS = $(PUSH_SWAP_SRCS:.c=.o)

all: $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

$(NAME): $(PUSH_SWAP_OBJS) $(FT_PRINTF)
	$(CC) $(CFLAGS) $(INCLUDES) $(PUSH_SWAP_OBJS) $(FT_PRINTF) -o $(NAME)

$(FT_PRINTF):
	@$(MAKE) -C $(FT_PRINTF_DIR)

clean:
	rm -f $(PUSH_SWAP_OBJS)
	@$(MAKE) -C $(FT_PRINTF_DIR) clean

fclean: clean
	rm -f $(NAME)
	@$(MAKE) -C $(FT_PRINTF_DIR) fclean

re: fclean all

.PHONY: clean fclean all re
