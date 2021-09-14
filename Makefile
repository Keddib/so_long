# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: keddib <keddib@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/10/24 23:20:45 by keddib            #+#    #+#              #
#    Updated: 2021/09/14 13:47:16 by keddib           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = Game

SRCS = main.c hundle_keys.c map.c utils.c

OBJS = main.o hundle_keys.o map.o utils.o

FLAGS =  -lmlx -framework OpenGL -framework AppKit -lm

GO = gcc -Wall -Wextra -Werror  -fsanitize=address

all : $(NAME)

$(NAME) : $(OBJS)
	@$(GO) -c $(SRCS)
	@$(GO) -o$(NAME) $(OBJS) $(FLAGS)

clean :
		rm -f ${OBJS}

fclean : clean
		rm -f $(NAME)

re : fclean
		make all

.PHONY: all clean fclean re
