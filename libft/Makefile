# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mplutarc <mplutarc@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/04/09 17:15:07 by kdune             #+#    #+#              #
#    Updated: 2019/07/20 14:41:50 by mplutarc         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

SRCS_C = ft_isdigit.c ft_lstnew.c ft_memset.c ft_putstr_fd.c ft_strequ.c \
ft_strncat.c ft_strsplit.c ft_isprint.c ft_memalloc.c ft_putchar.c \
ft_strcat.c ft_striter.c ft_strncmp.c ft_strstr.c ft_itoa.c ft_memccpy.c \
ft_putchar_fd.c ft_strchr.c ft_striteri.c ft_strncpy.c ft_strsub.c ft_atoi.c \
ft_lstadd.c ft_memchr.c ft_putendl.c ft_strclr.c ft_strjoin.c ft_strndup.c \
ft_strtrim.c ft_bzero.c ft_lstdel.c ft_memcmp.c ft_putendl_fd.c ft_strcmp.c \
ft_strlcat.c ft_strnequ.c ft_tolower.c ft_isalnum.c ft_lstdelone.c ft_memcpy.c \
ft_putnbr.c ft_strcpy.c ft_strlen.c ft_strnew.c ft_toupper.c ft_isalpha.c \
ft_lstiter.c ft_memdel.c ft_putnbr_fd.c ft_strdel.c ft_strmap.c ft_strnstr.c \
ft_isascii.c ft_lstmap.c ft_memmove.c ft_putstr.c ft_strdup.c ft_strmapi.c \
ft_strrchr.c ft_free.c ft_lstfree.c ft_isspace.c ft_strnchr.c ft_count_words.c \
get_next_line.c ft_atol.c

SRCS_O = $(SRCS_C:.c=.o)

all: $(NAME)

$(NAME): $(SRCS_O)
	@ar rc libft.a $(SRCS_O)

$(SRCS_O): %.o: %.c
	gcc -c $< -o $@

clean:
	@rm -rf $(SRCS_O)

fclean: clean
	@rm -rf libft.a

re: fclean all
