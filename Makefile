# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dtse <marvin@42.fr>                        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/10/18 16:05:19 by dtse              #+#    #+#              #
#    Updated: 2016/10/18 16:05:20 by dtse             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=		get_next_line
FILENAMES	=		get_next_line.c

CC			=		gcc
CFLAGS		+=		-Wall -Wextra -Werror
CFLAGS		+=		-I includes/

#SRCS		=		$(addprefix srcs/, $(FILENAMES))
OBJS		=		$(addprefix build/, $(FILENAMES:.c=.o))

LIBFT		=		./libft/libft.a
LIBINC		=		-I./libft
LIBLINK		=		-L./libft -lft

.PHONY:	all clean fclean re

all: libft $(NAME)

build:
	mkdir $@

build/%.o: %.c | build
	$(CC) $(CFLAGS) $(LIBINC) -o $@ -c $<

libft: $(LIBFT)

$(LIBFT):
	make -C ./libft

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(LIBLINK) -o $@ $^ #-fsanitize=address

clean: rm -rf build/

fclean: clean
	rm -f $(NAME)

re: fclean all

