# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: amessah <amessah@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/10 17:52:01 by amessah           #+#    #+#              #
#    Updated: 2022/03/30 01:48:59 by amessah          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long

BNS_NAME = so_long_bonus

CC = gcc

CFLAGS = -Wall -Wextra -Werror

INCLUDE = so_long.h

BNS_INCLUDE = ./so_long_bonuss/so_long_bonus.h

src =	so_long.c	\
		ft_utils.c 	\
		ft_libft_utils.c \
		ft_libft_utils2.c \
		ft_reading.c	\
		ft_validate.c	\
		game.c 		\
		mouve.c  	\
		position.c 	\
		ft_check.c 	\
		
BNS_src = 	./so_long_bonuss/so_long_bonus.c	\
			./so_long_bonuss/ft_utils.c 	\
			./so_long_bonuss/ft_libft_utils.c \
			./so_long_bonuss/ft_libft_utils2.c \
			./so_long_bonuss/ft_reading.c	\
			./so_long_bonuss/ft_validate.c	\
			./so_long_bonuss/game.c 		\
			./so_long_bonuss/mouve.c  	\
			./so_long_bonuss/position.c 	\
			./so_long_bonuss/ft_check.c 	\
			./so_long_bonuss/ft_check2.c	\
			./so_long_bonuss/ft_enemy_mouve.c	\
			./so_long_bonuss/ft_animation.c		\
				
OBJECTS = $(src:.c=.o)

BNS_OBJECT = $(BNS_src:.c=.o)

all: $(NAME)

$(NAME): $(OBJECTS) $(INCLUDES)
	$(CC) $(CFLAGS) $(OBJECTS) -lmlx -framework OpenGL -framework AppKit -o $(NAME)

bonus: $(BNS_NAME) 

$(BNS_NAME): $(BNS_OBJECT) $(BNS_INCLUDE)
	$(CC) $(CFLAGS) $(BNS_OBJECT) -lmlx -framework OpenGL -framework AppKit -o $(BNS_NAME)

%.o : %.c
	$(CC) $(CFLAGS) -o $@ -c $<

clean:
	rm -rf $(OBJECTS) $(BNS_OBJECT)

fclean: clean
	rm -rf $(NAME) $(BNS_NAME)

re: fclean all bonus