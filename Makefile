# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bmkhize <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/05/19 14:56:05 by bmkhize           #+#    #+#              #
#    Updated: 2018/07/27 15:07:44 by bmkhize          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf

FLAGS = -Wall -Werror -Wextra

HEADER = fdf.h

FUNCTIONS = fdf.c utility.c

all: $(NAME)

$(NAME):
	@ cd libft && make all
	@ gcc $(FLAGS) $(FUNCTIONS) -L./libft -lft -o $(NAME) -lmlx -framework OpenGL -framework AppKit
	./fdf test.txt

a:
	@ gcc $(FLAGS) $(FUNCTIONS) -L./libft -lft -o $(NAME) -lmlx -framework OpenGL -framework AppKit
	./fdf ../fdf_demo/maps/42.fdf

og:
	./../fdf_demo/fdf ../fdf_demo/maps/42.fdf

norm:
	norminette -r CheckForbiddenSourceHeader $(FUNCTIONS)

clean:
	@ cd libft && make fclean
	@ rm -f $(OBJECTS)

fclean: clean
	@ cd libft && make clean
	@ rm -f $(NAME)

re: fclean all
