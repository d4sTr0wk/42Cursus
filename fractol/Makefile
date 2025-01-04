# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: maxgarci <maxgarci@student.42malaga.com>   +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/12/28 11:00:33 by maxgarci          #+#    #+#              #
#    Updated: 2025/01/04 19:18:32 by maxgarci         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

RED = \033[0;31m
GREEN = \033[0;32m
YELLOW = \033[0;33m
RESTORE = \033[0;0m

NAME = fractol

CC = cc
CFLAGS = -Werror -Wextra -Wall
LIBRARIES =-lXext -lX11 -lm 

LIBFT_PATH = libft
LIBFT = $(LIBFT_PATH)/libft.a

MLX_PATH = minilibx-linux/
MLX = $(MLX_PATH)/libmlx.a

INCLUDES = -I include -I libft -I minilibx-linux
LIBRARIES = -lXext -lX11 -lm

SRC_PATH = src/
SRC =	fractol.c \
		initialization.c \
		color.c \
		utils.c \
		events.c \
		draw_fractol.c \
		parse_args.c \
		help.c \
		ecuations/mandelbrot.c \
		ecuations/julia.c \
		ecuations/burning_ship.c \

COMMON_SRCS = $(addprefix $(SRC_PATH), $(SRC))

OBJ_PATH = obj/
OBJ	= $(SRC:.c=.o)
OBJS = $(addprefix $(OBJ_PATH), $(OBJ))

all: $(MLX) $(LIBFT) $(NAME)

$(OBJ_PATH)%.o: $(SRC_PATH)%.c
	$(CC) $(CFLAGS) -c $< -o $@ $(INCLUDES)

$(OBJS): $(OBJ_PATH)

$(OBJ_PATH):
	@mkdir $(OBJ_PATH)
	@mkdir $(OBJ_PATH)ecuations/
	@mkdir $(OBJ_PATH)color_schemes/

$(MLX):
	@echo "MiniLibX being created . . ."
	@make -C $(MLX_PATH)

$(LIBFT):
	@echo "Libft being created . . ."
	@make -C $(LIBFT_PATH)

$(NAME): $(OBJS)
	@echo "Fractol being created . . ."
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS) $(MLX) $(LIBFT) $(INCLUDES) $(LIBRARIES) 
	@echo "Fractol ready!✅"

bonus: all

clean:
	@echo "Removing .o object files..."
	@rm -rf $(OBJ_PATH)
	@make clean -C $(MLX_PATH)
	@make clean -C $(LIBFT_PATH)

fclean: clean
	@echo "Removing fractol..."
	@rm -f $(NAME)
	@make fclean -C $(LIBFT_PATH)

re: fclean all

.PHONY: all re clean fclean
