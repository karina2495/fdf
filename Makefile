# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vfearles <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/12/04 16:44:29 by vfearles          #+#    #+#              #
#    Updated: 2019/12/04 16:44:32 by vfearles         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf

PATH_SRC = ./

PATH_OBJ = ./

PATH_INC = ./libft/

CFLAGS = -Wall -Wextra -Werror

HEAD = fdf.h utils.h

SRC =	main.c \
		map.c \
		mouse.c \
		stack.c \
		key_press.c \
		key_hook.c \
		convert.c \
		compound.c \
		utils.c \
		valid.c \
		fdf_describe.c \
		color.c \
		projection.c \
		struct.c

OBJ = $(patsubst %.c,%.o,$(addprefix $(PATH_SRC), $(SRC)))


all: $(NAME)

$(NAME): $(OBJ) $(HEAD)
	make -C libft/
	gcc $(CFLAGS) -I $(PATH_INC) -c $(SRC)
	gcc -o $(NAME) $(OBJ) -lm -L libft/ -lft -lmlx -framework OpenGL -framework AppKit

.PHONY: clean fclean

clean:
	make -C libft/ clean
	rm -rf $(OBJ)

fclean: clean
	make -C libft/ fclean
	rm -rf $(NAME)

re: fclean all
