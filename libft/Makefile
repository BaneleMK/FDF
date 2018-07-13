# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bmkhize <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/05/19 14:56:05 by bmkhize           #+#    #+#              #
#    Updated: 2018/07/09 12:02:22 by bmkhize          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

NAMEL = exe

FUNCTIONS = 	ft_strcmp.c \
				ft_bzero.c \
				ft_strncmp.c \
				ft_strlen.c \
				ft_atoi.c \
				ft_itoa.c \
				ft_putchar.c \
				ft_putchar_fd.c \
				ft_putnbr.c \
				ft_putnbr_fd.c \
				ft_putstr.c \
				ft_putstr_fd.c \
				ft_putendl.c \
				ft_putendl_fd.c \
				ft_strncpy.c \
				ft_strcpy.c \
				ft_strcat.c \
				ft_strncat.c \
				ft_strlcat.c \
				ft_strstr.c \
				ft_strnstr.c \
				ft_strdup.c \
				ft_isalnum.c \
				ft_isalpha.c \
				ft_isascii.c \
				ft_isdigit.c \
				ft_isprint.c \
				ft_toupper.c \
				ft_tolower.c \
				ft_strchr.c \
				ft_strrchr.c \
				ft_strsub.c \
				ft_memset.c \
				ft_memcpy.c \
				ft_memchr.c \
				ft_memmove.c \
				ft_memccpy.c \
				ft_memalloc.c \
				ft_memcmp.c \
				ft_memdel.c \
				ft_strjoin.c \
				ft_strnew.c \
				ft_strclr.c \
				ft_strtrim.c \
				ft_strsplit.c \
				ft_strequ.c \
				ft_strnequ.c \
				ft_strdel.c \
				ft_striter.c \
				ft_striteri.c \
				ft_strmap.c \
				ft_strmapi.c \
				ft_lstnew.c \
				ft_lstadd.c \
				ft_lstiter.c \
				ft_lstdelone.c \
				ft_lstdel.c \
				ft_lstmap.c \
				ft_wordstarts.c \
				ft_wordlens.c \
				get_next_line.c \

OBJECTS = $(FUNCTIONS:.c=.o)

FLAGS = -Wall -Werror -Wextra

HEADER = libft.h

all: $(NAME)

$(NAME):
	gcc -c $(FLAGS) $(FUNCTIONS)
	ar rc $(NAME) $(OBJECTS)

q: re comp_main

comp_main:
	gcc main.c -L. -lft -o $(NAMEL)

comp_c_only:
	gcc main.c $(FUNCTIONS) -o $(NAMEL)

comp_obj:
	gcc -c $(FLAGS) $(FUNCTIONS)

clean:
	rm -f $(OBJECTS)

fclean: clean
	rm -f $(NAME)

re: fclean all
