# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mdos-san <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/01/06 17:24:47 by mdos-san          #+#    #+#              #
#    Updated: 2016/03/07 04:38:04 by mdos-san         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= fractol

COMPILER	= gcc
FLAGS		= -Wall -Werror -Wextra -I./includes
LIBS		= -L./libs -lft -lmlx -lcolor

OS			= $(shell uname)

MLX_DIR		= minilibx_macos

ifeq ($(OS), Linux)
MLX_DIR		= minilibx_linux
endif

TMP_C		=\
			img_clear.c\
			img_putpixel.c\
			img_move.c\
			draw_mandelbrot.c\
			draw_julia.c\
			draw_ship.c\
			main.c
SRC_C		= $(TMP_C:%=src/%)

TMP_O		= $(TMP_C:.c=.o)
SRC_O		= $(TMP_O:%=objects/%)

all			: $(NAME)

$(NAME)		: libs/libcolor.a libs/libft.a libs/libmlx.a objects $(SRC_O)
ifeq ($(OS), Linux)
	$(COMPILER) $(SRC_O) $(FLAGS) $(LIBS) -lX11 -lXext -o $(NAME)
else
	$(COMPILER) $(SRC_O) $(FLAGS) $(LIBS) -framework OpenGL -framework AppKit -o $(NAME)
endif

libs/libft.a	:
	make -C libs/libft
	mv libs/libft/libft.a libs
	make -C libs/libft/ fclean

libs/libmlx.a	:
	make -C libs/$(MLX_DIR)
	mv libs/$(MLX_DIR)/libmlx.a libs
	make -C libs/$(MLX_DIR) clean

libs/libcolor.a	:
	@echo "Making libcolor ..."
	@make -C libs/libcolor
	@cp libs/libcolor/libcolor.a libs
	@make -C libs/libcolor fclean
	@echo "Done !"

objects		:
	@mkdir objects

objects/%.o	: srcs/%.c
	$(COMPILER) $(FLAGS) -c $<
	@mv $(notdir $@) objects

clean		:
	rm -rf objects

fclean		: clean
	rm -rf $(NAME)
	rm -rf libs/libft.a
	rm -rf libs/libmlx.a
	rm -rf libs/libcolor.a
	rm -rf libs/minilibx_linux/libmlx_Linux.a

re			: fclean all
