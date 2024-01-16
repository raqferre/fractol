# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: raqferre <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/13 13:38:19 by raqferre          #+#    #+#              #
#    Updated: 2023/02/16 16:58:27 by raqferre         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fractol

CFLAGS = -Wall -Werror -Wextra

SRCS = mandelbrot.c julia.c  main.c utils.c  \
		error.c hooks.c

OBJS = $(SRCS:.c=.o)

all : $(NAME)

$(NAME) : $(SRCS)
		cc $(CFLAGS) -Lmlx -lmlx -Imlx -framework OpenGL -framework AppKit $(SRCS) -o $(NAME)

clean :
		@rm -rf $(OBJS)

fclean : clean
		@rm -rf $(NAME)

re :	fclean all
	
