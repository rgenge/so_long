# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: acosta-a <chaves_87@hotmail.com>           +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/28 02:03:37 by acosta-a          #+#    #+#              #
#    Updated: 2022/06/17 23:19:32 by acosta-a         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Executable #
NAME = so_long

# Compilation #
CC = gcc
FLAG = -Wall -Wextra -Werror
OPTCC=  -I. -c
RM = rm -f
MLXFLAGS	= -lmlx -Imlx -lXext -lX11
# includes #

#HEADER = /include#
LIBFT = ./libft/libft.a
LIBFT_PATH = ./libft
# SOURCE FILES #
SRC = ./src/create_map.c

SRC.O = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(SRC.O)
		make -C ${LIBFT_PATH}
		$(CC) $(FLAG) $(SRC) $(LIBFT) $(MLXFLAGS) -o $(NAME)
clean:
	$(RM) $(SRC.O)
	make clean -C ${LIBFT_PATH}
fclean: clean
	$(RM) $(NAME)
	make fclean -C ${LIBFT_PATH}

re: fclean all

.PHONY: all clean fclean re
