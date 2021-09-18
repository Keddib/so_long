# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: keddib <keddib@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/10/24 23:20:45 by keddib            #+#    #+#              #
#    Updated: 2021/09/17 14:53:58 by keddib           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = Game

FOLD = utils

SRCS =			main.c \
				$(FOLD)/hundle_keys.c \
				$(FOLD)/map.c \
				$(FOLD)/utils.c \
				$(FOLD)/player.c \
				$(FOLD)/error.c \
				$(FOLD)/read_file.c \
				$(FOLD)/get_next_line.c \
				$(FOLD)/get_utils.c \
				$(FOLD)/dynamic_array.c

OBJS =			main.o \
				hundle_keys.o \
				map.o \
				utils.o \
				player.o \
				error.o \
				read_file.o \
				get_next_line.o \
				get_utils.o \
				dynamic_array.o

FLAGS =  -lmlx -framework OpenGL -framework AppKit -lm

GO = gcc -Wall -Wextra -Werror -g #-fsanitize=address

all : $(NAME)

$(NAME):
	@$(GO) -c $(SRCS)
	@$(GO) -o $(NAME) $(OBJS) $(FLAGS)

clean :
		@rm -f ${OBJS}

fclean : clean
		@rm -f $(NAME)

re : fclean
		@make all

.PHONY: all clean fclean re
