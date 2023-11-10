# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lribette <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/08 17:55:53 by lribette          #+#    #+#              #
#    Updated: 2023/11/10 16:27:22 by lribette         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = get_next_line.a

SOURCES = get_next_line.c get_next_line_utils.c

OBJECTS = $(SOURCES:.c=.o)

CC = cc
CFLAGS = -Wall -Wextra -Werror -g

all: $(NAME)

$(NAME): $(OBJECTS)
	ar rcs $@ $^

%.o:%.c
	$(CC) -g -c $(CFLAGS) $<

clean:
	$(RM) $(OBJECTS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
