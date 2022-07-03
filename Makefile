# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: acosta-a <chaves_87@hotmail.com>           +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/28 02:03:37 by acosta-a          #+#    #+#              #
#    Updated: 2022/06/26 23:54:48 by acosta-a         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long

# Compilation #
CC = gcc
CFLAGS = -Wall -Wextra -Werror -g
OPTCC=  -I. -c
RM = rm -rf
MLX    = -lmlx -Imlx -lXext -lX11

#HEADER = /include#
LIBFT = ./libft/libft.a
LIBFT_PATH = ./libft
# SOURCE FILES #
SRC = ./src/create_map.c ./src/exit.c ./src/move.c  ./src/render.c \
./src/utils.c
BONUS = ./bonus/create_map.c ./bonus/exit.c ./bonus/move.c  \
 ./bonus/render.c ./bonus/utils.c ./bonus/animation.c

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $(<:%.c=%.o)

SRC.O = $(SRC:%.c=%.o)
BONUS.O = $(BONUS:%.c=%.o)

all: $(NAME)

$(NAME): $(SRC.O)
	$(RM) $(NAME)
	make -C ${LIBFT_PATH}
	$(CC) $(CFLAGS) $(SRC.O) $(LIBFT) $(MLX) -o $(NAME)

bonus: $(NAME)_bonus

$(NAME)_bonus :	$(BONUS.O)
	$(CC) $(CFLAGS) $(BONUS.O) $(LIBFT) $(MLX) -o $(NAME)_bonus

clean:
	$(RM) $(SRC.O)
	$(RM) $(BONUS.O)
	make clean -C ${LIBFT_PATH}
fclean: clean
	$(RM) $(NAME)
	$(RM) $(NAME)_bonus
	make fclean -C ${LIBFT_PATH}

re: fclean all

.PHONY: clean fclean bonus re 
