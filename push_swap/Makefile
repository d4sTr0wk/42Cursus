# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: maxgarci <maxgarci@student.42malaga.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/28 18:22:03 by maxgarci          #+#    #+#              #
#    Updated: 2024/08/07 20:06:48 by maxgarci         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
CC = gcc
CFLAGS = -Wall -Wextra -Werror -g
LIBFT_DIR = libft
LIBFT = $(LIBFT_DIR)/libft.a
FT_PRINTF_DIR = ft_printf
FT_PRINTF = $(FT_PRINTF_DIR)/libftprintf.a
GET_NEXT_LINE_DIR = bonus/get_next_line
GET_NEXT_LINE = $(GET_NEXT_LINE_DIR)/
INCLUDES = -I . -I include -I ft_printf -I bonus/get_next_line

COMMON_SRCS = src/stack/stack.c src/stack/push.c src/stack/swap.c src/stack/rotate.c src/stack/reverserotate.c src/stack/push_swap.c src/stack/ft_split_count.c src/stack/next_move_utils.c src/stack/push_swap_utils1.c src/stack/push_swap_utils2.c
PUSH_SWAP_SRCS = $(COMMON_SRCS) src/main.c
PUSH_SWAP_OBJS = $(PUSH_SWAP_SRCS:.c=.o)
BONUS_SRCS = $(COMMON_SRCS) bonus/checker.c bonus/get_next_line/get_next_line.c bonus/get_next_line/get_next_line_utils.c
BONUS_OBJS = $(BONUS_SRCS:.c=.o)

all: $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

$(NAME): $(PUSH_SWAP_OBJS) $(FT_PRINTF) $(LIBFT)
	$(CC) $(CFLAGS) $(INCLUDES) $(PUSH_SWAP_OBJS) $(FT_PRINTF) $(LIBFT) -o $(NAME)

$(FT_PRINTF):
	@$(MAKE) -C $(FT_PRINTF_DIR)

$(LIBFT):
	@$(MAKE) -C $(LIBFT_DIR)

clean:
	rm -f $(PUSH_SWAP_OBJS) $(BONUS_OBJS)
	@$(MAKE) -C $(FT_PRINTF_DIR) clean
	@$(MAKE) -C $(LIBFT_DIR) clean

fclean: clean
	rm -f $(NAME)
	@$(MAKE) -C $(FT_PRINTF_DIR) fclean
	@$(MAKE) -C $(LIBFT_DIR) fclean

re: fclean all

bonus: $(BONUS_OBJS) $(FT_PRINTF) $(LIBFT)
	 $(CC) $(CFLAGS) $(INCLUDES) $(BONUS_OBJS) $(FT_PRINTF) $(LIBFT) -o checker

.PHONY: clean fclean all re bonus
