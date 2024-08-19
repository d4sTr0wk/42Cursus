# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: maxgarci <maxgarci@student.42malaga.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/28 18:22:03 by maxgarci          #+#    #+#              #
#    Updated: 2024/08/19 23:14:07 by maxgarci         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

RED = \033[0;31m
GREEN = \033[0;32m
YELLOW = \033[0;33m
RESTORE = \033[0m

NAME = fractol

CC = cc
CFLAGS = -Wall -Wextra -g -ldl -lglfw -pthread -lm -lX11 -lXext
LIBFT_DIR = libft
LIBFT = $(LIBFT_DIR)/libft.a
FT_PRINTF_DIR = ft_printf
FT_PRINTF = $(FT_PRINTF_DIR)/libftprintf.a
MINILIBX_DIR = minilibx-linux
MINILIBX = $(MINILIBX_DIR)/libmlx_Linux.a
INCLUDES = -I . -I include -I libft -I ft_printf -I minilibx-linux

FRACTOL_SRCS = src/main.c
FRACTOL_OBJS = $(FRACTOL_SRCS:.c=.o)

all: $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

$(NAME): $(FRACTOL_OBJS) $(FT_PRINTF) $(LIBFT) $(MINILIBX)
	@echo "$(YELLOW)Compiling $@...$(RESTORE)"
	$(CC) $(CFLAGS) $(INCLUDES) $^ -o $@ 
	@echo "$(GREEN)$@ compiled!$(RESTORE)"

$(FT_PRINTF):
	@echo "$(YELLOW)Compiling ft_printf...$(RESTORE)"
	@$(MAKE) -C $(FT_PRINTF_DIR)
	@echo "$(GREEN)Ft_printf compiled!$(RESTORE)"

$(LIBFT):
	@echo "$(YELLOW)Compiling libft...$(RESTORE)"
	@$(MAKE) -C $(LIBFT_DIR)
	@echo "$(GREEN)Libft compiled!$(RESTORE)"

$(MINILIBX):
	@echo "$(YELLOW)Compiling minilibx...$(RESTORE)"
	@$(MAKE) -C $(MINILIBX_DIR)
	@echo "$(GREEN)Minilibx compiled!$(RESTORE)"

clean:
	@echo "$(RED)Cleaning...$(RESTORE)"	
	rm -rf $(FRACTOL_OBJS)
	@$(MAKE) -C $(FT_PRINTF_DIR) clean
	@$(MAKE) -C $(LIBFT_DIR) clean
	@$(MAKE) -C $(MINILIBX_DIR) clean
	@echo "$(GREEN)Cleaned!$(RESTORE)"

fclean: clean
	@echo "$(RED)Full cleaning...$(RESTORE)"
	rm -rf $(NAME)
	@$(MAKE) -C $(FT_PRINTF_DIR) fclean
	@$(MAKE) -C $(LIBFT_DIR) fclean
	@echo "$(GREEN)Full cleaned!$(RESTORE)"

re: fclean all

.PHONY: clean fclean all re bonus
