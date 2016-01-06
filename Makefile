# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mdos-san <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/01/06 17:24:47 by mdos-san          #+#    #+#              #
#    Updated: 2016/01/06 18:53:35 by mdos-san         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= fractol

COMPILER	= gcc
FLAGS		= -Wall -Werror -Wextra

TMP_C		=\
			main.c
SRC_C		= $(TMP_C:%=src/%)

TMP_O		= $(TMP_C:.c=.o)
SRC_O		= $(TMP_O:%=objects/%)

all			: $(NAME)

$(NAME)		: libs/libft.a libs/libmlx.a objects $(SRC_O)
	$(COMPILER) $(FLAGS) $(SRC_O) -o $(NAME)

libs/libft.a	:
	make -C libs/libft
	mv libs/libft/libft.a libs
	make -C libs/libft/ fclean

libs/libmlx.a	:
	make -C libs/minilibx_macos
	mv libs/minilibx_macos/libmlx.a libs
	make -C libs/minilibx_macos clean

objects		:
	mkdir objects

objects/%.o	: srcs/%.c
	$(COMPILER) $(FLAGS) -c $<
	@mv $(notdir $@) objects

clean		:
	rm -rf objects

fclean		: clean
	rm -rf $(NAME)
	rm -rf libs/libft.a
	rm -rf libs/libmlx.a

re			: fclean all
