# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mplutarc <mplutarc@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/06/10 14:05:39 by mplutarc          #+#    #+#              #
#    Updated: 2019/08/29 16:20:25 by mplutarc         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fractol
SRC = fractol.c mandel.c events.c mouse_events.c potoki.c colors.c julia.c \
			something.c korablik.c honeybadger.c buddha.c
OBJ = $(SRC:.c=.o)
LIBFT = libft/libft.a
FLAGS = -Wall -Wextra -Werror


all: lib fractol

lib:
	@make -C libft

fractol: $(OBJ)
	gcc $(FLAGS) $(OBJ) $(LIBFT) -o $(NAME) -framework Appkit -framework OpenGL -lmlx -lpthread

%.o: %.c
	gcc -c -I./libft $< -o $@

clean:
	/bin/rm -f $(OBJ)
	make -C libft clean

fclean: clean
	/bin/rm -f $(NAME)
	make -C libft fclean

re: fclean all
