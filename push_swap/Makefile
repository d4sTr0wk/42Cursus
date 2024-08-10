# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: maxgarci <maxgarci@student.42malaga.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/28 18:22:03 by maxgarci          #+#    #+#              #
#    Updated: 2024/08/10 21:35:43 by maxgarci         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

RED = \033[0;31m
GREEN = \033[0;32m
YELLOW = \033[0;33m
RESTORE = \033[0m

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

COMMON_SRCS = src/stack/check_args.c src/stack/initialize_args.c src/stack/stack.c src/stack/push.c src/stack/swap.c src/stack/rotate.c src/stack/reverserotate.c src/stack/push_swap.c src/stack/next_move_utils.c src/stack/push_swap_utils1.c src/stack/push_swap_utils2.c
PUSH_SWAP_SRCS = $(COMMON_SRCS) src/main.c
PUSH_SWAP_OBJS = $(PUSH_SWAP_SRCS:.c=.o)
BONUS_SRCS = $(COMMON_SRCS) bonus/checker.c bonus/get_next_line/get_next_line.c bonus/get_next_line/get_next_line_utils.c
BONUS_OBJS = $(BONUS_SRCS:.c=.o)

all: $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

$(NAME): $(PUSH_SWAP_OBJS) $(FT_PRINTF) $(LIBFT)
	@echo "$(YELLOW)Compiling $<...$(RESTORE)"
	$(CC) $(CFLAGS) $(INCLUDES) $(PUSH_SWAP_OBJS) $(FT_PRINTF) $(LIBFT) -o $(NAME)
	@echo "$(GREEN)$< compiled!$(RESTORE)"

$(FT_PRINTF):
	@echo "$(YELLOW)Compiling ft_printf...$(RESTORE)"
	@$(MAKE) -C $(FT_PRINTF_DIR)
	@echo "$(GREEN)Ft_printf compiled!$(RESTORE)"

$(LIBFT):
	@echo "$(YELLOW)Compiling libft...$(RESTORE)"
	@$(MAKE) -C $(LIBFT_DIR)
	@echo "$(GREEN)Libft compiled!$(RESTORE)"

clean:
	@echo "$(RED)Cleaning...$(RESTORE)"	
	rm -rf $(PUSH_SWAP_OBJS)
	rm -rf $(BONUS_OBJS)
	@$(MAKE) -C $(FT_PRINTF_DIR) clean
	@$(MAKE) -C $(LIBFT_DIR) clean
	@echo "$(GREEN)Cleaned!$(RESTORE)"

fclean: clean
	@echo "$(RED)Full cleaning...$(RESTORE)"
	rm -rf $(NAME)
	rm -rf checker
	@$(MAKE) -C $(FT_PRINTF_DIR) fclean
	@$(MAKE) -C $(LIBFT_DIR) fclean
	@echo "$(GREEN)Full cleaned!$(RESTORE)"

re: fclean all

bonus: $(BONUS_OBJS) $(FT_PRINTF) $(LIBFT)
	@echo "$(YELLOW)Compiling bonus...$(RESTORE)"
	$(CC) $(CFLAGS) $(INCLUDES) $(BONUS_OBJS) $(FT_PRINTF) $(LIBFT) -o checker
	@echo "$(GREEN)Bonus compiled!$(RESTORE)"

clean_bonus:
	@echo "$(RED)Cleaning bonus...$(RESTORE)"
	rm -f $(BONUS_OBJS) 
	@$(MAKE) -C $(LIBFT_DIR) clean
	@$(MAKE) -C $(FT_PRINTF_DIR) clean
	@echo "$(GREEN)Bonus cleaned!$(RESTORE)"

.PHONY: clean fclean all re bonus
