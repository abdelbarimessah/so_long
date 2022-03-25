# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: amessah <amessah@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/10 17:52:01 by amessah           #+#    #+#              #
#    Updated: 2022/03/24 16:41:19 by amessah          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long_bonus

CC = gcc

CFLAGS = -Wall -Wextra -Werror

INCLUDE = so_long_bonus.h

src =	so_long_bonus.c	\
		ft_utils.c 	\
		ft_libft_utils.c \
		ft_libft_utils2.c \
		ft_reading.c	\
		ft_validate.c	\
		game.c 		\
		mouve.c  	\
		position.c 	\
		ft_check.c 	\
		ft_check2.c	\
		ft_enemy_mouve.c	\
		ft_animation.c		\
		
OBJECTS = $(src:.c=.o)

all: $(NAME)

bonus :$(OBJECTS) $(INCLUDES)
	$(CC) $(CFLAGS) $(OBJECTS) -lmlx -framework OpenGL -framework AppKit -o $(NAME)
	
%.o : %.c
	$(CC) $(CFLAGS) -o $@ -c $<

clean:
	rm -rf $(OBJECTS)

fclean: clean
	rm -rf $(NAME)

re: fclean all