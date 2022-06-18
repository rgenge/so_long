# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: acosta-a <chaves_87@hotmail.com>           +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/28 02:03:37 by acosta-a          #+#    #+#              #
#    Updated: 2022/06/18 03:06:07 by acosta-a         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long

# Compilation #
CC = gcc
CFLAGS = -Wall -Wextra -Werror
OPTCC=  -I. -c
RM = rm -f
MLX    = -lmlx -Imlx -lXext -lX11
# includes #

#HEADER = /include#
LIBFT = ./libft/libft.a
LIBFT_PATH = ./libft
# SOURCE FILES #
SRC = ./src/create_map.c

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $(<:%.c=%.o)

OBJ = $(SRC:%.c=%.o)

all: $(NAME)

$(NAME): $(OBJ)
	rm -rf $(NAME)
	make -C ${LIBFT_PATH}
	$(CC) $(CFLAGS) $(OBJ) $(LIBFT) $(MLX) -o $(NAME)


clean:
	$(RM) $(SRC.O)
	make clean -C ${LIBFT_PATH}
fclean: clean
	$(RM) $(NAME)
	make fclean -C ${LIBFT_PATH}

re: fclean all

.PHONY: all clean fclean re
