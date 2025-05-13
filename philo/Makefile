# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: maxgarci <maxgarci@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/02/05 10:31:34 by maxgarci          #+#    #+#              #
#    Updated: 2025/05/13 14:37:57 by maxgarci         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #
# Colors
MAGENTA = \033[35;1m
YELLOW  = \033[33;1m
GREEN   = \033[32;1m
WHITE   = \033[37;1m
RESET   = \033[0m
GRAY 	= \033[0;90m
BLUE    = \033[34;1m
CYAN    = \033[37;1m
BOLD	= \033[1m
RED		= \033[31;1m

NAME		:= philo

CC			:= cc
CFLAGS		:= -g -Wextra -Wall
INCLUDES	:= -I./include

MAIN		:= main.c
SRC_PATH	:= src/
SRC			:= print_error.c libft_utils.c init_philosophers.c \
				end_philosophers.c run_philo.c \
				philo_utils.c check_forks_freed.c go_to_think.c \
				go_to_sleep.c go_to_eat.c ask_for_forks.c
SRCS		:= $(addprefix $(SRC_PATH), $(SRC))

OBJ_PATH	:= obj/
OBJ			:= $(SRC:.c=.o)
OBJS		:= $(addprefix $(OBJ_PATH), $(OBJ))

all: $(NAME)

$(OBJ_PATH)%.o: $(SRC_PATH)%.c | $(OBJ_PATH)
	@echo "$(BLUE)COMPILING $(YELLOW) $< $(WHITE)to $(YELLOW)$@\n"
	@$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

$(OBJ_PATH):
	@mkdir -p $@

$(NAME): $(OBJS)
	@echo "$(WHITE)---------------------------------------------------------$(RESET)\n"
	@echo "$(BLUE)LINKING $(YELLOW)$(SRCS) $(WHITE)to $(GREEN)$(BOLD)$(NAME)\n"
	@$(CC) $(CFLAGS) $(INCLUDES) $(MAIN) $(OBJS) -o $(NAME)
	@echo "$(MAGENTA)$(ITALIC)Philosophers compiled!✅$(RESET)"

clean:
	@echo "$(YELLOW)Removing .o object files...$(RESET)\n"
	@rm -rf $(OBJ_PATH)

fclean: clean
	@echo "$(YELLOW)Removing fractol...$(RESET)\n"
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
