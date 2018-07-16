# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bmkhize <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/05/19 14:56:05 by bmkhize           #+#    #+#              #
#    Updated: 2018/07/16 16:07:21 by bmkhize          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf

FLAGS = -Wall -Werror -Wextra

HEADER = fdf.h

FUNCTIONS = fdf.c utility.c

all: $(NAME)

$(NAME):
	@ cd libft && make all
	@ gcc $(FLAGS) $(FUNCTIONS) -L./libft -lft -o $(NAME)
	./fdf test.txt

a:
	@ gcc $(FLAGS) $(FUNCTIONS) -L./libft -lft -o $(NAME)
	./fdf test.txt

clean:
	@ cd libft && make fclean
	@ rm -f $(OBJECTS)

fclean: clean
	@ cd libft && make clean
	@ rm -f $(NAME)

re: fclean all
