# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: amessah <amessah@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/10 17:52:01 by amessah           #+#    #+#              #
#    Updated: 2022/03/21 17:17:34 by amessah          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long

CC = gcc

CFLAGS = -Wall -Wextra -Werror

INCLUDE = so_long.h

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
		
OBJECTS = $(src:.c=.o)

all: $(NAME)

$(NAME): $(OBJECTS) $(INCLUDES)
	$(CC) $(CFLAGS) $(OBJECTS) -lmlx -framework OpenGL -framework AppKit -o $(NAME)
	
%.o : %.c
	$(CC) $(CFLAGS) -o $@ -c $<

clean:
	rm -rf $(OBJECTS)

fclean: clean
	rm -rf $(NAME)

re: fclean all