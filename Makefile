# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mdelforg <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/02/17 13:09:27 by mdelforg          #+#    #+#              #
#    Updated: 2022/02/23 13:20:17 by mdelforg         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long

SRCS = so_long.c \
	   map_init.c \
	   map_check.c \
	   map_check_elem.c \
	   background.c \
	   move.c \
	   error.c \
	   gnl/get_next_line.c gnl/get_next_line_utils.c \
	   libft/ft_strdup.c libft/ft_strlen.c libft/ft_memcpy.c libft/ft_calloc.c \
	   libft/ft_bzero.c libft/ft_memset.c libft/ft_strchr.c

OBJS = $(SRCS:.c=.o)

CC		= gcc
RM		= rm -f

CFLAGS = -Wall -Wextra -Werror -fsanitize=address -g

LINKS = -lmlx -framework OpenGL -framework AppKit

$(NAME): $(OBJS)
		$(CC) $(CFLAGS) $(OBJS) $(LINKS) -o $(NAME)

all:	$(NAME)

exe:	all clean

clean:
		$(RM) $(OBJS)

fclean:	clean
		$(RM) $(NAME)

re:		fclean all
