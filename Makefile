# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nahmed-m <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/12/28 16:04:43 by nahmed-m          #+#    #+#              #
#    Updated: 2016/01/07 20:22:23 by nahmed-m         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC_NAME = core.c window.c file.c utils.c draw.c keyboard.c

OBJ_NAME = $(SRC_NAME:.c=.o)

NAME = fdf

$(NAME) :
	make -C libft/ fclean && make -C libft/
	gcc -Werror -Wextra -Wall $(SRC_NAME) -c
	gcc -o $(NAME) $(OBJ_NAME) -L/usr/local/lib/ -I/usr/local/include -lmlx -framework OpenGL -framework AppKit -L./libft/ -lft

all : $(NAME)

clean :
	rm -rf $(OBJ_NAME)

fclean : clean
	rm -rf $(NAME)

re : fclean all

.PHONY : re fclean clean all
