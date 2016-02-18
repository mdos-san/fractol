# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mdos-san <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/12/18 17:35:31 by mdos-san          #+#    #+#              #
#    Updated: 2016/01/23 12:10:27 by mdos-san         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME=		libcolor.a

COMPILER=	gcc
FLAGS=		-Werror -Wextra -Wall
INCLUDES=	-I./includes

SRC_C=\
			color_new.c\
			color_del.c\
			color_get.c\
			color_convert.c\
			color_average.c\
			color_step.c

SRC_O=$(SRC_C:.c=.o)

all: objects $(SRC_O:%=objects/%) $(NAME)

objects:
	@mkdir objects

objects/%.o: srcs/%.c
	@echo "Compling $< ..."
	@$(COMPILER) $(FLAGS) $(INCLUDES) -c $<
	@mv $(notdir $@) objects

$(NAME): $(SRC_C:%=srcs/%)
	@ar -rc $(NAME) $(SRC_O:%=objects/%)
	@echo "Libcolor has been created!"

clean:
	rm -rf objects

fclean: clean
	rm -rf libcolor.a

re: fclean all
