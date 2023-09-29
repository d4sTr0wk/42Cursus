# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: maxgarci <maxgarci@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/09/19 19:17:40 by maxgarci          #+#    #+#              #
#    Updated: 2023/09/29 21:02:08 by maxgarci         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Archivos fuente
SRCS = ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_isascii.c ft_isprint.c ft_strlen.c ft_memset.c ft_memmove.c ft_bzero.c ft_memcpy.c ft_toupper.c ft_tolower.c ft_atoi.c ft_strncmp.c ft_strchr.c ft_strrchr.c ft_calloc.c ft_strdup.c ft_substr.c ft_strjoin.c ft_strtrim.c
OBJS = $(SRCS:.c=.o)
CFLAGS = -Wall -Wextra -Werror

NAME = libft.a

.PHONY: clean fclean

all: $(NAME)

%.o: %.c
	gcc $(CFLAGS) -c $< -o $@

$(NAME): $(OBJS)
	ar -rcs $(NAME) $(OBJS)	

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all
