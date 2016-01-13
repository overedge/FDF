	# **************************************************************************** #
	#                                                                              #
	#                                                         :::      ::::::::    #
	#    Makefile                                           :+:      :+:    :+:    #
	#                                                     +:+ +:+         +:+      #
	#    By: nahmed-m <marvin@42.fr>                    +#+  +:+       +#+         #
	#                                                 +#+#+#+#+#+   +#+            #
	#    Created: 2015/12/28 16:04:43 by nahmed-m          #+#    #+#              #
#    Updated: 2016/01/13 16:05:53 by nahmed-m         ###   ########.fr        #
	#                                                                              #
	# **************************************************************************** #
	#

SRC_NAME = core.c window.c file.c utils.c draw.c keyboard.c overlay.c

OBJ_NAME = $(SRC_NAME:.c=.o)

NAME = fdf

$(NAME) :
		make -C libft/ fclean && make -C libft/
		@make -C minilibx_macos/ clean && make -C minilibx_macos
		@cp minilibx_macos/mlx.h libft/includes
		gcc -Werror -Wextra -Wall $(SRC_NAME) -c -I./libft/includes
	gcc -o $(NAME) $(OBJ_NAME) -L./minilibx_macos -lmlx -framework OpenGL -framework AppKit -L./libft/ -lft

all : $(NAME)

clean :
	rm -rf $(OBJ_NAME)

fclean : clean
	rm -rf $(NAME)

re : fclean all

.PHONY : re fclean clean all
