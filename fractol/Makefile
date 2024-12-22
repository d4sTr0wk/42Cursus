# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: maxgarci <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/12/22 19:21:20 by maxgarci          #+#    #+#              #
#    Updated: 2024/12/22 21:22:49 by maxgarci         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Program name
NAME = fractol

# Compiler
CC = cc
CFLAGS = -Werror -Wextra -Wall
MLX_FLAGS = -lXext -lX11 -lm

# Minilibx
MLX_PATH = minilibx-linux/
MLX_NAME = libmlx.a
MLX = $(MLX_PATH)$(MLX_NAME)

# libft
LIBFT_PATH = libft/
LIBFT_NAME = libft.a
LIBFT = $(LIBFT_PATH)$(LIBFT_NAME)

# ft_printf
FT_PRINTF_PATH = ft_printf/
FT_PRINTF_NAME = libftprintf.a
FT_PRINTF = $(FT_PRINTF_PATH)$(FT_PRINTF_NAME)

# Includes
INC	= -I ./includes/\
	  -I ./libft/\
	  -I ./minilibx-linux/

# Sources
SRC_PATH = src/
SRC = main.c
SRCS = $(addprefix $(SRC_PATH), $(SRC))

# Objects
OBJ_PATH = obj/
OBJ = $(SRC:.c=.o)
OBJS = $(addprefix $(OBJ_PATH), $(OBJ))

all: $(MLX) $(LIBFT) $(FT_PRINTF) $(NAME)

$(OBJ_PATH)%.o: $(SRC_PATH)%.c
	@$(CC) $(CFLAGS) -c $< -o $@ $(INC)

$(OBJ_PATH):
	@mkdir -p $(OBJ_PATH)
	@mkdir $(OBJ_PATH)fractal_sets/

$(OBJS): $(OBJ_PATH)

$(NAME): $(OBJS)
	@echo "Compiling fractol . . ."
	@$(CC) $(CFLAGS) -o $(NAME) $(OBJS) $(MLX) $(LIBFT) $(FT_PRINTF) $(INC) $(MLX_FLAGS)

$(MLX):
	@echo "Making MinilibX . . ."
	@make -sC $(MLX_PATH)

$(LIBFT):
	@echo "Making libft . . ."
	@make -sC $(LIBFT_PATH)

$(FT_PRINTF):
	@echo "Making ft_printf . . ."
	@make -sC $(FT_PRINTF_PATH)

clean:
	@echo "Removing .o object files . . ."
	@make clean -sC $(MLX_PATH)
	@make clean -sC $(LIBFT_PATH)
	@make clean -sC $(FT_PRINTF_PATH)
	@rm -rf $(OBJ_PATH)

fclean: clean
	@echo "Cleaning project . . ."
	@rm -f $(MLX)
	@rm -f $(LIBFT)
	@rm -f $(FT_PRINTF)
	@rm -f $(NAME)

re: clean all

.PHONY: all re clean
